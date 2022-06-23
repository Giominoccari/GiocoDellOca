#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "gioca.h"

void crea_coda(struct coda* seq, int num, struct giocatore* nuovo){
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
            //printf("seleziona colore identificativo tra giallo, blu, viola, rosso, verde");
            //do{
                //fflush(stdin);
                //c=getchar();
            //}while(c!='g' && c!='b' && c!='v' && c!='r' && c!='v');
            //switch(c){
                //colori

            //}
        }else{
            printf("no spazio per tutti");
        }
    }
}

int domanda(struct casella *tab, int posg, int post){
    char risp[MAX_CHAR];
    printf("rispondi a questa domanda per avanzare di %d caselle :%s  =%s\n", (tab+post)->val, (tab+post)->dom, (tab+post)->risp);
    fflush(stdin);
    scanf("%s", risp);
    if(strcmp(risp, (tab+post)->risp)==0){
        printf("bravo!");
        posg+=(tab+post)->val;
        return posg;
    }else{
        printf("nope");
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
                printf("pos=%d", posg);
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
                printf("type postab=%d  postab=%d", (tab+postab)->type, postab);
            }while((tab+postab)->type==0 || (tab+postab)->type==1 || (tab+postab)->type==2);
        }else{
            seq->t->salto=false;
        }
        printf("bomba2");
        temp=seq->t;
        seq->t=seq->t->next;
        temp->next=NULL;
        seq->c->next=temp;
        seq->c=temp;
        temp=NULL;
        free(temp);
    }while(true);
}