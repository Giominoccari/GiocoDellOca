
#define MAX_CHAR 100

#define ROSSO    "\x1b[31m"
#define VERDE   "\x1b[32m"
#define GIALLO  "\x1b[33m"
#define BLU    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define RESET   "\x1b[0m"

struct giocatore{
    char pos_coda;
    char colore;
    int num;
    int pos;
    bool salto;
    struct giocatore *next;
};

struct casella{
    char col_gioc;
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

