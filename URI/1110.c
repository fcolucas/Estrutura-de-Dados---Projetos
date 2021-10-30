#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
 int info;
 struct lista *prox;
}Lista;

typedef struct fila{
 Lista *ini;
 Lista *fim;
}Fila;

Fila *inicialize(){
 Fila prim = (Fila)malloc(sizeof(Fila));
 prim->ini = NULL;
 prim->fim = NULL;
 return prim;
}

void *push(Fila *p, int carta){
 Lista novo = (Lista)malloc(sizeof(Lista));
 novo->info = carta;
 novo->prox = NULL;
 if(p->ini==NULL){
  p->ini = novo;
  p->fim = novo;
 }else{
  p->fim->prox = novo;
  p->fim = novo;
 }

}

int pop(Fila *p){
 int carta;
 Lista *l;

 l = p->ini;
 carta = l->info;

 p->ini = l->prox;
 if(p->ini==NULL)
  p->fim = NULL;

 free(l);

 return carta;
}

int vazio(Fila *p){
 return p->ini==NULL;
}

int main(){

 int n, i, carta, cont = 0;
 Fila *fila;

 fila = inicialize();

 do{
  scanf("%d", &n);
  if(n){
   cont = n;
   for(i=1;i<=n;i++){
    push(fila, i);
   }

   printf("Discarded cards:");

   while(cont!=1){
    printf(" %d", pop(fila));
    push(fila, pop(fila));

    if(cont!=2)
     printf(",");
    cont--;
   }

   if(!vazio(fila))
    printf("\nRemaining card: %d\n", pop(fila));
  }
 }while(n!=0);

 return 0;
}
