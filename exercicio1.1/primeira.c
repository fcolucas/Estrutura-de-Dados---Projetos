#include <stdio.h>
#include <stdlib.h>
#define tam 6
/*
Leia uma lista de no máximo 100 números inteiros, carregando-os em um vetor. Os
números lidos maiores ou iguais que 256 deverão ser ignorados.
 Ordene os números lidos em ordem decrescente.
 Informar quantos são ímpares e quantos são pares.
 Apresente a média dos números ímpares maiores que 50.
*/

void ordena (int *vet, int len){ //Ordena os números na forma decrescente
    int i, j, aux;

    for(i=0; i<len; i++){
        for(j=i+1; j<len; j++){
            if(vet[i]<vet[j]){
                aux = vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
            }
        }
    }
}

void conta_par_impar(int *vet, int len, int *q_par, int *q_impar){ //Conta numeros pares e impares
    int i;
    for(i=0; i<len; i++){
        if(vet[i]%2==0) *q_par=*q_par+1;
        else *q_impar=*q_impar+1;
    }
}

int maior_q_50(int *vet, int len){ //Faz a média dos números impares maiores que 50
    int i, j=0, media=0;
    for(i=0; i<len; i++){
        if(vet[i]>50 && vet[i]%2!=0){
            media+=vet[i];
            j++;
        }
    }
    if(j>0) media/=j;
    return media;
}

int main(){
    int vetor[tam], i=0, k, num=0, q_par=0, q_impar=0;

    do{ //Criando vetor
        printf("Digite um numero: ");
        scanf("%d", &num);

        if(num<256){
            vetor[i]=num;
             }
            i++;
    }while(i<tam);

    conta_par_impar(vetor, tam, &q_par, &q_impar);

    ordena(vetor, tam);

    printf("-----LISTA ORDENADA-----\n");
    printf("{");
    for(k=0; k<6; k++){
        printf("%d ", vetor[k]);
    }
    printf("}\n");
    printf("\nQuantidade de pares: %d", q_par);
    printf("\nQuantidade de impares: %d", q_impar);
    printf("\nMedia dos numeros impares maiores que 50: %d", maior_q_50(vetor, tam));

    return 0;
}
