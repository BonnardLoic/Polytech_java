#include "stdint.h"
#include "stdio.h"
#include <stdlib.h>
#include <time.h>
#include "string.h"

#define TAILLE_MAX 30

void RL()
{
    printf("\n");
}

void mot_random(char chaine[])
{
    srandom(time(NULL));
    int i = 0;
    int random_word = rand() % 839;

    FILE *dico = fopen("dico.txt", "r");

    if (dico != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, dico) != NULL && i != random_word)
        {
            i++;
        }
    }
    fclose(dico);
}

void motUser(char *char_user)
{
    char bin;
    printf("Entre une lettre : ");
    scanf("%c%c", char_user, bin);
}

void afficheMot(char chaine[], int bool_mot[])
{
    int taille_mot = (strlen(chaine) - 2);

    for (int i = 0; i < taille_mot; i++)
    {
        if (chaine[i] == bool_mot[i])
        {
            printf("%c", chaine[i]);
        }
        else
        {
            printf("_");
        }
    }
    RL();
}

void testMot(char chaine[], char *char_user, int *bool_mot)
{
    int taille_mot = (strlen(chaine) - 2);
    for (int i = 0; i < taille_mot; i++)
    {
        if (*char_user == chaine[i])
        {
            bool_mot[i] = 1;
        }
        else
        {
            if (*char_user == chaine[i])
            {
                bool_mot[i] = 1;
            }
            else
            {
                bool_mot[i] = 0;
            }
        }
    }

    // for (int j = 0; j < taille_mot; j++)
    // {
    //     printf("%d", bool_mot[j]);
    // }
    RL();
}

int32_t main(int32_t argc, char *argv[])
{

    char chaine[TAILLE_MAX];
    char char_user;
    mot_random(chaine);
    int nb_essai = (strlen(chaine) - 2) * 2;
    int bool_mot[strlen(chaine - 2)];
    printf("%s et nb essai %d\n", chaine, nb_essai);
    while (nb_essai != 0)
    {
        motUser(&char_user);
        testMot(chaine, &char_user, bool_mot);
        afficheMot(chaine, char_user);
        nb_essai -= 1;
    }

    return 0;
}