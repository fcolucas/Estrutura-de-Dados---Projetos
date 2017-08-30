#include <stdio.h>
#include <stdlib.h>

struct rgAluno{
    char nome[35];
    float notas[3];
};

int main()
{
    struct rgAluno Aluno;
    printf("Nome do Aluno: ");
    gets(Aluno.nome);

    printf("Digite a nota AP1: ");
    scanf("%f", &Aluno.notas[0]);

    printf("Digite a nota AP2: ");
    scanf("%f", &Aluno.notas[1]);

    printf("Digite a nota AV.FINAL: ");
    scanf("%f", &Aluno.notas[2]);

    printf("Registro feito!\n");
    printf("Nome: %s \n", Aluno.nome);
    printf("Nota da AP1: %.2f \n", Aluno.notas[0]);
    printf("Nota da AP2: %.2f \n", Aluno.notas[1]);
    printf("Nota da AV.FINAL: %.2f \n", Aluno.notas[2]);

    return 0;
}
