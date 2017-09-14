#include "stdint.h"
#include "stdio.h"

// Voici des variables dites "globales",
// elles sont visibles de partout.
int8_t v1;
int8_t* v1_addr = &v1;

/*
 * Voici une fonction, avec un seul argument: v2
 */
void foo(int8_t v2) {
  int8_t* v2_addr = &v2;

  // Sous gdb, set a breakpoint in foo.
  // Avec l'execution suspendue sur la ligne suivante,
  // utilisez la commander suivante:
  //  (gdb) where
  // Vous voyez la pile des appels
  //   la fonction main
  //   la fonction foo
  // Utiliser les commandes
  //  (gdb) up
  //  (gdb) down
  // Tout en imprimant la valeur de v2 et de v2_addr
  // -> vous voyez, il y a deux variables v2,
  //  - une pour la fonction main
  //  - une pour la fonction foo
  v2 = v2 + 10;

  *v2_addr = v2 + 10;

  // lorsque la fonction foo va faire return, 
  // les variable v2 et v2_addr vont disparaitre,
  // mais seulement celle de la fonction foo.
  // pas celle de la fonction main.
  return;
}

/*
 * Ici, nous avons une fonction qui retourne une valeur,
 * un entier encodé sur 32bits.
 */
int32_t bar(int32_t v2) {
  int32_t* v2_addr = &v2;

  v2 = v2 + 20;

  // descendre dans l'appel de foo, avec "step"
  // jouer avec up et down, et regarder les valeurs de la variable v2,
  // au différent niveau de la pile d'exécution.
  foo(v2);

  // Regarder la valeur de v2... l'appel de foo ne l'a pas modifie.
  
  return v2;
}

int32_t main(int32_t argc, char* argv[]) {
  
  // mettez un breakpoint sur main avant de faire run sous gdb
  // Utiliser la commande next pour executer la ligne courante.

  int v2;
  int* v2_addr = &v2;
  
  v1 = 12;
  v2 = 0;

  // ATTENTION: ici, utilisez la commande step
  // pour continuer de suivre l'execution dans la fonction foo.
  // (gdb) step
  foo(v1);

  v1 = 32;

  // ATTENTION: ici, utilisez la commande step
  // pour continuer de suivre l'execution dans la fonction foo.
  // (gdb) step
  v2 = bar(v1);

  return 0;
}
