#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define TAM 20


typedef struct node{
    char valor;
    struct node *prox;
}Node;

int vaziaP (Node *pilha){ //verifica se a pilha está vazia
    if(pilha->prox == NULL){
            return 1;}
    else {
            return 0;}
}

void empilha(Node *pilha, char valor){ //empilha valores na pilha
    Node *topo = (Node *)malloc(sizeof(Node));
    topo->valor = valor;
    topo->prox = pilha->prox;
    pilha->prox = topo;
}

char desempilha(Node *pilha){ //desempilha o valor topo da pilha
    Node *x;
    int valor;
    if(pilha->prox != NULL){
        x = pilha->prox;
        valor = x->valor;
        pilha->prox = x->prox;
        free(x);
    }
    return valor;
}

char topoP (Node *pilha){
    return pilha->prox->valor;
}

int prioridade (char op){
    int pri;
    if(op == '(') pri = 1;
    else if (op == '+' || op == '-') pri = 2;
    else if (op == '*' || op == '/') pri = 3;
    return pri;
}

void mostra_vetor (char *vet, int tam){
    int i;
    printf("[ ");
    for(i=0; i<tam; i++){
        if(vet[i]!='\0') printf("%c ", i);
        else break;
    }
    printf("]");
}

void empilha_expressao(char *exp, int tam, char exp2[tam]){
    int i, num=0, j=0;
    char c;
    Node *pilha = NULL;

    for(i=0; TRUE; i++){
        c = exp[i];
        if(isdigit(c)){
            num = c-'0' + num*10;
        }
        else{
            if(num){
                exp2[j] = num; j++;
                num = 0;
            }
            if(c!='\0'){
                    if(exp[i]=='('){
                        empilha(pilha, exp[i]);
                    }
                    else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
                        while(vaziaP(pilha)==0 || prioridade(topoP(pilha)) >= prioridade(exp[i])){
                            exp2[j] = desempilha(pilha);
                            j++;
                        }
                        empilha(pilha, exp[i]);
                    }
                    else{
                        while(topoP(pilha)!='('){
                            exp2[j] = desempilha(pilha);
                            j++;
                        }
                    }
                }
            else{
                break;
                }
            }
        }
}

int main()
{
    Node *pilha = (Node *)malloc(sizeof(Node));
    pilha->prox = NULL;

    char exp2[TAM];
    char s[TAM] = "3+6-7*8";
    empilha_expressao(s, TAM, exp2);
    mostra_vetor(exp2, TAM);
    return 0;
}
