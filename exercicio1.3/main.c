#include <stdio.h>
#include <stdlib.h>
#define max 10
/*
Leia um vetor A e um vetor B, ambos com N elementos e que intercale estes vetores A e
B, formando um outro vetor C da seguinte forma. A seguir efetue uma pesquisa
seqüencial no vetor C.
C[1] > A[1]
C[2] > B[1]
C[3] > A[2]
C[4] > B[2]
*/

void imprime_vetor(int *vet, int len){ //Imprimir vetor
    int i=0;
    printf("{ ");
    for(i=0; i<len; i++){
        printf("%d ", vet[i]);
    }
    printf("}\n");
}

int busca(int *vet, int len, int val){ //Buscar elemento
   int i=0;
   for(i=0; i<len; i++){
        if(vet[i]==val){
            return 1;
        }
   }
   return 0;
}

int main()
{
    int i, num;
    static int a[]={2, 3, 5, 7, 11}; //5 primeiros números primos
    static int b[]={1, 4, 9, 16, 25}; //5 primeiros quadrados perfeitos
    int c[max];

    //intercalando vetores a e b em c
    for(i=0; i<max/2; i++){
        c[i*2]=a[i];
        c[i*2+1]=b[i];
    }

    printf("Vetor A: ");
    imprime_vetor(a, 5);
    printf("\nVetor B: ");
    imprime_vetor(b, 5);

    printf("\nIntercalando vetor A e vetor B em C...\nVetor C: ");

    imprime_vetor(c, max);

    printf("Procure um numero: ");
    scanf("%d", &num);
    if(busca(c, max, num)){
        printf("Numero encontrado!\n");
    }
    else printf("Numero nao encontrado!\n");

    return 0;
}
