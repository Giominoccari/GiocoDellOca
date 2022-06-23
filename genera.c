#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "genera.h"
 

void inserisci_scala(int j, struct casella *tab, FILE *fpd, FILE *fpr){
    static int i=0;
    (tab+j)->type=0;
    fgets((tab+j)->dom, 100, fpd);
    fgets((tab+j)->risp, 50, fpr);
    printf("%s\n", (tab+j)->risp);
    (tab+j)->val=rand()%10+5;
    i++;
    if(i==4){
        rewind(fpd);
        rewind(fpr);
        i=0;
    }
}

void inserisci_scivolo(int j, struct casella *tab){
    (tab+j)->val=rand()%10+5;
    (tab+j)->type=1;
}

void salta_turno(int j, struct casella *tab){
    (tab+j)->type=2;
}

void genera_partita(struct casella *tab, int *num){
    srand(time(NULL));
    char topo[10];
    int a;
    int k=0;
    int d;
    char y=true;
    FILE *fpd=NULL;
    FILE *fpr=NULL;

    char *filenamed="domande.txt";
    char *filenamer="risposte.txt";

    if ((fpd = fopen(filenamed, "r+")) != NULL){
        if((fpr = fopen(filenamer, "r+")) != NULL) {
    // costruisco tabella
            for(int j=0; j<63; j++){
                    //d=;
                    //a=;
                    //printf("d=%d\n", d);
                    //printf("%d===%d\n", (tab+j)->num, *(num+i));
                    if (rand()%3==0){
                        if(y==true){
                            y=false;
                            switch (rand()%3){
                                case 0:
                                    //printf("scala  %d\n", j);
                                    inserisci_scala(j, tab, fpd, fpr);
                                    (tab+j)->giocatore=0;
                                    k++;
                                        break;
                                case 1:
                                    //printf("scivolo %d\n", j);
                                    inserisci_scivolo(j, tab);
                                    (tab+j)->giocatore=0;
                                    k++;
                                        break;
                                case 2:
                                    //printf("salto %d\n", j);
                                    salta_turno(j, tab);
                                    (tab+j)->giocatore=0;
                                    k++;
                                        break;
                            }
                        }else{
                            y=true;
                            (tab+j)->type=3;
                            (tab+j)->giocatore=0;
                        }
                    }else{
                        (tab+j)->type=3;
                        (tab+j)->giocatore=0;
                    }
            }
        }
    }
    fclose(fpd);
    fclose(fpr);
    printf("k= %d\n", k);
    for(int i=1; i<=63; i++){
        switch((tab+i-1)->type){
            case 0: strcpy(topo, "scala");
                break;
            case 1: strcpy(topo, "scivolo");
                break;
            case 2: strcpy(topo, "salto");
                break;
            case 3: strcpy(topo, "   ");
            }
        printf("|%2d  %7s|", (tab+i-1)->num, topo );
        if(i%9==0){
            printf("\n");
        }
    }

}