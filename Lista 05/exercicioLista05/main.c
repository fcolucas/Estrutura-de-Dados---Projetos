#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 20

typedef struct Item{
    int valor;
    struct Item *prox;
}Item;

typedef struct TipoPilha{
    Item *topo;
}Pilha;

void FazPilhaVazia(Pilha *pilha){
    pilha->topo = (Item *)malloc(sizeof(Item));
    pilha->topo->prox = NULL;
}

int PilhaVazia (Pilha *pilha) {
    if (pilha->topo == NULL) return 1;
    else return 0;
}

void empilha(Pilha *pilha, int v){
    Item *novo = (Item *)malloc(sizeof(Item));
    novo->valor = v;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int desempilha(Pilha *pilha){
    Item *aux;
    int valor;
    if(PilhaVazia(pilha) == 0){
        aux = pilha->topo;
        valor = aux->valor;
        pilha->topo = pilha->topo->prox;
        free(aux);
    }
    return valor;
}

void imprime(Pilha *pilha){
    if(PilhaVazia(pilha) == 0){
        while(pilha->topo->prox != NULL){
            printf("%c", desempilha(pilha));
        }
    }
}

char topoPilha (Pilha *pilha){
    return pilha->topo->valor;
}

char opera (Pilha *op, Pilha *num){
    int num1 = atoi(desempilha(num));
    int num2 = atoi(desempilha(num));
    char oper = desempilha(op);
    int res;
    switch(oper){
        case '+':
            res = num1 + num2;
            empilha(num, res);
            break;
        case '-':
            res = num1 - num2;
            empilha(num, res);
            break;
        case '*':
            res = num1 * num2;
            empilha(num, res);
            break;
        case '/':
            res = num1 / num2;
            empilha(num, res);
            break;
    }
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

void empilha_expressao(char *exp, int tam, char *retorno){
    int i=0, j=0;
    char c;
    Pilha *op = NULL, *num = NULL;

    do{
        c = exp[i];
        if(isdigit(c)){
            empilha(num, c);
        }
        else{
            if(c!='\0'){
                    if(c=='('){
                        empilha(op, c);
                    }
                    else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
                        while(PilhaVazia(op)==0 && prioridade(topoPilha(op)) >= prioridade(exp[i])){
                            retorno[j] = desempilha(op);
                            j++;
                        }
                        empilha(op, exp[i]);
                    }
                    else{
                        while(topoPilha(op)!='('){
                            retorno[j] = desempilha(op);
                            j++;
                        }
                        desempilha(op);
                    }
                }
            }
            i++;
        }while(exp[i]!='\0');
}

int main()
{
    Pilha p;
    FazPilhaVazia(&p);

    char exp[TAM] = "4*4", retorno[TAM];
    empilha_expressao(exp, TAM, retorno);
    mostra_vetor(retorno, TAM);
    /*
    FazPilhaVazia(&p);
    empilha(&p, 'C');
    imprime(&p);
    */
    return 0;
}

