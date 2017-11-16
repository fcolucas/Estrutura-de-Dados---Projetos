#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TRUE 1
#define FALSE 0

typedef struct No Arvore;
struct No{
    int num;
    Arvore *esq;
    Arvore *dir;
};

int arvoreVazia(Arvore *raiz){
    if(raiz == NULL) return TRUE;
    else return FALSE;
}

Arvore *inserir (Arvore *aux, int num){
    if(aux == NULL){
        aux = malloc(sizeof(Arvore));
        aux->num = num;
        aux->dir = NULL;
        aux->esq = NULL;
    }
    else if(num < aux->num)
        aux->esq = inserir(aux->esq, num);
    else
        aux->dir = inserir(aux->dir, num);
    return aux;
}

int consultar(Arvore *aux, int num, int achou){
    if(aux != NULL && achou == 0){
        if(aux->num == num){
            achou = 1;
        }if(num < aux->num){
            achou = consultar(aux->esq, num, achou);
        }else{
            achou = consultar(aux->dir, num, achou);
        }
    }return achou;
}

void arvoreEmOrdem(Arvore *aux){
    if(aux != NULL){
        arvoreEmOrdem(aux->esq);
        printf("%d ", aux->num);
        arvoreEmOrdem(aux->dir);
    }
}

void arvorePreOrdem(Arvore *aux){
    if(aux != NULL){
        printf("%d ", aux->num);
        arvorePreOrdem(aux->esq);
        arvorePreOrdem(aux->dir);
    }
}

void arvorePosOrdem(Arvore *aux){
    if(aux != NULL){
        arvorePosOrdem(aux->esq);
        arvorePosOrdem(aux->dir);
        printf("%d ", aux->num);
    }
}

Arvore *remover(Arvore *aux, int num){
    Arvore *p, *p2;
    if(aux->num == num){
        if(aux->esq == aux->dir) {
            //raiz n�o tem filhos
            free(aux);
            return NULL;
        }
        else if(aux->esq == NULL){
            // raiz n�o tem filho para a esquerda
            p = aux->dir;
            free(aux);
            return p;
        }
        else if(aux->dir == NULL){
            // raiz n�o tem filho para a direita
            p = aux->esq;
            free(aux);
            return p;
        }
        else{
            //raiz tem filho para ambos os lados
            p2 = aux->dir;
            p = aux->dir;
            while(p->esq != NULL){
                p = p->esq;
            }
            p->esq = aux->esq;
            free(aux);
            return p2;
        }
    }
    else if(aux->num < num){
        aux->dir = remover(aux->dir, num);
    }
    else{
        aux->esq = remover(aux->esq, num);
    }
    return aux;
}

Arvore *desalocar(Arvore *aux){
    if(aux != NULL){
        aux->esq = desalocar(aux->esq);
        aux->dir = desalocar(aux->dir);
        free(aux);
    }
    return NULL;
}

