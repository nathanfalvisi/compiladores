%{
    #include <stdio.h>
    int nline;
%}
%%
ola {printf("\ola");}
. {printf("\n Erro: entrada = %s", yytext);}
%%
int main(){
    yylex();
    printf("\nFim de programa de %d linha", nline);
}
