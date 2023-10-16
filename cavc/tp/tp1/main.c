#include <stdio.h>
#include <stdlib.h>

const int width = 512;
const int height = 512;

void imageAleatoire() {  
    FILE *fp = NULL; 
    fp = fopen("couleurAleatoire", "w");
    if (fp == NULL) {
        printf("erreur ouverture fichier");
    }

}

int main(int argc, char **argv) {
    imageAleatoire();
    return 0;
}