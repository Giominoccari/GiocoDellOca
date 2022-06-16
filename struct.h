
#define MAX_CHAR 50

typedef struct giocatore{
    char colore;
    int num;
    int pos;
};

typedef struct casella{
    int num;
    char type[10];
    int val;
    bool salto;
    char dom[MAX_CHAR];
    char risp[MAX_CHAR];
};

