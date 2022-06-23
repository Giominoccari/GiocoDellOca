#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "struct.h"
#endif

void crea_coda(struct coda* seq, int num, struct giocatore* nuovo);
int domanda(struct casella *tab, int posg, int post);
int scivolo(struct casella *tab, int posg, int post);
void gioca_partita(struct coda *seq, struct casella *tab, int num);