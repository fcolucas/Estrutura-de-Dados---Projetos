#include <stdio.h>
#include <stdlib.h>

struct rgAluno{
    char nome[35];
    float notas[3];
};

int main()
{
    struct rgAluno Aluno[5];
    int i=0;

    for(i=0; i<5; i++){
        printf("Nome do Aluno: ");
        gets(Aluno[i].nome);
        fflush(stdin);

        printf("AP1: ");
        scanf("%f", &Aluno[i].notas[0]);

        printf("AP2: ");
        scanf("%f", &Aluno[i].notas[1]);

        printf("AV.FINAL: ");
        scanf("%f", &Aluno[i].notas[2]);
    }

    printf("\n -----REGISTRO DE ALUNOS----- \n \n");
    for(i=0; i<5; i++){
        printf("Nome............: %s \n", Aluno[i].nome);
        printf("Nota da AP1.....: %.1f \n", Aluno[i].notas[0]);
        printf("Nota da AP2.....: %.1f \n", Aluno[i].notas[1]);
        printf("Nota da AV.FINAL: %.1f \n \n", Aluno[i].notas[2]);
    }

    return 0;
}
