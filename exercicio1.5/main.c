#include <stdio.h>
#include <stdlib.h>

/*
5. Escreva um algoritmo que receba um vetor de N elementos e verifique a existência de
elementos repetidos. Caso não existam elementos repetidos retorne um “Ok”. Caso
contrário, que remova as repetições dos elementos e que retorne o número de
elementos removidos. A seguir efetue uma pesquisa binária no vetor sem elementos
repetidos.
*/

void imprime_vetor(int *vet, int len){ //Imprime vetor
    int i=0;
    printf("{ ");
    for(i=0; i<len; i++){
        printf("%d ", vet[i]);
    }
    printf("}\n");
}

void ordena (int *vet, int len){ //Ordena os números na forma crescente
    int i=0, j, aux;

    for(i=0; i<len; i++){
        for(j=i+1; j<len; j++){
            if(vet[i]>vet[j]){
                aux = vet[i];
                vet[i]=vet[j];
                vet[j]=aux;
            }
        }
    }
}

int busca_binaria(int *vet, int len, int val){ //Busca Binária
    int i=0, meio=len/2, maior=len-1, menor=0;

    while(maior>=menor){
        if(vet[meio]==val){
            return 1;
        }
        else if(vet[meio]<val){
            menor=meio+1;
        }
        else{
            maior=meio-1;
        }
        meio=(maior+menor)/2;
    }
    return 0;
}

int verif_repetido(int *vet, int len){ //Verifica se há numero repetido
    int i=0, j=0, repete=0;
    for(i=0; i<len-1; i++){
        for(j=i+1; j<len; j++){
            if(vet[i]==vet[j]){
                repete++;
            }
        }
    }
    return repete;
}

void novo_vetor(int *vet, int *len){ // Reorganiza o vetor
    int i=0, j=0;
    for(i=0; i<*len-1; i++){
        for(j=i+1; j<*len; j++){
            if(vet[i]==vet[j]){
                vet[j]=vet[*len-1];
                *len-=1;
            }
        }
    }
}

int main()
{
    int tam=6, vetor[tam], nvetor[tam], aux=0, num, i=0;
    do{ //Criando vetor
        printf("Digite um numero: ");
        scanf("%d", &num);

        if(num<256){
            vetor[i]=num;
             }
            i++;
    }while(i<tam);

    printf("Vetor: ");
    imprime_vetor(vetor, tam);

    printf("Repeticoes: %d repeticao\n", verif_repetido(vetor, tam));
    novo_vetor(vetor, &tam);

    ordena(vetor, tam);
    printf("Novo vetor: ");
    imprime_vetor(vetor, tam);

    printf("Procure um numero: ");
    scanf("%d", &num);
    if(busca_binaria(vetor, tam, num)){
        printf("Numero encontrado!");
    }
    else {
        printf("Numero nao encontrado!");
    }
    return 0;
}
