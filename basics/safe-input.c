#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

void panic(char* msg) {
  printf("\n");
  if (msg)
    printf("PANIC: %s\n",msg);
  else
    printf("PANIC\n");
  exit(-1);
}
  
int32_t main(int32_t argc, char* argv[]) {

  int32_t res;
  char s1[20];

  // Faisons un lecture de ce que est tape sur le clavier:
  
  printf("Votre nom ? ");
  res = scanf("%s",s1);
  if (res!=1)
    panic("Mauvaise saisie.");
  printf("Bonjour %s\n",s1);
      
  int32_t age;
  printf("Votre age ? ");
  res = scanf("%d",&age);
  if (res!=1)
    panic("Mauvaise saisie.");
  printf(" vous avez %d ans\n",age);
  return 0;
}
