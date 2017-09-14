#include "stdint.h"
#include "stdio.h"

// Voici une definition de tableau de valeurs entieres.
// La definition reserve la place en memoire pour 10 octets
// et definie une variable qui nomme cette zone memoire.
int8_t values[10];


int32_t main(int32_t argc, char* argv[]) {
  
  // mettez un breakpoint sur main avant de faire run sous gdb
  // Utiliser la commande next pour executer la ligne courante.

  int32_t i;
  int32_t sum = 0;

  // definissons une variable "pointeur" qui pointera sur
  // une valeur du tableau.
  int8_t *pointer;
  
  // nous initializons le tableau avec des valeurs
  //   values[i] = i
  // mais nous utilisons la notation avec le calcul d'adresse
  for (i=0;i<10;i++) {
    pointer = values+i;
    *pointer = i;
  }
  // un peu d'impression pour voir les valeurs et les adresses...
  
  printf(" la variable locale values contient l'adresse %p \n",
	 values);
  printf(" le tableau se trouve donc en memoire entre [%p, %p[ \n",
	 values,values+10);
  
  for (i=0;i<10;i++)
    printf(" values[%d]=%d  stored at address %p \n",
	   i, *(values+i), values+i);

  // maintenant, calculons la somme des elements du tableau de valeur.
  i = 0;
  while (i<10) {
    pointer = values + i;
    sum = sum + *pointer;
    i++;
  }

  printf(" sum=%d \n", sum);
  
  return 0;
}
