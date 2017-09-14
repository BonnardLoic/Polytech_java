#include "stdint.h"
#include "stdio.h"

/*
 * Une fonction qui calcule la somme des elements 
 * du tableau de valeur passé en parametre.
 */
int32_t compute_sum(int8_t* values, int32_t nvalues) {

  int32_t i;
  int32_t sum = 0;
  int8_t* pointer;
  i = 0;
  while (i<nvalues) {
    pointer = values + i;
    sum = sum + *pointer;
    i = i + 1;
  }
  return sum;
}

/*
 * Une fonction qui calcule les sommes pour les n premieres valeurs,
 * variant n de 0 a nvalues.
 */
void compute_all_sums(int8_t* values, int32_t nvalues) {
  int32_t i;
  int32_t sum = 0;
  for (i=0;i<=nvalues;i++) {
    sum = compute_sum(values,i);
    printf(" Sum[0,%d[ = %d \n", i, sum);
  }
  return;
}


int32_t main(int32_t argc, char* argv[]) {

  int8_t values[10];

  // mettez un breakpoint sur main avant de faire run sous gdb
  // Utiliser la commande next pour executer la ligne courante.

  int32_t i;
  int32_t sum = 0;

  // nous initializons le tableau avec des valeurs
  for (i=0;i<10;i++)
    values[i] = i;

  sum = compute_sum(values,10);

  printf(" sum[0,10[=%d \n", sum);

  compute_all_sums(values,10);
    
  return 0;
}
