#include <stdio.h>
#include <stdlib.h>

void mostra_matriz(int x, int y, int A[x][y]){
    int i=0, j=0;
    for(i=0; i<x; i++){
        printf("[ ");
        for(j=0; j<y; j++){
            printf("%4.d ", A[i][j]);
        }
        printf("]\n");
    }
}

void multiplica_matriz(int linA, int linB, int colA, int colB, int A[linA][colA], int B[linB][colB], int C[linA][colB]){
    int i=0, j=0, k=0;
    if(colA != linB) {printf("IMPOSSÍVEL MULTIPLICAR!");}
    else{
        for(i=0; i<linA; i++){
            for(j=0; j<colB; j++){
                C[i][j] = 0;
            }
        }

        for(i=0; i<linA; i++){
            for(j=0; j<colB; j++){
                for(k=0; k<colA; k++){
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

}

int main()
{
    int linA=5, colA=4, linB=4, colB=3, C[linA][colB];
    int A[5][4] = {
        {12, 43, 2, 6},
        {10, 9, 4, 20},
        {36, 50, 47, 15},
        {22, 7, 13, 62},
        {34, 26, 17, 32}
        };

    int B[4][3] = {
        {20, 36, 14},
        {5, 19, 6},
        {62, 53, 32},
        {37, 42, 66}
    };
    printf("\n Matriz A: \n");
    mostra_matriz(linA, colA, A);
    printf("\n Matriz B: \n");
    mostra_matriz(linB, colB, B);

    printf("\nMultiplicando A por B...\n");
    multiplica_matriz(linA, linB, colA, colB, A, B, C);

    printf(" Matriz C: \n");
    mostra_matriz(linA, colB, C);

    return 0;
}
