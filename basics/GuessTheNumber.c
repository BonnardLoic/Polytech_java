#include "stdint.h"
#include "stdio.h"
#include <stdlib.h>
#include <time.h>



int32_t main(int32_t argc, char* argv[]){
    //Appel du générateur random
    srandom(time(NULL));

    //Choix d'un nombre entre 0 et 20
    int64_t val = rand()%21;
    int nb = 0;
    int i = 1;

    printf("Choisi un nombre entre 0 et 20 : \n");
    scanf("%d", &nb);

    while(val != nb){
        if(nb>val){
            printf("Trop grand !\n");
        }
        else{
            printf("Trop petit !\n");
        }
        scanf("%d", &nb);
        i += 1;
    }

    printf("Bravo vous avez choisi %d et en effet c'était %ld ! \nEn %d coup(s)l ! \n",nb, val, i);
    return 0;
}