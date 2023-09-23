%{
    int nbMots, nbNombres;
%}

%%
[a-zA-Z]+ nbMots++;
[0-9]+(,[0-9]+)* nbNombres++;
%%
int main() {
    yylex();
    printf("nombre mots : %d\n nombres : %d\n", nbMots, nbNombres);
}
int yywrap() {
    return 1;
}