#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "genera.h"
#include "gioca.h"

int main(){
    int numgioc;
    do{
    printf("inserisci numero di giocatori(MAX 5): ");
    scanf("%d", &numgioc);
    }while(numgioc>5);
    printf("\n");

    struct coda *seq;
    seq=(struct coda*)malloc(sizeof(struct coda));
    seq->t=NULL;
    seq->c=NULL;

    struct casella *tab;

    int numeri[63]={1,2,3,4,5,6,7,8,9,28,29,30,31,32,33,34,35,10,27,48,49,50,51,52,53,36,11,26,47,60,61,62,63,54,37,12,25,46,59,58,57,56,55,38,13,24,45,44,43,42,41,40,39,14,23,22,21,20,19,18,17,16,15};
    if((tab =(struct casella*)malloc(63*sizeof(struct casella)))!=NULL){
        for(int i=0; i<63; i++){
            (tab+i)->num=numeri[i];
        }
    }else{
        printf("tabella troppo grande");
    }
    genera_partita(tab, numeri);
    gioca_partita(seq, tab, numgioc);
    return 0;
}
