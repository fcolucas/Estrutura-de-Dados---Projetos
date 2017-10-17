#include <stdio.h>
#include <stdlib.h>
#include <string.h> //função strcpy

struct rgAgenda{
    char nome[30];
    char endereco[30];
    int telefone;
    char situacao;
};

//Situação (L – Livre; X – Ocupado e * - Apagado)

int main()
{
    struct rgAgenda Agenda;

    strcpy(Agenda.nome, "Francisco Lucas");
    strcpy(Agenda.endereco, "Rua F");
    Agenda.telefone=994329497;
    Agenda.situacao = 'L';

    printf("Registro: \n");
    printf("Nome: %s \n", Agenda.nome);
    printf("Endereco: %s \n", Agenda.endereco);
    printf("Telefone: %d \n", Agenda.telefone);
    printf("Situacao: %c \n", Agenda.situacao);

    return 0;
}
