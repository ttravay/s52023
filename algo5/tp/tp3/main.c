#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int TAILLE_MAX_MOT = 25;

struct ListeChainee
{
    char mot[TAILLE_MAX_MOT];
    int nbOccurences;
    struct ListeChainee *next;
};

int isLowerCase(char lettre)
{
    if (lettre >= 'a' && lettre <= 'z')
    {
        return 1;
    }
    return 0;
}

int isUpperCase(char lettre)
{
    if (lettre >= 'A' && lettre <= 'Z')
    {
        return 1;
    }
    return 0;
}

int isLetter(char lettre)
{
    if (isUpperCase(lettre) || isLowerCase(lettre))
    {
        return 1;
    }
    return 0;
}

int toLowerCase(char lettre)
{
    lettre += 'a' - 'A';
    return lettre;
}

FILE *openFile(char *nom)
{
    FILE *fp;
    fp = fopen(nom, "r");
    if (fp == NULL)
    {
        printf("erreur fopen \n");
    }
    return fp;
}

char *readWord(FILE *fp)
{
    char *str = malloc(sizeof(char) * TAILLE_MAX_MOT);
    int len = 0;
    char c;
    do
    {
        c = getc(fp);
    } while (!isLetter(c) && c != EOF);
    while (c != ' ' && c != EOF)
    {
        str[len++] = c;
        c = getc(fp);
    }
    return str;
}

void readAllWords(FILE *fp)
{
    char *chaine = malloc(sizeof(char) * TAILLE_MAX_MOT);
    chaine = readWord(fp);
    while (strlen(chaine) > 0)
    {
        printf("%s\n", chaine);
        chaine = readWord(fp);
    }
}

int main(int argc, char **argv)
{
    FILE *fp = openFile("test");
    char *str = malloc(sizeof(char) * TAILLE_MAX_MOT);
    test();
    return 0;
}