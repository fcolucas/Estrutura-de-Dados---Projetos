#include <stdio.h>
#include <stdlib.h>
#define max 10
int main()
{
    int i, j, num, encontro=0;
    static int a[]={2, 3, 5, 7, 11}; //5 primeiros números primos
    static int b[]={1, 4, 9, 16, 25}; //5 primeiros quadrados perfeitos
    int c[max];

    //intercalando vetores a e b em c
    for(i=0; i<max/2; i++){
        c[i*2]=a[i];
        c[i*2+1]=b[i];
    }

    //pesquisa sequencial
    printf("Digite um número: ");
    scanf("%d", &num);
    while(encontro==0){
        while(j<max){
            if(c[j]==num){
                printf("Numero encontrado!");
                encontro=1;
            }
            j++;
        }
        printf("Numero nao encontrado");
    }
/*
    for(j=0; j<max; j++){
        printf("%d,", c[j]);
    }
*/
    return 0;
}
