#include "analex.h"
#include "pilha.h"
#define MAX 1000

int token;

void E();
void E_linha();
void T();
void T_linha();
void F();


void erro_sint(){
    printf("ERRO SINTATICO na Linha %d!!", linha_atual);
    exit(1);
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

int main(){
    token = analex();
    E();

    if(token == ';')
        printf("NAO TEM ERROS SINTATICOS!!");
    else
        erro_sint();
    printf("\n\nResultado = %d", pop());
    return 0;
}