#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "genera.h"
 

void inserisci_scala(int j, struct casella *tab){
    srand(time(NULL));
    char *filenamed="";
    char *filenamer="";
    FILE *fpd;
    FILE *fpr;
    // (tab+j)->type="scala";
    if ((fpd = fopen(filenamed, "r+")) != NULL){
        if((fpr = fopen(filenamer, "r+")) != NULL) {
            fgets((tab+j)->dom, 50, fpd);
            fgets((tab+j)->risp, 50, fpr);
            (tab+j)->val=rand()%10+5;
        }
    }
}

void inserisci_scivolo(int j, struct casella *tab){
    // (tab+j)->type="scivolo";
    srand(time(NULL));
    (tab+j)->val=rand()%10+5;
}
void salta_turno(int j, struct casella *tab){
    (tab+j)->salto=true;
}

void genera_partita(struct casella *tab){
    int a;
    for(int i=0; i<63; i++){
        for(int j=0; j<63; j++) {
            if((tab+j)->num==i){
                srand(time(NULL));
                if (rand() % 4 == 0) {
                    srand(time(NULL));
                    a = rand() % 3;
                    switch (a) {
                        case 0:
                            inserisci_scala(j, tab);

                        case 1:
                            inserisci_scivolo(j, tab);

                        case 2:
                            salta_turno(j, tab);
                    }
                }
                break;
            }
        }
    }
    for(int i=0; i<63; i++){
        printf("_______\n|     %d|\n|%7s|", (tab+i)->num, (tab+i));
        if(i%9==0){
            printf("/n");
        }
    }
}
