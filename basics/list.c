#include <stddef.h>
#include "stdint.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0


/*
 * The structure that defines the entry to hold
 * one element of a list.
 */
struct list_entry {
  struct list_entry *next;
  void *elem;
};

/*
 * The structure to represent a list.
 * The list is a single-linked list.
 */
struct list {
  struct list_entry * head;
  unsigned int size;
};

void list_insert(struct list* list, int idx, void* element);

/*
 * To create a new list. 
 * The list is memory allocated, so it will need to be 
 * disposed of.
 */
struct list* new_list() {
  struct list* list = malloc(sizeof(struct list));
  memset(list, 0, sizeof(struct list));
  return list;
}

/*
 * To dispose of a list. 
 * Making to free the entire list, including 
 * the entries if the list is not empty.
 *
 * Nota Bene: the entries are freed only if asked
 *            to do so (free_elements)
 */
void dispose_list(struct list* list, int8_t free_elements) {
  struct list_entry *pos;
  pos = list->head;
  while (pos) {
    struct list_entry *next = pos->next;
    if (free_elements)
      free(pos->elem);
    free(pos);
    pos = next;
  }
  free(list);
}

/*
 * Returns the size of the list, that is,
 * the number of elements in the list.
 */
int list_size(struct list* list) {
  return list->size;
}

/* 
 * Appends an element to the list, that is,
 * adds the element at the end of the list.
 */
void list_append(struct list* list, void* element) {
  if (list->size == 0) {
    struct list_entry *niu;
    niu = malloc(sizeof(struct list_entry));
    memset(niu, 0, sizeof(struct list_entry));
    niu->elem = element;
    list->head = niu;
    list->size = 1;
  } else {
    struct list_entry *pos;
    pos = list->head;
    while (pos->next)
      pos = pos->next;
    //for (int i = 0; i < list->size - 1; i++) {
    //  pos = pos->next;
    //}
    struct list_entry *niu;
    niu = malloc(sizeof(struct list_entry));
    memset(niu, 0, sizeof(struct list_entry));
    niu->elem = element;
    niu->next = pos->next;
    pos->next = niu;
    list->size++;
  }
}

/* 
 * Prepends an element to the list, that is,
 * adds the element at the front of the list.
 */
void list_prepend(struct list* list, void* element) {
  if (list->size == 0) {
    struct list_entry *niu;
    niu = malloc(sizeof(struct list_entry));
    memset(niu, 0, sizeof(struct list_entry));
    niu->elem = element;
    list->head = niu;
    list->size = 1;
  } else
    list_insert(list, 0, element);
}

/* 
 * Finds the element at the given position in the list.
 * Returns NULL if the index is not a valid index in
 * the list.
 */
void* list_element_at(struct list* list, int idx) {
  struct list_entry *pos;
  if (idx<0 || idx>=list->size)
    return (void*)0;
  
  pos = list->head;
  for (int i = 0; pos && i < idx; i++)
    pos = pos->next;
  return pos->elem;
}

/*
 * Inserts an element before at the given index.
 * The index starts at zero
 * WARNING: 
 *    exits the process if the index is invalid.
 */
void list_insert(struct list* list, int idx, void* element) {
  struct list_entry *prev = NULL;
  struct list_entry *pos;
  if (idx<0 || idx>=list->size) {
    printf("PANIC: insert at invalid index %d\n",idx);
    exit(-1);
  }
  pos = list->head;
  for (int i = 0; i < idx; i++) {
    prev = pos;
    pos = pos->next;
  }
  struct list_entry *niu;
  niu = malloc(sizeof(struct list_entry));
  memset(niu, 0, sizeof(struct list_entry));
  niu->elem = element;
  if (prev) {
    niu->next = prev->next;
    prev->next = niu;
  } else {
    niu->next = list->head;
    list->head = niu;
  }
  list->size++;
}

/*
 * Remove the element at the given index.
 * WARNING: 
 *    exits the process if the index is invalid.
 */
void* list_remove(struct list* list, int idx) {
  struct list_entry *prev = NULL;
  struct list_entry *pos;
  if (idx<0 || idx>=list->size) {
    printf("PANIC: remove at invalid index %d\n",idx);
    exit(-1);
  }
  pos = list->head;
  for (int i = 0; i < idx; i++) {
    prev = pos;
    pos = pos->next;
  }
  if (prev)
    prev->next = pos->next;
  else
    list->head = pos->next;
  
  list->size--;
  void* elem = pos->elem;
  free(pos);
  return elem;
}

/*
 * Prints a list of strings
 */
void print_string_list(char* prefix, struct list* list) {
  int size = list_size(list);
  if (size == 0) {
    printf("%s: empty list.\n", prefix);
    return;
  }
  printf("%s\n", prefix);
  for (int i = 0; i < list_size(list); i++) {
    char* s = (char*) list_element_at(list, i);
    printf(" list[%d]=%s \n", i, s);
  }
}

char buffer[128];

int32_t read_line() {
  int pos = 0;
  char c = getchar();
  while (c!='\n') {
    buffer[pos++] = c;
    c = getchar();
  }
  buffer[pos] = 0;
  return pos;
}

/*
 * This is just a small test program 
 * for our list implementation.
 */
int main(int argc, char** argv) {

  struct list* list;
  list = new_list();

  list_append(list, "zero");
  list_append(list, "un");
  list_append(list, "trois");
  list_insert(list, 2, "deux");


  print_string_list("Initial:", list);

  list_remove(list, 3);
  print_string_list("Removed list[3]", list);
  list_remove(list, 1);
  print_string_list("Removed list[1]", list);
  list_remove(list, 0);
  print_string_list("Removed list[0]", list);

  list_remove(list, 0);
  print_string_list("Removed list[0]", list);

  dispose_list(list, FALSE);
  
  printf("Enter strings to insert in the list.\n");
  printf(" (enter an empty string to stop)\n");
  
  list = new_list();

  int n = read_line();
  while (n!=0) {
    char * s = malloc(n+1);
    strcpy(s,buffer);
    printf(" + %s\n",s);
    list_append(list,s);
    n = read_line();
  }
  print_string_list("list: ", list);

  dispose_list(list, TRUE);

  printf("Bye now.\n");
  return 0;
}
