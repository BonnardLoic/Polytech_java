#include "stdint.h"
#include "stdio.h"

/*
 * Une fonction qui imprime sur le terminal une chaine de caractere.
 * En C, une chaine de caractere est un tableau de caractere, termine
 * par un octet qui vaut zero.
 */
void prints(char* s) {

  int32_t i=0;
  char c;
  c = *s;
  while (c != 0) {
    printf("%c",c);
    i++;
    c = *(s+i);
  }
  return;
}

/*
 * Une fonction qui copie une string, dans une autre.
 */ 
void copys(char* dst, char* src) {

  int32_t i=0;
  char c;
  c = *src;
  while (c != 0) {
    dst[i]=c;
    i++;
    c = *(src+i);
  }
  // ne pas oublier de copier le zero qui 
  // marque la fin de toute chaine de caractère
  dst[i]=0;
  return;
}

int32_t main(int32_t argc, char* argv[]) {

  char s1[20];
  char *s2;
  int i;

  s1[0] = 'H';
  s1[1] = 'e';
  s1[2] = 'l';
  s1[3] = 'l';
  s1[4] = 'o';
  s1[5] = 0;

  
  printf("La chaine s1 est ");
  prints(s1);
  printf("\n");

  // Le C comprends les chaines de caracteres...
  // Ici, le pointeur s2 prends l'adresse de la chaine
  // donc l'adresse de la premiere valeur du tableau en mémoire
  // qui contient la chaine "Hello World!\n".
  s2 = "Hello World!\n";
  prints(s2);

  // Nous allons copier les caracteres de la chaine pointee par s2
  // dans le tableau de caracteres pointe par s1.
  copys(s1,s2);

  printf("La copie dans s1 est ");
  prints(s1);

  copys(s1,"Super!\n");
  prints(s1);

  printf("\n");
  
  // heureusement, la fonction printf sait aussi imprimer
  // une chaine de caracteres... Ouf! Pas besoin de notre
  // fonction.
  printf(" s1=%s \n",s1);
  
  return 0;
}