void mostrarNos(Arvore *aux){
    int r, d=0, e=0;
    if(aux != NULL){
        r = aux->num;
        if(aux->dir != NULL) {
            d = aux->dir->num;
        }if(aux->esq != NULL) {
            e = aux->esq->num;
        }
        printf("{%d[%d, %d]} ", r, e, d);
        mostrarNos(aux->esq);
        mostrarNos(aux->dir);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Arvore *raiz = NULL;
    int op, achou, num, menu=1, q, i;
    do{
        printf("\n�RVORE BINARIA \n");
        printf("1- Inserir n�s na �rvore \n");
        printf("2- Consultar n� na �rvore \n");
        printf("3- Listar �rvore em ordem \n");
        printf("4- Listar �rvore em pr�-ordem \n");
        printf("5- Listar �rvore em p�s-ordem \n");
        printf("6- Excluir n� na �rvore \n");
        printf("7- Esvaziar �rvore \n");
        printf("0- Sair da aplica��o \n");
        printf("\n -> Escolha sua op��o: ");
        scanf("%d", &op);
        fflush(stdin);

        switch(op){
        case 1:
            printf("\nINSERIR N�S NA �RVORE\n");
            printf(" -> Quantos n�s a inserir? ");
            scanf("%d", &q);
            fflush(stdin);
            for(i=1; i<=q; i++){
                printf(" -> Digite o valor do n� %d: ", i);
                scanf("%d", &num);
                fflush(stdin);
                achou = 0;
                achou = consultar(raiz, num, achou);
                if(achou){
                    printf("  N� j� inserido!\n");
                    i--;
                }
                else{
                raiz = inserir(raiz, num);
                }
            }
            printf("  N�s inseridos na �rvore! \n");
            printf("  �rvore: ");
            mostrarNos(raiz);
            printf("\n");
            break;

        case 2:
            printf("\nCONSULTAR N� NA �RVORE\n");
            if(!arvoreVazia(raiz)){
                printf(" -> Digite o n� a ser consultado: ");
                scanf("%d", &num);
                fflush(stdin);
                achou = 0;
                achou = consultar(raiz, num, achou);
                if(achou){
                    printf("  N� encontrado na �rvore!\n");
                }
                else{
                    printf("  N� n�o encontrado!\n");
                }
            }
            else{
                printf("  �rvore vazia!\n");
            }
            break;

        case 3:
            printf("\nLISTAR �RVORE EM ORDEM\n");
            if(!arvoreVazia(raiz)){
                printf("  Listando elementos... { ");
                arvoreEmOrdem(raiz);
                printf("}\n");
            }
            else{
                printf("  �rvore vazia!\n");
            }
            break;

        case 4:
            printf("\nLISTAR �RVORE EM PR�-ORDEM\n");
            if(!arvoreVazia(raiz)){
                printf("  Listando elementos... { ");
                arvorePreOrdem(raiz);
                printf("}\n");
            }
            else{
                printf("  �rvore vazia!\n");
            }
            break;

        case 5:
            printf("\nLISTAR �RVORE EM P�S-ORDEM\n");
            if(!arvoreVazia(raiz)){
                printf("  Listando elementos... { ");
                arvorePosOrdem(raiz);
                printf("}\n");
            }
            else{
                printf("  �rvore vazia!\n");
            }
            break;

        case 6:
            printf("\nEXCLUIR N� DA �RVORE\n");
            if(!arvoreVazia(raiz)){
                printf(" -> Digite o n� a ser excluido: ");
                scanf("%d", &num);
                fflush(stdin);
                achou = 0;
                achou = consultar(raiz, num, achou);
                if(achou){
                    raiz = remover(raiz, num);
                    printf("  N� exclu�do!\n");
                    printf("  �rvore: ");
                    mostrarNos(raiz);
                    printf("\n");
                }
                else printf("  N� n�o encontrado!\n");
            }
            else{
                printf("  �rvore vazia!\n");
            }
            break;

        case 7:
            printf("\nESVAZIAR �RVORE\n");
            if(!arvoreVazia(raiz)){
                raiz = desalocar(raiz);
                printf("  �rvore esvaziada!\n");
            }
            else{
                printf("  �rvore vazia! \n");
            }
            break;

        case 0:
            printf("\n -> DESEJA SAIR DA APLICA��O(1-SIM // 2-N�O)? ");
            scanf("%d", &num);
            fflush(stdin);
            if(num == 1){
                printf("  Saindo da aplica��o...\n");
                menu = 0;
            }
            break;

        default:
            printf("  OP��O INV�LIDA! \n");
            break;
        }
    }while(menu);
    /*
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 14);
    arvoreEmOrdem(raiz);
    printf("\n");

    raiz = remover(raiz, 3);
    arvoreEmOrdem(raiz);
    raiz = desalocar(raiz);
    if(raiz == NULL) printf("Vazia!");
    */
    return 0;
}
