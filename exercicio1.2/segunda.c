#include <stdio.h>
#include <stdlib.h>
#define tam 6
/*
2. Leia um vetor X de N elementos e que:
 Crie outro vetor Y contendo os elementos de X que estão na faixa entre 10 e 40;
 Crie outro vetor W contendo os números que estão nas posições pares;
 Pesquise a existência de um determinado elemento Z no vetor X;
 Escreva o menor e maior elemento do vetor X.
*/


void entre_10_40(int *x, int *y, int len, int *aux){
    int i=0;
    for(i=0; i<len; i++){
        if((10<x[i]) && (x[i]<40)){
            y[*aux]=x[i];
            *aux+=1;
        }
    }
}

void posicao_par(int *x, int *w, int len, int *sec){
    int i=0;
    for(i=0; i<len; i+=2){
        w[*sec]=x[i];
        *sec+=1;
    }
}

void imprime_vetor(int *vet, int len){
    int i=0;
    printf("{ ");
    for(i=0; i<len; i++){
        printf("%d ", vet[i]);
    }
    printf("}\n");
}

int busca(int *vet, int len, int val){
   int i=0;
   for(i=0; i<len; i++){
        if(vet[i]==val){
            return 1;
        }
   }
   return 0;
}

int maior_elem(int *x, int len){
    int i=0, maior=x[i];
    for(i=0; i<len; i++){
        if(x[i]>maior) maior=x[i];
    }
    return maior;
}

int menor_elem(int *x, int len){
    int i=0, menor=x[i];
    for(i=0; i<len; i++){
        if(x[i]<menor) menor=x[i];
    }
    return menor;
}

int main()
{
    int x[tam], y[tam], w[tam], i=0, num, aux=0, sec=0 ;
    do{
        printf("Digite um numero: ");
        scanf("%d", &num);
        x[i]=num;
        i++;
    }while(i<tam);

    entre_10_40(x, y, tam, &aux);

    posicao_par(x, w, tam, &sec);

    printf("Vetor X:");
    imprime_vetor(x, tam);

    printf("Vetor Y de numeros entre 10 e 40:");
    imprime_vetor(y, aux);

    printf("Vetor W:");
    imprime_vetor(w, sec);

    printf("Maior elemento de X: %d // Menor elemento de X: %d \n", maior_elem(x, tam), menor_elem(x, tam));

    printf("Procure um numero: ");
    scanf("%d", &num);
    if(busca(x, tam, num)){
        printf("Numero encontrado!\n");
    }
    else printf("Numero nao encontrado!\n");

    return 0;

}
