#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM 256

int tokenval;
int linha_atual = 1;

int analex(){
    char ch;
    ch = getchar();

    if(ch == '+')
        return '+';

    if(ch == '-')
        return '-';

    if(ch == '*')
        return '*';

    if(ch == '/')
        return '/';

    if(ch == ';')
        return ';';

    if(ch == '(')
        return '(';

    if(ch == ')')
        return ')';

    if(isdigit(ch)){
        tokenval = 0;

    while (isdigit(ch)){
        tokenval = tokenval * 10 + (ch - '0');
        ch = getchar();
    }
    ungetc(ch, stdin);
    return NUM;
    }

    if(!isspace(ch)){
<<<<<<< HEAD
        printf("ERRO LEXICO NA LINHA: %d",linha_atual);
=======
        printf("Erro Lexico na Linha: %d Caracter Inserido Invalido! '%c'",linha_atual, ch);
>>>>>>> b0e84cf9a9e00161a98f32e052494dd8470d9a02
        exit(1);
    }
    if(ch == '\n'){
        linha_atual++;
    }

    return analex();
}
