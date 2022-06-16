#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "struct.h"
#include "main.h"


int main(){
    printf("inserisci numero di giocatori: ");

    giocatore *testa=NULL, *coda=NULL;
    casella tab[63];


    int numeri[63]={1,2,3,4,5,6,7,8,9,28,29,30,31,32,33,34,35,10,27,48,49,50,51,52,53,36,11,26,47,60,61,62,63,54,37,12,25,46,59,58,57,56,55,38,13,24,45,44,43,42,41,40,39,14,23,22,21,20,19,18,17,16,15};

    for(int i=0; i<63; i++){
        (tab+i)->num=numeri[i];
    }

    genera_partita(tab);
    gioca_partita(testa, coda, tab);
    return 0;
}
