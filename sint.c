#include "analex.h"
#include "pilha.h"
#include <string.h>
#define MAX 1000

int token;
char posfixa[MAX];
char aux;
int x = 0;

void consome(int t);
void E();
void E_linha();
void T();
void T_linha();
void F();
void erro_sint();

int main(){
    token = analex();
    E();

    if(token == ';'){
        printf("EXPRESSAO CORRETA\n");
        printf("NOTACAO POSFIXA: %s\n", posfixa);
        printf("RESULTADO DA EXPRESSAO: %d\n", pop());
    } else
        erro_sint();
} 

void consome(int t){
    if (token == t)
        token = analex();
    else
        erro_sint();
}

void E(){
    T();
    E_linha();
}

void E_linha(){
    switch(token){
        case '+':
            consome('+');
            T();
            b = pop();
            a = pop();
            push(a + b);
            aux = '+';
            strcpy(&posfixa[x], &aux);
            E_linha();
            break;
        case '-':
            consome('-');
            T();
            b = pop();
            a = pop();
            push(a - b);
            E_linha();
            break;
    }
}

void T(){
    F();
    T_linha();
}

void T_linha(){
    switch(token){
        case '*':
            consome('*');
            F();
            b = pop();
            a = pop();
            push(a * b);
            T_linha();
            break;
        case '/':
            consome('/');
            F();
            b = pop();
            a = pop();
            push(a / b);
            T_linha();
            break;
    }
}

void F(){
    switch(token){
        case '(':
            consome('(');
            E();
            consome(')');
            break;
        case NUM:
            consome(NUM);
            push(tokenval);
            break;
        default:
            erro_sint();
    }
}

void erro_sint(){
    printf("ERRO SINTATICO NA LINHA: %d", linha_atual);
    exit(1);
}