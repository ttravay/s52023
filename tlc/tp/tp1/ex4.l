%{
%}
IDENTIFICATEURS [a-zA-Z]([a-zA-Z]|[0-9])*

%%
begin|end printf("motCle %s", yytext);
[0-9]+ printf("nombres %s", yytext);
{IDENTIFICATEURS} printf("identificateurs %s", yytext);
[-+\*]|"**" printf("op %s", yytext);
.&[^\n\t] printf("erreur %s");
%%
int main() {
    yylex();
}
int yywrap() {
    return 1;
}