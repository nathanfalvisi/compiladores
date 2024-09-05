%{
    #include <stdio.h>
    int nline;
%}
%%
ola {printf("\ola");}
\n {++nline;}
. {printf("\n Erro na linha %d Entrada = %s", nline, yytext);}
%%
int main(){
    yylex();
    printf("\nFim de programa de %d linha", nline);
}
