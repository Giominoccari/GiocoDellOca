
#define MAX_CHAR 100

struct giocatore{
    char colore;
    int num;
    int pos;
    bool salto;
    struct giocatore *next;
};

struct casella{
    int giocatore;
    int num;
    int type;
    int val;
    char dom[MAX_CHAR];
    char risp[MAX_CHAR];
};

struct coda{
    struct giocatore *t;
    struct giocatore *c;
};

typedef struct coda coda;