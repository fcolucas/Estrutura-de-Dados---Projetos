#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rgAgenda{
    char nome[30];
    char endereco[30];
    int telefone;
    char situacao;
};

void insere(struct rgAgenda ag){
    printf("Digite o nome: ");
    gets(ag.nome);

    printf("Digite endereco: ");
    gets(ag.endereco);

    printf("Digite telefone: ");
    scanf("%d", ag.telefone);

    printf("Digite situacao (L – Livre; X – Ocupado ou * - Apagado): ");
    gets(ag.situacao);

    fflush(stdin);
}

void mostra_registro(struct rgAgenda ag){
    int i=0;
    while(i<5){
        printf("Nome: %s \n", ag.nome);
        printf("Endereco: %s \n", ag.endereco);
        printf("Telefone: %d \n", ag.telefone);
        printf("Situacao: %c \n", ag.situacao);
    }
}

int main()
{
    int op;
    const qtde = 5;
    struct rgAgenda Agenda[qtde];

    printf("1-Inserir registros\n");
    printf("2-Pesquisar registro\n");
    printf("3-Alterar registro\n");
    printf("4-Sair da aplicação\n");
    printf("Digite uma opção:\n");
    scan("%d", &op);



    return 0;
}
