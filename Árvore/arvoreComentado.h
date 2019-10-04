/* Árvore Binária - Binary Tree
 *
 * São estruturas de dados caracterizadas por:
 * ou, não tem elemento algum (árvore vazia).
 *
 * ou tem um elemento distinto, denominado raiz,
 * com dois apontamentos para duas estruturas diferentes,
 * denominadas sub-árove esquerda e sub-árvore direita.
 *
 * existe uma regra para adicionar valores na árvore,
 * se o valor novo for menor do que já existe na árvore é
 * criado um apontamento a esquerda caso contrário é criado
 * a direita.
 */

struct st_arvore{
    int valor;
    struct st_arvore *direita; //sub-árvore direita
    struct st_arvore *esquerda; //sub-árvore esquerda
};

typedef struct st_arvore arvore;

/*Na criação da árvore retorna um ponteiro nulo*/

arvore* criaArvore(){
    return NULL;
}

/*Verifica se a árvore está vazia retornando nulo*/
int arvoreEstaVazia(arvore* t){
    return t == NULL;
}

void insereDadoArvore(arvore** t, int num){
    if(*t == NULL){// sendo nula ela não existe ainda
        *t = (arvore*)malloc(sizeof(arvore));
        (*t)->esquerda = NULL;// acessa o valor e aponta esquerda pra NULL
        (*t)->direita = NULL;
        (*t)->valor = num;// árvore recebe um valor
    }else{// se a árvore já tiver valores, seus galhos estarão vazios e adicionaremos os valores nos galhos
        if(num < (*t)->valor){
            insereDadoArvore(&(*t)->esquerda, num);
        }
        if(num > (*t)-> valor){
            insereDadoArvore(&(*t)->direita, num);
        }
    }
}

int estaNaArvore(arvore* t, int num){ // busca em árvore binária
    if(arvoreEstaVazia(t)){
        return 0;
    }
    return t->valor==num || estaNaArvore(t->esquerda, num) || estaNaArvore(t->direita, num);
    //esse return verifica pros dois ramos da árvore se existe o valor.
}

/*--- O em ordem, busca o último à esquerda, depois volta até o nó onde ele terá
que ir à direita. Após isso ele busca o último à esquerda e volta....---*/
void exibirEmOrdem(arvore *pRaiz){//recebe o nó raiz, de novo aquela confusão com o nome da variável
	if(pRaiz != NULL){//verifica se o nó atual existe, pois ao ser chamado pRaiz->direita ou pRaiz->esquerda, sabemos que poderão ser nulos
            exibirEmOrdem(pRaiz->esquerda);//chamada recursiva para o próximo à esquerda, e será chamado até o último à esquerda.
            printf("\n%i", pRaiz->valor);//Ao chegar no último à esquerda, ou seja, for pRaiz->esquerda for NULL, ele começa a printar, e vai printando todos os nós por onde ele passou, "voltando"
            exibirEmOrdem(pRaiz->direita);//é chamado o nó a direita, seguindo o fluxo
	}
}

void exibirPreOrdem(arvore *pRaiz){//Pré-Ordem é mais simples, no nó que ele tá, ele já printa. Começa pela raiz e vai printando até o último a esquerda, depois volta pro nó onde ele terá que ir até a esquerda e volta denovo a buscar o último a esquerda e segue o fluxo.
    if(pRaiz != NULL){//mesmo teste anterior
        printf("\n%i", pRaiz->valor);//assim que está no nó, já faz o print
        exibirPreOrdem(pRaiz->esquerda);//faz a chamada recursiva pro nó a esquerda, perceba que o pRaiz->direita só é chamado quando passa por todos os nós a esquerda
        exibirPreOrdem(pRaiz->direita);//chamada recursiva para nó à direita
    }
}

