#include "stdint.h"
#include "stdio.h"

/*
 * Voici une fonction qui implémente la fonction factoriel:
 * 
 * factoriel(n) = n * n-1 * ... * 1
 */
int32_t factorial(int32_t n) {
  if (n==1)
    return 1;
  return n * factorial(n-1);
}

int32_t main(int32_t argc, char* argv[]) {
  
  // mettez un breakpoint sur main avant de faire run sous gdb
  // Utiliser la commande next pour executer la ligne courante.

  int32_t v1 = 5;
  int32_t v2 = factorial(v1);
  printf(" factorial(%d)=%d \n",v1,v2);
  
  return 0;
}
