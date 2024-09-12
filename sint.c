#include "analex.h"
#include "pilha.h"
#include <string.h>
#define MAX 1000

int token;
char npx[MAX];
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
        printf("NOTACAO POSFIXA: %s\n", npx);
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
            aux = '+'; // Armazena o operador em aux
            strcpy(&npx[x], &aux); // Copia o conteudo de aux para a posicao atual de npx[x]
            x++; // Acrescenta o tamanho da string
            npx[x] = ' '; // Adiciona um espaco logo apos o operador ser armazenado na string
            x++; // Acrescenta novamente o tamanho da string apos o espaco ser adicionado
            E_linha();
            break;
        case '-':
            consome('-');
            T();
            b = pop();
            a = pop();
            push(a - b);
            aux = '-'; 
            strcpy(&npx[x], &aux);
            x++;
            npx[x] = ' ';
            x++;
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
            aux = '*';
            strcpy(&npx[x], &aux);
            x++;
            npx[x] = ' ';
            x++;

            T_linha();
            break;
        case '/':
            consome('/');
            F();
            b = pop();
            a = pop();
            push(a / b);
            aux = '/';
            strcpy(&npx[x], &aux);
            x++;
            npx[x] = ' ';
            x++;
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

            int newchar = tokenval; // Recebe o Valor do Token a ser transformado
            int tam = 0; // Numero de Digitos

            while (newchar != 0){
                newchar = newchar / 10; // Calcula o numero de digitos do token, calculando quantas divisoes com 10 sao possiveis
                tam++; // Aumenta o tamanho a cada iteracao
            }

            if (tam == 0) { // Trata o caso onde o 'tokenval' eh 0.
                tam = 1; // 0 tem apenas um digito, logo ajustado para 1.
                npx[x] = '0'; // Char 0 é adicionado na string da notacao pos fixa.
                x++; // Acrscenta o tamanho da string.
            }

            newchar = tokenval; // Restaura o valor para ser utilizado na etapa abaixo

            for (int i = (tam - 1) + x; i >= x; i--){ // Etapa onde o valor de newchar eh transformado em char e armazenado na string.
                npx[i] = (newchar % 10) + '0'; // Pega o resto da operacao e soma com o '0' para transformar em valor ASCII.
                newchar /= 10; // Prepara o valor para a proxima iteracao.
            } // No caso de 123, primeiro o 3 eh extraido, depois o 2, depois o 1 e fim.

            x += tam; // Apos o token ser totalmente extraido, salta o x para a proxima posicao livre, baseado no tamanho do digito inserido.
            npx[x] = ' '; // Espaco apos o numero/digitos serem inseridos na string posfixa.
            x++; // Acrescenta o tamanho da string apos a insercao do numero.
            
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

