#include <stdio.h>
#include <stdlib.h>

int main()
{
int vetor[6], i=0, j, aux, k, num=0, q_par=0, q_impar=0, soma_impar=0, maior=0;
float media_impar;

do{
    printf("Digite um numero: ");
    scanf("%d", &num);

    if(num<256){
        vetor[i]=num;

        if(num%2==0) q_par++;
        else{
         q_impar++;

         if(num>50){
            soma_impar+=num;
            maior++;
         }
        }
        i++;
    }
}while(i<6);

/*Ordenação do vetor */
for(i=0; i<6; i++){
    for(j=i+1; j<6; j++){
        if(vetor[i]<vetor[j]){
            aux = vetor[i];
            vetor[i]=vetor[j];
            vetor[j]=aux;
        }
    }
}
printf("-----LISTA ORDENADA-----\n");
printf("{");
for(k=0; k<6; k++){
    printf("%d,", vetor[k]);
}
printf("}\n");
    printf("\nQuantidade de pares: %d", q_par);
    printf("\nQuantidade de impares: %d", q_impar);
    if(maior>0) printf("\nMedia dos num impares maiores que 50: %d", soma_impar/maior);
    return 0;
}
