#include <stdio.h>
#include <stdlib.h>

typedef struct box{
        char conteudo;
        struct box *proximo;
    }Box;

void mostrar_box(Box *inicio){
    Box *p = inicio->proximo;
    printf("Lista: ");
    while(p != NULL){
        printf(" %c ", p->conteudo);
        p = p->proximo;
    }
    printf("\n");
}

void insere_final (Box *inicio, char cont){
    Box *novo = inicio;
    for(novo = inicio; novo->proximo != NULL; novo=novo->proximo){
    }
    novo->proximo = (Box *)malloc(sizeof(Box));
    novo = novo->proximo;
    novo->conteudo = cont;
    novo->proximo = NULL;
}

void insere_inicio (Box *inicio, char cont){
    Box *novo = (Box *) malloc(sizeof(Box));
    novo->conteudo = cont;
    novo->proximo = inicio->proximo;
    inicio->proximo = novo;
}

void insere_entre_dois(Box *inicio, char primeiro, char cont){
    Box *temp1 = inicio;
    while(temp1->conteudo != primeiro){
        temp1 = temp1->proximo;
    }
    Box *novo = (Box*)malloc(sizeof(Box));
    novo->conteudo = cont;
    novo->proximo = temp1->proximo;
    temp1->proximo = novo;
}

void exclue(Box *inicio, char cont){
    Box *temp1 = inicio;
    while(temp1->proximo->conteudo != cont){
        temp1 = temp1->proximo;
    }
    Box *temp2 = temp1->proximo;
    temp1->proximo = temp2->proximo;
    free(temp2);
}

int main()
{
    Box *inicio, *temp1, *temp2;

    // crinado célula-cabeça
    inicio = (Box *) malloc(sizeof(Box));
    inicio->proximo = NULL;

    // 1 - Inserindo elemento A no final
    insere_final(inicio, 'A');
    mostrar_box(inicio);

    //2 - Inserindo elemento B no inicio
    insere_inicio(inicio, 'B');
    mostrar_box(inicio);

    //3 - Inserindo elemento C no inicio
    insere_final(inicio, 'C');
    mostrar_box(inicio);

    //4 - inserindo elemento D no inicio
    insere_final(inicio, 'D');
    mostrar_box(inicio);

    //5 - Inserindo elemento E entre A e C
    insere_entre_dois(inicio, 'A', 'E');
    mostrar_box(inicio);

    //6 - Inserindo elemento F no final
    insere_final(inicio, 'F');
    mostrar_box(inicio);

    //7 - Inserindo elemento G no inicio
    insere_inicio(inicio, 'G');
    mostrar_box(inicio);

    //8 - Excluindo ultimo elemento
    temp1 = inicio;
    while(temp1->proximo->proximo != NULL){
        temp1 = temp1->proximo;
    }
    temp2 = temp1->proximo;
    temp1->proximo = temp2->proximo;
    free(temp2);

    mostrar_box(inicio);

    //9 - Excluindo primeiro elemento
    temp1 = inicio->proximo;
    inicio->proximo = temp1->proximo;
    free(temp1);

    mostrar_box(inicio);

    //10 - Inserindo elemento H entre A e E
    insere_entre_dois(inicio, 'A', 'H');
    mostrar_box(inicio);

    //11 - Excluindo elemento A
    exclue(inicio, 'A');
    mostrar_box(inicio);


    //12 - Inserindo elemento I entre E e D
    insere_entre_dois(inicio, 'E', 'I');
    mostrar_box(inicio);

    //13 - Inserindo elemento J no inicio
    insere_final(inicio, 'J');
    mostrar_box(inicio);

    //14 - Inserindo elemento K entre B e H
    insere_entre_dois(inicio, 'B', 'K');
    mostrar_box(inicio);

    //15 - Excluindo elementos D, K e I
    exclue(inicio, 'D');
    exclue(inicio, 'K');
    exclue(inicio, 'I');
    mostrar_box(inicio);

    //16 - Excluindo elemento B
    exclue(inicio, 'B');
    mostrar_box(inicio);

    //17 - Inserindo elemento L no inicio
    insere_final(inicio, 'L');
    mostrar_box(inicio);

    return 0;
}
