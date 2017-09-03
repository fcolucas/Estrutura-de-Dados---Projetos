#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define qtde 5

struct rgAgenda{
    char nome[30];
    char endereco[30];
    int telefone;
    char situacao;
};

void insere(struct rgAgenda *ag, int contatos){
    printf("Digite o nome: ");
    gets(ag[contatos].nome);

    printf("Digite endereco: ");
    gets(ag[contatos].endereco);

    printf("Digite telefone: ");
    scanf("%d", &ag[contatos].telefone);

    printf("Digite situacao (L – Livre; X – Ocupado ou * - Apagado): ");
    scanf("%s", &ag[contatos].situacao);

    fflush(stdin);
}

int pesquisa(struct rgAgenda *ag, char *nome, int contatos){
    int i=0;
    for(i=0; i<contatos; i++){
        if(!strcmp(ag[i].nome, nome)){
            return i;
        }
    }
    return -1;
}

void mostra(struct rgAgenda *ag, int indice){
    char sit[10];
    printf("Nome: %s \n", ag[indice].nome);
    printf("Endereço: %s \n", ag[indice].endereco);
    printf("Telefone: %d \n", ag[indice].telefone);
    if(ag[indice].situacao == 'L') {strcpy(sit, "Livre");}
    else if(ag[indice].situacao == 'X') {strcpy(sit, "Ocupado");}
    else if(ag[indice].situacao == '*') {strcpy(sit, "Apagado");}

    printf("Situação: %s \n", sit);
}

int main()
{
    setlocale(LC_ALL, ""); //adaptação do programa ao idioma desejado

    char nome[30];
    int contatos=0, op, menu=1, n, i=0;
    struct rgAgenda Agenda[qtde];

    do{
        printf("\n ------------- \n");
        printf(" MINHA AGENDA \n");
        printf(" ------------- \n \n");
        printf("1 - Inserir contato\n");
        printf("2 - Pesquisar contato\n");
        printf("3 - Alterar contato\n");
        printf("4 - Sair da aplicação\n");
        printf("Digite uma opção: ");
        scanf("%d", &op);
        fflush(stdin);

        switch(op){
            case 1:
                if(contatos<qtde){
                    printf("\n --- INSERIR CONTATO --- \n");
                    insere(Agenda, contatos);
                    printf("\n *CONTATO INSERIDO!* \n");
                    contatos+=1;
                }
                else {
                    printf("\n * AGENDA LOTADA! * \n");
                }
                break;

            case 2:
                printf("\n --- PESQUISAR CONTATO --- \n");
                if(contatos <=0 ) {printf ("\n * NÃO HÁ CONTATOS! *\n");}

                else{
                    printf("Digite o nome a ser pesquisado: ");
                    scanf("%s", nome);
                    fflush(stdin);
                    n = pesquisa(Agenda, nome, contatos);

                    if(n == -1){
                        printf("\n * CONTATO NÃO ENCONTRADO! *\n");
                    }
                    else{
                        printf("\n * CONTATO ENCONTRADO *\n");
                        mostra(Agenda, n);
                    }
                }
                break;

            case 3:
                printf("\n --- ALTERAR CONTATO --- \n");
                if(contatos <= 0) {printf ("\n * NÃO HÁ CONTATOS! *\n");}

                else{
                    for(i=0; i<contatos; i++){
                        printf("%d - %s \n", i, Agenda[i].nome);
                    }
                    printf("\nDigite a opção de alteração: ");
                    scanf("%d", &op);
                    fflush(stdin);

                    if(op < contatos){
                        mostra(Agenda, op);
                        printf("\n ALTERANDO DADOS... \n");
                        printf("Nome: ");
                        gets(Agenda[op].nome);
                        printf("Endereço: ");
                        gets(Agenda[op].endereco);
                        printf("Telefone: ");
                        scanf("%d", &Agenda[op].telefone);
                        printf("Situacao (L – Livre; X – Ocupado ou * - Apagado): ");
                        scanf("%s", &Agenda[op].situacao);

                        fflush(stdin);
                    }
                    else printf("\n OPERAÇÃO INVÁLIDA! \n");
                }
                break;

            case 4:
                printf("\n -> Deseja sair (1 - SIM // 2 - NÃO): ");
                scanf("%d", &op);
                if(op == 1){
                    printf("\n SAINDO DA APLICAÇÃO...\n");
                    menu=0;
                }
                else {break;}
                break;

            default:
                printf("\n * OPÇÃO INVÁLIDA! * \n");
                break;
        }
    } while (menu);

    return 0;
}
