#include "stdint.h"
#include "stdio.h"

/*
 * Voici un déclaration d'une fonction.
 * Voir la définition plus bas.
 */
int32_t bar(int32_t bar_arg);

/*
 * Voici une fonction "foo", 
 * avec un seul argument foo_arg.
 */
int32_t foo(int32_t foo_arg) {
  int32_t lvar;
  lvar = 2*foo_arg;
  lvar = bar(lvar);
  return lvar;
}

/*
 * Voici une autre fonction "bar", 
 * avec un seul argument "bar_arg". 
 */
int32_t bar(int32_t bar_arg) {
  int32_t lvar;
  lvar = bar_arg + 5;
  return lvar;
}

/*
 * Voici le point d'entree de l'execution.
 * Toute execution commence toujours par ici.
 *
 * mettez un breakpoint sur main avant de faire run sous gdb
 * Utiliser la commande next pour executer la ligne courante.
 */
int32_t main(int32_t argc, char* argv[]) {

  int16_t v1 = 12;
  int16_t v2 = 21;
  int32_t* pt = (int32_t*)&v1;
  *pt = 0;
  
  // *(int32_t*)0x456721 = 12;
  // *(int32_t*)0x985563 = *(int32_t*)0x456721; 
  
  int32_t value=0;

  // follow the execution with the step command
  // (gdb) step
  value = foo(5);
    
  return 0;
}
