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
            //raiz não tem filhos
            free(aux);
            return NULL;
        }
        else if(aux->esq == NULL){
            // raiz não tem filho para a esquerda
            p = aux->dir;
            free(aux);
            return p;
        }
        else if(aux->dir == NULL){
            // raiz não tem filho para a direita
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
        printf("\nÁRVORE BINARIA \n");
        printf("1- Inserir nós na árvore \n");
        printf("2- Consultar nó na árvore \n");
        printf("3- Listar árvore em ordem \n");
        printf("4- Listar árvore em pré-ordem \n");
        printf("5- Listar árvore em pós-ordem \n");
        printf("6- Excluir nó na árvore \n");
        printf("7- Esvaziar árvore \n");
        printf("0- Sair da aplicação \n");
        printf("\n -> Escolha sua opção: ");
        scanf("%d", &op);
        fflush(stdin);

        switch(op){
        case 1:
            printf("\nINSERIR NÓS NA ÁRVORE\n");
            printf(" -> Quantos nós a inserir? ");
            scanf("%d", &q);
            fflush(stdin);
            for(i=1; i<=q; i++){
                printf(" -> Digite o valor do nó %d: ", i);
                scanf("%d", &num);
                fflush(stdin);
                achou = 0;
                achou = consultar(raiz, num, achou);
                if(achou){
                    printf("  Nó já inserido!\n");
                    i--;
                }
                else{
                raiz = inserir(raiz, num);
                }
            }
            printf("  Nós inseridos na árvore! \n");
            printf("  Árvore: ");
            mostrarNos(raiz);
            printf("\n");
            break;

        case 2:
            printf("\nCONSULTAR NÓ NA ÁRVORE\n");
            if(!arvoreVazia(raiz)){
                printf(" -> Digite o nó a ser consultado: ");
                scanf("%d", &num);
                fflush(stdin);
                achou = 0;
                achou = consultar(raiz, num, achou);
                if(achou){
                    printf("  Nó encontrado na árvore!\n");
                }
                else{
                    printf("  Nó não encontrado!\n");
                }
            }
            else{
                printf("  Árvore vazia!\n");
            }
            break;

        case 3:
            printf("\nLISTAR ÁRVORE EM ORDEM\n");
            if(!arvoreVazia(raiz)){
                printf("  Listando elementos... { ");
                arvoreEmOrdem(raiz);
                printf("}\n");
            }
            else{
                printf("  Árvore vazia!\n");
            }
            break;

        case 4:
            printf("\nLISTAR ÁRVORE EM PRÉ-ORDEM\n");
            if(!arvoreVazia(raiz)){
                printf("  Listando elementos... { ");
                arvorePreOrdem(raiz);
                printf("}\n");
            }
            else{
                printf("  Árvore vazia!\n");
            }
            break;

        case 5:
            printf("\nLISTAR ÁRVORE EM PÓS-ORDEM\n");
            if(!arvoreVazia(raiz)){
                printf("  Listando elementos... { ");
                arvorePosOrdem(raiz);
                printf("}\n");
            }
            else{
                printf("  Árvore vazia!\n");
            }
            break;

        case 6:
            printf("\nEXCLUIR NÓ DA ÁRVORE\n");
            if(!arvoreVazia(raiz)){
                printf(" -> Digite o nó a ser excluido: ");
                scanf("%d", &num);
                fflush(stdin);
                achou = 0;
                achou = consultar(raiz, num, achou);
                if(achou){
                    raiz = remover(raiz, num);
                    printf("  Nó excluído!\n");
                    printf("  Árvore: ");
                    mostrarNos(raiz);
                    printf("\n");
                }
                else printf("  Nó não encontrado!\n");
            }
            else{
                printf("  Árvore vazia!\n");
            }
            break;

        case 7:
            printf("\nESVAZIAR ÁRVORE\n");
            if(!arvoreVazia(raiz)){
                raiz = desalocar(raiz);
                printf("  Árvore esvaziada!\n");
            }
            else{
                printf("  Árvore vazia! \n");
            }
            break;

        case 0:
            printf("\n -> DESEJA SAIR DA APLICAÇÃO(1-SIM // 2-NÃO)? ");
            scanf("%d", &num);
            fflush(stdin);
            if(num == 1){
                printf("  Saindo da aplicação...\n");
                menu = 0;
            }
            break;

        default:
            printf("  OPÇÃO INVÁLIDA! \n");
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
