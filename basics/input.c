#include "stdint.h"
#include "stdio.h"

int32_t main(int32_t argc, char* argv[]) {

  char s1[20];

  // Faisons un lecture de ce que est tape sur le clavier:
  
  printf("Votre nom ? ");
  scanf("%s",s1);
  printf("Bonjour %s\n",s1);

  int32_t age;
  printf("Votre age ? ");

  scanf("%d",&age);
  printf(" vous avez %d ans\n",age);

  return 0;
}
