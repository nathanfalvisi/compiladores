#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM 256

int tokenval;

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

    if (!isspace(ch)){
        printf("Erro Lexico: Caracter Inserido Invalido! '%c'", ch);
        exit(1);
    }

    return analex();
}
