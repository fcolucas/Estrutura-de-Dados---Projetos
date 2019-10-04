struct st_arvore{
    int valor;
    struct st_arvore *direita; //sub-árvore direita
    struct st_arvore *esquerda; //sub-árvore esquerda
};

typedef struct st_arvore arvore;

arvore* criaArvore(){
    return NULL;
}

int arvoreEstaVazia(arvore* t){
    return t == NULL;
}

void insereDadoArvore(arvore** t, int num){
    if(*t == NULL){
        *t = (arvore*)malloc(sizeof(arvore));
        (*t)->esquerda = NULL;
        (*t)->direita = NULL;
        (*t)->valor = num;
    }else{
        if(num < (*t)->valor){
            insereDadoArvore(&(*t)->esquerda, num);
        }
        if(num > (*t)-> valor){
            insereDadoArvore(&(*t)->direita, num);
        }
    }
}

int estaNaArvore(arvore* t, int num){
    if(arvoreEstaVazia(t)){
        return 0;
    }
    return t->valor==num || estaNaArvore(t->esquerda, num) || estaNaArvore(t->direita, num);
}

void exibirEmOrdem(arvore *t){
	if(t != NULL){
            exibirEmOrdem(t->esquerda);
            printf("\n  %i", t->valor);
            exibirEmOrdem(t->direita);
	}
}

void exibirPreOrdem(arvore *t){
    if(t != NULL){
        printf("\n  %i", t->valor);
        exibirPreOrdem(t->esquerda);
        exibirPreOrdem(t->direita);
    }
}

void exibirPosOrdem(arvore *t){
    if(t != NULL){
        exibirPosOrdem(t->esquerda);
        exibirPosOrdem(t->direita);
        printf("\n  %i", t->valor);
    }
}

char menu_principal()
{
    printf("  1 - Criar %crvore\n",160);
    printf("  2 - Inserir na %crvore\n",160);
    printf("  3 - Listar %crvore\n",160);
    printf("  4 - Excluir itens da %crvore\n",160);
    printf("  5 - Pesquisar na %crvore\n",160);
    printf("  6 - Contar n%cs\n", 162);
    printf("  7 - Contar folhas\n");
    printf("  8 - Altura da %crvore\n", 160);
    printf("  9 - Esvaziar %crvore\n",160);
    printf("  0 - Sair do aplicativo\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();
}

char sub_menuPrint ()
{
    printf("  1 - Listar em ordem\n");
    printf("  2 - Listar em pr%c ordem\n",130);
    printf("  3 - Listar em p%cs ordem\n",162);
    printf("  0 - Voltar ao menu\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();
}

char sub_menuDelete (){

    printf("  1 - Excluir item da %crvore\n", 160);
    printf("  2 - Excluir maior n%c da direita\n",162);
    printf("  3 - Excluir menor n%c da esquerda\n",162);
    printf("  0 - Voltar ao menu\n\n");
    printf("  ESCOLHA UM OP%c%cO: ",128,199);
    return getche();

}

arvore* MaiorDireita(arvore** no)
{

    if((*no)->direita != NULL)
        return MaiorDireita(&(*no)->direita);
    else
    {
        arvore *aux = *no;
        if((*no)->esquerda != NULL)
            *no = (*no)->esquerda;
        else
            *no = NULL;

        printf("\n  N%cmero %i excluido\n", 163, *aux);
        return aux;
    }
}

arvore* MenorEsquerda(arvore** no)
{
    if((*no)->esquerda != NULL)
        return MenorEsquerda(&(*no)->esquerda);
    else
    {
        arvore *aux = *no;
        if((*no)->direita != NULL)
            *no = (*no)->direita;
        else
            *no = NULL;
        printf("\n  N%cmero %i excluido\n", 163, *aux);
        return aux;
    }
}

void remover(arvore** t, int valor){

    if(*t == NULL)
    {
        printf("\n  N%cmero n%co existe na %crvore!\n", 163, 198,160);
        getch();
        return;
    }

    if(valor < (*t)->valor)
        remover(&(*t)->esquerda, valor);
    else
        if(valor > (*t)->valor)
            remover(&(*t)->direita, valor);
        else
        {
            arvore *aux = *t;
            if (((*t)->esquerda == NULL) && ((*t)->direita == NULL))
            {
                free(aux);
                (*t) = NULL;
            }
            else
            {
                if ((*t)->esquerda == NULL)
                {
                    (*t) = (*t)->direita;
                    aux->direita = NULL;
                    free(aux);
                    aux = NULL;
                }
                else
                {
                    if ((*t)->direita == NULL)
                    {
                        (*t) = (*t)->esquerda;
                        aux->esquerda = NULL;
                        free(aux);
                        aux = NULL;
                    }
                    else
                    {
                        aux = MaiorDireita(&(*t)->esquerda);
                        aux->esquerda = (*t)->esquerda;
                        aux->direita = (*t)->direita;
                        (*t)->esquerda = (*t)->direita = NULL;
                        free((*t));
                        *t = aux;
                        aux = NULL;
                    }
                }
            }
        }
}

int contarNos(arvore **t){
    if((*t) == NULL)
        return 0;
    else
        return 1 + contarNos(&(*t)->esquerda) + contarNos(&(*t)->direita);
}

int contarFolhas(arvore **t){
    if((*t) == NULL)
        return 0;
    if((*t)->esquerda == NULL && (*t)->direita == NULL)
        return 1;
    return contarFolhas(&(*t)->esquerda) + contarFolhas(&(*t)->direita);
}

int altura(arvore* t)
{
    if (t == NULL)
        return 0;
    else
    {

        int eAltura = altura(t->esquerda);
        int dAltura = altura(t->direita);

        if (eAltura > dAltura)
            return(eAltura + 1);
        else return(dAltura + 1);
    }
}

void apagaArvore (struct st_arvore *t){
    if (t == NULL)
        return;
    apagaArvore(t->esquerda);
    apagaArvore(t->direita);
    printf("\n  Excluindo o n%c: %d", 162, t->valor);
    free(t);
}
