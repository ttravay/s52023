%{
    int ajoutTailleNombres;
    int *nombres;
    int tailleActu;
    int indNombres;
    /* 5 * (12 + (5 + 5)) 5 12 5 5 + + * , il faut utiliser une pile aussi (pile.h)*/
%}

NOMBRES [1-9][0-9]*
OPERATEURS \*|\+|-

%%
{NOMBRES} {nombres[indNombres] = (int) yytext; printf("%d\n", nombres[0]);indNombres++;}
{OPERATEURS} {
switch(*yytext) {
    case '*':
    nombres[indNombres-2] = nombres[indNombres-1] * nombres[indNombres-2];
    indNombres--;
    break;
    case '+':
    nombres[indNombres-2] = nombres[indNombres-1] + nombres[indNombres-2];
    break;
    case '-':
    nombres[indNombres-2] = nombres[indNombres-1] - nombres[indNombres-2];
    break;
}
}
. ;

%%
int main() {
    ajoutTailleNombres = 20;
    nombres = malloc(sizeof(int) * ajoutTailleNombres);
    tailleActu = ajoutTailleNombres;
    indNombres = 0;
    yylex();
    //printf("%d\n", nombres[0]);
}
int yywrap() {
    return 1;
}