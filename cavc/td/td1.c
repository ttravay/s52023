#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int NB_BATONNETS = 10;

void printBatons(int nb)
{
    printf("|");
    nb--;
    while (nb > 0)
    {
        printf(" |");
        nb--;
    }
    printf("\n");
}

void batonnets()
{
    srand(time(NULL));
    int joueur = 1 + (rand() & 1), batonnets = NB_BATONNETS, choix;
    while (batonnets > 0)
    {
        printBatons(batonnets);
        printf("Joueur %d, choisir entre 1 et 3 battonets : ", joueur);
        scanf("%d", &choix);
        batonnets -= choix;
        // joueur = 1 + (joueur + 1) & 1;
        if (joueur == 2)
            joueur = 1;
        else
            joueur = 2;
    }
    printf("Le joueur %d a gagné\n", joueur);
}

void swap(int *a, int *b)
{
    *a = *b + *a; // a = a ^ b
    *b = *a - *b; // b = b ^ a
    *a = *a - *b; // a = a ^b
}

int puissance(int nb)
{
    unsigned int cpt = 0;
    while (nb)
    {
        cpt += (nb & 1);
        nb >>= 1;
    }
    if (cpt == 1)
        printf("puissance de 2\n");
    else
        printf("pas puissance de 2\n");
}

int puissance2(int nb)
{
    if (!(nb & (nb - 1)))
        printf("puissance de 2\n");
    else
        printf("pas puissance de 2");
}

int binaire(int nb) // >> 1 << 1 >> 2 && ma version
{
    if (nb == 0)
        printf("0b");
    else
    {
        ;
        binaire(nb >> 1);
        printf("%d", nb & 1);
    }
}

int inverser(int nb)
{
    nb = ((nb & 0xFFFF0000) >> 16) | ((nb & 0x0000FFFF) << 16);
    nb = ((nb & 0xFF00FF00) >> 8) | ((nb & 0x00FF00FF) << 8);
    nb = ((nb & 0xF0F0F0F0) >> 4) | ((nb & 0x0F0F0F0F) << 4);
    nb = ((nb & 0xCCCCCCCC) >> 2) | ((nb & 0x33333333) << 2);
    nb = ((nb & 0xAAAAAAAA) >> 1) | ((nb & 0x55555555) << 1);
    return nb;
}

int main(int argc, char *argv[])
{
    // puissance(16);
    /*int a = 2, b = 4;
    printf("a : %d, b : %d\n", a, b);
    swap(&a, &b);
    printf("a : %d, b : %d\n", a, b);*/
}