void exibirPosOrdem(arvore *pRaiz){//Pós-ordem é o que eu acho mais complicado, mas não impossível de entender. A ideia basicamente é passar por toda a árvore, e só depois vir fazendo os prints. Ele busca o último a esquerda, depois volta pro nó que tiver que voltar e vai pra direita, sem printar nada, e busca de novo o último a esquerda, ate varrer toda a árvore, depois ele vai printando tudo
    if(pRaiz != NULL){
        exibirPosOrdem(pRaiz->esquerda);
        exibirPosOrdem(pRaiz->direita);
        printf("\n%i", pRaiz->valor);
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

char sub_menu()
{
    printf("  1 - Listar em ordem\n",160);
    printf("  2 - Listar em pre ordem\n",160);
    printf("  3 - Listar em pos ordem\n",160);
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

arvore* MaiorDireita(arvore** no) //Essas duas funções, *MaiorDireita e *MenorEsquerda são duas funções auxiliares. Vão ser usadas na hora de remover um Nó que tenha filhos a direita e a esquerda
{
//essa função vai ser usada pra, como o próprio nome já diz, buscar o Maior nó a direita
//Recebe um arvore** no que será o nó a ser removido, a partir dai ele busca o maior à direita
    if((*no)->direita != NULL)//caso seja diferente de null, ou seja, existe algum nó à direita, ele chama recursivamente o próximo nó à direita
        return MaiorDireita(&(*no)->direita);
    else //caso contrário, esse é o maior nó a direita.
    {
        arvore *aux = *no;//faz um backup do nó, pois ele irá excluir esse nó, e irá adicioná-lo em outro lugar
        if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
            *no = (*no)->esquerda;
        else
            *no = NULL;
 	printf("\n  N%cmero %i excluido\n", 163, *aux);
    	return aux;
    }
}

arvore* MenorEsquerda(arvore** no) //Essa função tem a mesma característica da anterior. Dependendo da sua abordagem, você pode usar uma ou outra. Se a sua abordagem é de pegar o Menor à esquerda, use essa função, caso contrário, utilize a anterior.
{
    if((*no)->esquerda != NULL)
        return MenorEsquerda(&(*no)->esquerda);
    else
    {
        arvore *aux = *no;
        if((*no)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
            *no = (*no)->direita;
        else
            *no = NULL;
        printf("\n  N%cmero %i excluido\n", 163, *aux);
    	return aux;
    }
}

void remover(arvore** t, int valor){ //Mais uma vez aquela confusão do **pRaiz, mas já está ciente do problema. A função recebe o nó raiz, e um número a ser removido. Irá fazer uma busca de onde está esse número e depois executa a lógica de remoção.

    if(*t == NULL)    // esta verificacao serve para caso o numero nao exista na arvore.
    {
        printf("Numero nao existe na arvore!");
        getch();
        return;
    }

    if(valor < (*t)->valor)//verifica se o número é menor que o número do Nó atual, na busca.
        remover(&(*t)->esquerda, valor);//chamada recursiva para caso seja menor
    else//caso contrário, ele será o número ou será maior
        if(valor > (*t)->valor)//verifica se o número é maior que o número do Nó atual, na busca.
            remover(&(*t)->direita, valor);//chamada recursiva para caso seja maior
        else     // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
        {
            arvore *aux = *t;     // faz um backup do Nó a ser removido
            if (((*t)->esquerda == NULL) && ((*t)->direita == NULL)) // verifica se não tem filho nem a direita, nem a esquerda, ou seja, não tem filhos.
            {
                free(aux);//Nesse Caso, é bem simples, é só desalocar, liberar esse nó da memória
                (*t) = NULL;
            }
            else      // so tem o filho da direita
            {
                if ((*t)->esquerda == NULL) //Verifica se não tem filho a esquerda, caracterizando como tendo filhos somente a direita.
                {
                    (*t) = (*t)->direita;//o Nó atual, recebe o seu filho a direta, fazendo com que ele desapareça e o seu próximo filho substitua o seu lugar
                    aux->direita = NULL;//o backup se faz necessário para isso, para você cortar essa ligação, caso contrário, teria um nó em memória que teriam os antigos filhos
                    free(aux);
                    aux = NULL;// e também para poder liberá-lo da memória depois
                }
                else             //so tem filho da esquerda
                {
                    if ((*t)->direita == NULL) //MESMO CASO ANTERIOR, só que nesse caso, só existem filhos a esquerda.
                    {
                        (*t) = (*t)->esquerda;
                        aux->esquerda = NULL;
                        free(aux);
                        aux = NULL;
                    }
                    else //Quando existe filhos a direita e a esquerda. Escolhi fazer o maior filho direito da subarvore esquerda.
                    {
                        aux = MaiorDireita(&(*t)->esquerda); //Faz um backup do Maior a direita, pois ele usará o maior a direita no local do Nó a ser removido. Se vc quiser usar o Menor da esquerda, so o que mudaria seria isso: aux = MenorEsquerda(&(*t)->direita);
                        aux->esquerda = (*t)->esquerda;          //o Nó(Maior a Direita) irá receber os filhos a esquerda do Nó que será removido
                        aux->direita = (*t)->direita;//o Nó(Maior a Direita) irá receber os filhos a direita do Nó que será removido
                        (*t)->esquerda = (*t)->direita = NULL;//O Nó que será removido, perde seus filhos, ou seja, recebe NULL
                        free((*t));
                        *t = aux;
                        aux = NULL;   //Enfim, libera-se da memória o nó a ser removido
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

/* Folha é um nó que não tem filho algum */
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
        /* Recebe altura de cada sub-arvore */
        int eAltura = altura(t->esquerda);
        int dAltura = altura(t->direita);

        /* Usa a altura maior pra dizer o tamanho da árvore */
        if (eAltura > dAltura)
            return(eAltura + 1);
        else return(dAltura + 1);
    }
}

void apagaArvore (struct st_arvore *t){
    if (t == NULL)
        return;

    /* primeiro deleta as duas sub-arvores */
    apagaArvore(t->esquerda);
    apagaArvore(t->direita);

    /* depois deleta o nó */
    printf("\n Excluindo o n%c: %d", 162, t->valor);
    free(t);
}

