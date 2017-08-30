#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct rgAluno{
    char nome[35];
    float notas[3];
};

int main()
{
    struct rgAluno Aluno;
    strcpy(Aluno.nome, "Francisco Lucas");
    Aluno.notas[0]=9.6;
    Aluno.notas[1]=8.4;
    Aluno.notas[2]=10;

    printf("Registro: \n");
    printf("Nome.......: %s \n", Aluno.nome);
    printf("Nota da AP1: %.2f \n", Aluno.notas[0]);
    printf("Nota da AP2: %.2f \n", Aluno.notas[1]);
    printf("Nota da AV.FINAL: %.2f \n", Aluno.notas[2]);

    return 0;
}
