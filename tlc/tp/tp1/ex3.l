%{
    int nbVoyelles, nbConsonnes, nbPonctuation;
%}

%%
[aeiouy] nbVoyelles++;
[bcdfghjklmnpqrstvwxz] nbConsonnes++;
[\.\?\!\,;:()\[\]\"-] nbPonctuation++;
%%
int main() {
    yylex();
    printf("nombre voyelles : %d\n nombre consonnes : %d\n nombre ponctuations : %d\n", nbVoyelles, nbConsonnes, nbPonctuation);
}
int yywrap() {
    return 1;
}