#include <stdio.h>
#include <stdlib.h>

int primo(int num){
    if(num==1) return 0;
    int i;
    for(i=2; i<num; i++){
            if(num%i==0) return 0;
        }
    return 1;
    }

int main()
{
    int num, i, qtde=0;
    printf("Digite um numero: ");
    scanf("%d", &num);

    if(!primo(num)) printf("O numero %d nao e primo\n", num);
    else{
        printf("O numero %d e primo\n", num);
        printf("Primos sucessores de %d: ", num);
        for(i=num+1; qtde<2; i++){
            if(primo(i)){
                qtde++;
                printf("%d, ", i);
            }
        }

        qtde=0;
        printf("\nPrimos antecessores de %d: ", num);
        for(i=num-1; qtde<2; i--){
            if(primo(i)){
                qtde++;
                printf("%d, ", i);
            }
        }
    }
    return 0;
}
