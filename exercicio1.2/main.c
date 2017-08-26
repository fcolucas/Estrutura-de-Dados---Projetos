#include <stdio.h>
#include <stdlib.h>
int x[6], y[6], w[6], i=0, j, k, num, aux=0, sec=0 ;
int main()
{
    do{
        printf("Digite um numero: ");
        scanf("%d", &num);
        x[i]=num;
        i++;
    }while(i<6);

    while(k<6){
        if((x[k]>10) && (x[k]<40)){
            aux++;
            y[aux-1]=x[k];
        }
    k++;
    }

    while(k<6){
        if(x[k]%2==0){
            sec++;
            w[sec-1]=x[k];
        }
    k++;
    }

//    printf("Vetor Y de numeros entre 10 e 40: {");
    for(i=0;i<6;i++){
        printf("%d, ", w[i]);
    }
    //printf("}");


    return 0;

}
