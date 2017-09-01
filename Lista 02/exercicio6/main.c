#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rgAgenda{
    char nome[30];
    char endereco[30];
    int telefone;
    char situacao;
};

void insere(struct rgAgenda *ag, int len){
    int i=0;
    for(i=0; i<len; i++){
        printf("Digite o nome: ");
        gets(ag[i].nome);

        printf("Digite endereco: ");
        gets(ag[i].endereco);

        printf("Digite telefone: ");
        scanf("%d", ag[i].telefone);

        printf("Digite situacao (L – Livre; X – Ocupado ou * - Apagado): ");
        scanf("%s", ag[i].situacao);

        fflush(stdin);
    }
}

void mostra_registro(struct rgAgenda *ag, int len){
    int i=0;
    while(i<len){
        printf("Nome: %s \n", ag[i].nome);
        printf("Endereco: %s \n", ag[i].endereco);
        printf("Telefone: %d \n", ag[i].telefone);
        printf("Situacao: %c \n", ag[i].situacao);

        i++;
        printf("\n");
    }
}

int main()
{
    char op;
    const qtde = 5;
    struct rgAgenda Agenda[qtde];

    printf("1-Inserir registros\n");
    printf("2-Pesquisar registro\n");
    printf("3-Alterar registro\n");
    printf("4-Sair da aplicação\n");
    printf("Digite uma opção:\n");
    scanf("%d", &op);

    switch(op){
        case '1':
            insere(Agenda, qtde);
            break;

        case '2':
            mostra_registro(Agenda, qtde);
            break;

        case '3':
            break;

        case '4':
            break;


    }


    return 0;
}
