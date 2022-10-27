#include <stdio.h>
#include <stdlib.h>

/*
5. Escreva um algoritmo que receba um vetor de N elementos e verifique a exist�ncia de
elementos repetidos. Caso n�o existam elementos repetidos retorne um �Ok�. Caso
contr�rio, que remova as repeti��es dos elementos e que retorne o n�mero de
elementos removidos. A seguir efetue uma pesquisa bin�ria no vetor sem elementos
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

void ordena(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

int busca_binaria(int *vet, int len, int val){ //Busca Bin�ria
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

void novo_vetor(int *vet, int *len){ // Retirando numeros repetidos
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
    int tam=6, vetor[tam], nvetor[tam], aux=0, num, i=0, tam2=tam;
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

    novo_vetor(vetor, &tam);
    if(tam!=tam2){
        printf("Repeticoes: %d repeticao\n", tam2-tam);
    }
    else printf("OK!");

    ordena(vetor, 0, tam);
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
