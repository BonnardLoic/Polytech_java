#include "stdint.h"
#include "stdio.h"
#include <stdlib.h>

void ordonnerTableau(int tableau[], int tailleTableau)
{
    int i = 0;

    for (i = 0; i < tailleTableau; i++)
    {
        int j = 1;

        for (j = 1; j < (tailleTableau - i); j++)
        {
            if (tableau[i] > tableau[i + j])
            {
                int stocka = tableau[i], stockb = tableau[i + j];
                tableau[i] = stockb;
                tableau[i + j] = stocka;
            }
        }
    }
}

void inputArray(int tableau[], int taille_tableau){
    int i;
    for (i = 0; i < taille_tableau; i++)
    {
        printf("Valeur pour la case %d ? ", i + 1);
        scanf("%d", &tableau[i]);
    }
}

int32_t main(int32_t argc, char *argv[])
{
    int *tableau = NULL;
    int taille_tableau = 0, i = 0;
    int *tab_trie;

    printf("Taille de ton tableau\n");
    scanf("%d", &taille_tableau);

    if (taille_tableau > 0)
    {
        tableau = malloc(taille_tableau * sizeof(int));
        if (tableau == NULL)
        {
            exit(0);
        }

        inputArray(tableau, taille_tableau);

        ordonnerTableau(tableau, taille_tableau);

        for (i = 0; i < taille_tableau; i++)
        {
            printf("%d\n", tableau[i]);
        }

        free(tableau);
    }

    return 0;
}