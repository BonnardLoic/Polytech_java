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
  return bar(2*foo_arg);
}

/*
 * Voici une autre fonction "bar", 
 * avec un seul argument "bar_arg". 
 */
int32_t bar(int32_t bar_arg) {
  return bar_arg + 5;
}

/*
 * Voici le point d'entree de l'execution.
 * Toute execution commence toujours par ici.
 *
 * mettez un breakpoint sur main avant de faire run sous gdb
 * Utiliser la commande next pour executer la ligne courante.
 */
int32_t main(int32_t argc, char* argv[]) {
  
  int32_t value=0;

  // follow the execution with the step command
  // (gdb) step
  value = foo(5);
    
  return 0;
}
