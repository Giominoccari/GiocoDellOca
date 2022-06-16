
#define MAX_CHAR 50

struct giocatore{
    char colore;
    int num;
    int pos;
};

struct casella{
    int num;
    char type[10];
    int val;
    bool salto;
    char dom[MAX_CHAR];
    char risp[MAX_CHAR];
};

