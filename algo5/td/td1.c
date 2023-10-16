#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define k 37
#define MAX_CH 255

typedef Liste Table[k];
typedef char mot[MAX_CH];

typedef struct cel
{
    mot m;
    struct cel *suivant;
} cellules;

void initHashTable(Table t)
{
    int i;
    for (i = 0; i < k; i++)
    {
        t[i] = NULL;
    }
}

void insererMotTable(mot m, Table t)
{
    int e = h(m);
    insererMotListe(m, &t[e]);
}

int calcValHachage(char *mot)
{
    int som = 0;
    for (int i = 0; i < strlen(mot); i++)
    {
        som += mot[i];
    }
    return som;
}

int h(mot m)
{
    return valeur(m) % k;
}

int main(int argc, char **argv)
{
    printf("calcValHachage : %d\n", calcValHachage("bonjour"));
    return EXIT_SUCCESS;
}