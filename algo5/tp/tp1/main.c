#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

const int TAILLE = 10;
const int NBMAXLISTE = 100;

struct Stat {
    int comparaisons;
    int permutations;
    int total;
};

void swap(int *var1, int *var2)
{
    int tmp = *var1;
    *var1 = *var2;
    *var2 = tmp;
}

int *genererListe(int taille, int max)
{
    srand(time(NULL));
    int *nombres = malloc(sizeof(int) * taille);
    for (int i = 0; i < taille; i++)
    {
        nombres[i] = rand() % max;
    }
    return nombres;
}

void printListe(int *liste, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("liste[%d] = %d\n", i, liste[i]);
    }
}

int isSorted(int *liste, int taille)
{
    for (int i = 1; i < taille; i++)
    {
        if (liste[i] < liste[i - 1])
            return 0;
    }
    return 1;
}

void selection(int *liste, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        int mini = liste[i];
        int indMini = i;
        for (int j = i + 1; j < taille; j++)
        {
            if (liste[j] < mini)
            {
                mini = liste[j];
                indMini = j;
            }
        }
        swap(&liste[indMini], &liste[i]);
    }
}

void insertion(int *liste, int taille)
{
    for (int i = 1; i < taille; i++)
    {
        int end = 0;
        for (int j = i; j > 0 && !end; j--)
        {
            if (liste[j] < liste[j - 1])
            {
                swap(&liste[j], &liste[j - 1]);
            }
            else
            {
                end = 1;
            }
        }
    }
}

void bulles(int *liste, int taille)
{
    int end = 0;
    while (!end)
    {
        end = 1;
        for (int i = 0; i < taille - 1; i++)
        {
            if (liste[i] > liste[i + 1])
            {
                swap(&liste[i], &liste[i + 1]);
                end = 0;
            }
        }
    }
}

void fusion(int *liste, int indPremier, int indDernier)
{
    int indMilieu = (indDernier + indPremier) / 2;
    int tailleT1 = (indMilieu - indPremier + 1);
    int tailleT2 = (indDernier - indMilieu);

    int t1[tailleT1], t2[tailleT2];

    for (int i = 0; i < tailleT1; i++)
    {
        t1[i] = liste[indPremier + i]; // rajout indPremier
    }
    for (int i = 0; i < tailleT2; i++)
    {
        t2[i] = liste[i + indMilieu + 1];
    }

    int ind1 = 0, ind2 = 0, k = indPremier;
    while (ind1 < tailleT1 && ind2 < tailleT2)
    {
        if (t1[ind1] < t2[ind2])
        {
            liste[k] = t1[ind1];
            ind1++;
        }
        else
        {
            liste[k] = t2[ind2];
            ind2++;
        }
        k++;
    }
    while (ind1 < tailleT1)
    {
        liste[k] = t1[ind1];
        ind1++;
        k++;
    }
    while (ind2 < tailleT2)
    {
        liste[k] = t2[ind2];
        ind2++;
        k++;
    }
}

void triFusion(int *liste, int indPremier, int indDernier)
{
    if (indPremier < indDernier)
    {
        int indMilieu = (indPremier + indDernier) / 2;
        triFusion(liste, indPremier, indMilieu);
        triFusion(liste, indMilieu + 1, indDernier);

        fusion(liste, indPremier, indDernier);
    }
}

int partition(int *liste, int indPremier, int indDernier)
{
    int pivot = liste[indDernier];
    int k = indPremier;

    for (int i = indPremier; i < indDernier; i++)
    {
        if (pivot >= liste[i])
        {
            swap(&liste[i], &liste[k]);
            k++;
        }
    }
    swap(&liste[indDernier], &liste[k]);
    return k;
}

void triRapide(int *liste, int indPremier, int indDernier)

{
    if (indPremier < indDernier)
    {
        int indMilieu = partition(liste, indPremier, indDernier);
        triRapide(liste, indPremier, indMilieu - 1);
        triRapide(liste, indMilieu + 1, indDernier);
    }
}

void plateforme(int taille_mini, int nb_listes, int nb_expes)
{
    for (int i = taille_mini; i < taille_mini * nb_listes; i += taille_mini)
    {
        for (int j = 0; j < nb_expes; j++)
        {
            int *savedListe = genererListe(i, NBMAXLISTE);
            int *liste = malloc(sizeof(int) * i);
            memcpy(liste, savedListe, i * sizeof(int));
            selection(liste, i);
            assert(isSorted(liste, i));
            memcpy(liste, savedListe, i * sizeof(int));
            insertion(liste, i);
            assert(isSorted(liste, i));
            memcpy(liste, savedListe, i * sizeof(int));
            bulles(liste, i);
            assert(isSorted(liste, i));
            memcpy(liste, savedListe, i * sizeof(int));
            triFusion(liste, 0, i - 1);
            assert(isSorted(liste, i));
            memcpy(liste, savedListe, i * sizeof(int));
            triRapide(liste, 0, i - 1);
            assert(isSorted(liste, i));
            free(savedListe);
            free(liste);
        }
    }
}

int main(int argc, char **argv)
{
    int *liste = genererListe(TAILLE, NBMAXLISTE);
    printListe(liste, TAILLE);
    /*selection(liste, TAILLE / 2);
    selection(&liste[5], TAILLE / 2);
    printListe(liste, TAILLE);
    printf("%s", isSorted(liste, TAILLE) ? "La liste est triee\n" : "La liste n'est pas triee\n");
    swap(&liste[0], &liste[3]);
    printListe(liste, TAILLE);
    selection(liste, TAILLE);
    printListe(liste, TAILLE);
    printf("%s", isSorted(liste, TAILLE) ? "La liste est triee\n" : "La liste n'est pas triee\n");
    insertion(liste, TAILLE);
    printListe(liste, TAILLE);
    printf("%s", isSorted(liste, TAILLE) ? "La liste est triee\n" : "La liste n'est pas triee\n");
    bulles(liste, TAILLE);
    printListe(liste, TAILLE);
    printf("%s", isSorted(liste, TAILLE) ? "La liste est triee\n" : "La liste n'est pas triee\n");
    free(liste);
    triFusion(liste, 0, TAILLE - 1);
    printListe(liste, TAILLE);*/
    plateforme(100, 10, 100);

    return 0;
}
