#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "gioca.h"

void crea_coda(struct coda* seq, int num, struct giocatore* nuovo){
    char c;
    for(int i=0; i<num; i++){
        if((nuovo = (struct giocatore*)malloc(sizeof(struct giocatore)))!=NULL){
            if(i==0){
            seq->t=nuovo;
            seq->c=nuovo;
            nuovo=NULL;
            }
            if(i!=0){
                seq->c->next=nuovo;
                seq->c=nuovo;
                nuovo=NULL;
            }
            free(nuovo);
            seq->c->pos=0;
            seq->c->salto=false;
            printf("inserisci un numero identificativo di massimo 2 cifre:");
            scanf("%d", &(seq->c->num));
            printf("seleziona colore identificativo tra giallo, blu, magenta, rosso, verde");
            do{
                fflush(stdin);
                c=getchar();
            }while(c!='g' && c!='b' && c!='v' && c!='r' && c!='v');
            switch(c){
                case 'g':

            }
        }else{
            printf("no spazio per tutti");
        }
    }
}

int domanda(struct casella *tab, int posg, int post){
    char risp[MAX_CHAR];
    char risps[MAX_CHAR];
    char rispi[MAX_CHAR];
    printf("rispondi a questa domanda per avanzare di %d caselle :%s\n", (tab+post)->val, (tab+post)->dom);
    strncpy(risps, (tab+post)->risp, strlen((tab+post)->risp)-1);
    fflush(stdin);
    scanf("%s", risp);
    if(strcmp(risp, risps)==0){
        printf("bravo!\n");
        posg+=(tab+post)->val;
        return posg;
    }else{
        printf("nope\n");
        return posg;
    }
}

int scivolo(struct casella *tab, int posg, int post){
    printf("arretra di %d caselle\n", (tab+post)->val);
    if((posg-(tab+post)->val)>0){
        posg-=(tab+post)->val;
        return posg;
    }else{
        return 1;
    }
}

void gioca_partita(struct coda *seq, struct casella *tab, int num){
    char topo[10];
    int postab;
    int posg;
    int dado;      
    struct giocatore* nuovo=NULL;;
    char c;
    char y;
    struct giocatore *temp=NULL;

    //creo la coda
    crea_coda(seq, num, nuovo);
    srand(time(NULL));
    do{
        if(seq->t->salto!=true){
            printf("giocatore %d tira i dadi, premi y per tirare\n", seq->t->num);
            do{
                y=getchar();
            }while(y!='y');
            for(int b=0; b<63; b++){
                if((tab+b)->num==seq->t->pos){
                    postab=b;
                    break;
                }
            }
            (tab+postab)->giocatore=0;
            dado=rand()%6+1;
            printf("hai fatto %d\n", dado);
            seq->t->pos=(seq->t->pos)+dado;
            posg=seq->t->pos;
            printf("pos=%d\n", posg);
            if(posg==63){
                break;
            }
            do{
                int vec=posg;
                for(int b=0; b<63; b++){
                    if((tab+b)->num==posg){
                        postab=b;
                        break;
                    }
                }
                printf("sei finito su una casella tipo %d\n", (tab+postab)->type);
                if(((tab+postab)->type)==0){
                    posg=domanda(tab, posg, postab);
                }
                if(((tab+postab)->type)==1){
                    posg=scivolo(tab, posg, postab);
                }
                if(((tab+postab)->type)==2){
                    seq->t->salto=true;
                }
                if(posg>63){
                    posg=posg-(posg-63);
                }
                printf("pos=%d\n", posg);
                if(vec==posg){
                    break;
                }
                for(int b=0; b<63; b++){
                    if((tab+b)->num==posg){
                        postab=b;
                        break;
                    }
                }
                seq->t->pos=posg;
            }while((tab+postab)->type==0 || (tab+postab)->type==1 || (tab+postab)->type==2);
        }else{
            printf("salta il turno\n");
            seq->t->salto=false;
        }
        (tab+postab)->giocatore=seq->t->num;
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
            printf("|%2d  %2d  %7s|", (tab+i-1)->num, (tab+i-1)->giocatore , topo);
            if(i%9==0){
                printf("\n");
            }
        }
        if(num>1){
        temp=seq->t;
        seq->t=seq->t->next;
        temp->next=NULL;
        seq->c->next=temp;
        seq->c=temp;
        temp=NULL;
        free(temp);
        }
    }while(true);
}