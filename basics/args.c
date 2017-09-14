#include "stdint.h"
#include "stdio.h"

int32_t main(int32_t argc, char* argv[]) {

  char s1[20];
  int i;

  // heureusement, la fonction printf sait aussi imprimer
  // une chaine de caracteres...
  // Imprimons les arguments du programme
  printf(" argc=%d \n",argc);
  for (i=0; i<argc; i++) {
    printf(" argv[%d]=%s\n",i,argv[i]);
  }
  return 0;
}
