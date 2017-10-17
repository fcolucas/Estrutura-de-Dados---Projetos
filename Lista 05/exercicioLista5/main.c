#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 20

typedef struct Item{
    char valor;
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
    if (pilha->topo->prox == NULL) return 1;
    else return 0;
}

void empilha(Pilha *pilha, char v){
    Item *novo = (Item *)malloc(sizeof(Item));
    novo->valor = v;
    novo->prox = pilha->topo->prox;
    pilha->topo->prox = novo;
}

char desempilha(Pilha *pilha){
    Item *aux;
    char valor;
    if(PilhaVazia(pilha) == 0){
        aux = pilha->topo->prox;
        valor = aux->valor;
        aux->prox = aux->prox;
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
/*
char topoPilha (Pilha *pilha){
    return pilha->topo->valor;
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
    Pilha pilha;

    do{
        c = exp[i];
        if(isdigit(c)){
            retorno[j] = c;
            j++;
        }
        else{
            if(c!='\0'){
                    if(exp[i]=='('){
                        empilha(&pilha, exp[i]);
                    }
                    else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
                        while(PilhaVazia(&pilha)==0 && prioridade(topoPilha(&pilha)) >= prioridade(exp[i])){
                            retorno[j] = desempilha(&pilha);
                            j++;
                        }
                        empilha(&pilha, exp[i]);
                    }
                    else{
                        while(topoPilha(&pilha)!='('){
                            retorno[j] = desempilha(&pilha);
                            j++;
                        }
                    }
                }
            }
            i++;
        }while(exp[i]!='\0');
}
*/
int main()
{
    Pilha *p;
    /*
    char exp[TAM] = "4*4", retorno[TAM];
    empilha_expressao(exp, TAM, retorno);
    mostra_vetor(retorno, TAM);
    */
    empilha(p, 'C');
    imprime(p);
    return 0;
}
