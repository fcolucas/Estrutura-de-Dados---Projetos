#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<locale.h>

#define VERDADEIRO 1
#define FALSO 0
#define Tamanho_Maximo 100

typedef struct{
    char* conteudo;
    int topo;
}Pilha;

void Push(Pilha* pilha, char item){
    if(pilha->topo == Tamanho_Maximo){
        printf("ERRO! Pilha esta cheia!");
        return;
    }
    pilha->topo++;
    pilha->conteudo[pilha -> topo - 1] = item;
}

char Pop(Pilha* pilha){
    if(pilha->topo <= 0){
        printf("ERRO! Pilha esta vazia!");
        return '\0';
    }
    return pilha->conteudo[pilha -> topo];
}

void MostrarPilha(Pilha* pilha){
    int i;
    for(i = 0; i < pilha->topo; i++){
        printf("%c",pilha->conteudo[i]);
    }
}

int ResolverExpressaoParcial(char* expressao){
    int num1,num2,i,j;
    int saida;
    char buffer[10],buffer2[10];
    char op;
    int negativo1 = FALSO, negativo2 = FALSO;
    i = 0;
    if(expressao[i] == '-'){
        negativo1 = VERDADEIRO;
        i++;
    }
    j = 0;
    while(isdigit(expressao[i])){
        buffer[j] = expressao[i];
        i++;
        j++;
    }
    num1 = atoi(buffer);
    if(negativo1){
        num1 = - num1;
    }
    op = expressao[i];
    i++;
    if(expressao[i] == '-'){
        negativo2 = VERDADEIRO;
        i++;
    }
    j = 0;
    while(isdigit(expressao[i])){
        buffer2[j] = expressao[i];
        i++;
        j++;
    }
    num2 = atoi(buffer2);
    if(negativo2){
        num2 = - num2;
    }
    if(op == '+'){
        saida = num1 + num2;
    }
    else if(op == '-'){
        saida = num1 - num2;
    }
    else if(op == '*'){
        saida = num1 * num2;
    }
    else{
        saida = num1 / num2;
    }
    return saida;
}

int ContarNumeros(char* expressao){
    int i = 0,qt_n = 0;
    while(expressao[i] != '\0'){
        if(isdigit(expressao[i])){
            while(isdigit(expressao[i])){
                i++;
            }
            qt_n++;
        }
        i++;
    }
    return qt_n;
}

int PosicaoPenultimoNumero(char* expressao){
    int n = ContarNumeros(expressao),qt = 0,i = 0;
    while(expressao[i] != '\0'){
        if(isdigit(expressao[i])){
            while(isdigit(expressao[i])){
                i++;
            }
            qt++;
            if(n - qt <= 2){
                return i;
            }
        }
        i++;
    }
}

int ResolverExpressaoCompletaSimples(char* expressao){
    printf("\nExpressão a ser resolvida: %s\n",expressao);
    int i,p_op = PosicaoPenultimoNumero(expressao);
    Pilha p;
    p.topo = 0;
    p.conteudo = (char*)malloc((strlen(expressao) - p_op) * sizeof(char));
    p.conteudo[(strlen(expressao) - p_op) - 1] = '\0';
    if(ContarNumeros(expressao) > 2){
        for(i = p_op + 1; i < strlen(expressao); i++){
            Push(&p,expressao[i]);
        }
        char saida_parcial[10];
        itoa(ResolverExpressaoParcial(p.conteudo),saida_parcial,10);
        char nova_expressao[32];
        for(i = 0; i <= p_op; i++){
            nova_expressao[i] = expressao[i];
        }
        nova_expressao[i] = '\0';
        strcat(nova_expressao,saida_parcial);
        nova_expressao[strlen(nova_expressao) + 1] = '\0';
        ResolverExpressaoCompletaSimples(nova_expressao);
    }
    else{
        return ResolverExpressaoParcial(expressao);
    }
}

int ExisteParenteses(char* expressao){
    int i = 0;
    while(expressao[i] != '\0'){
        if(expressao[i] == '('){
            return VERDADEIRO;
        }
        i++;
    }
    return FALSO;
}

char* EncontrarSubExpressao(char* expressao, int* inicio, int* fim){
    int i = 0,nao_encontrou_sub_expressao = VERDADEIRO;
    while(nao_encontrou_sub_expressao){
        if(expressao[i] == '('){
            *inicio = i;
        }
        if(expressao[i] == ')'){
            *fim = i;
            nao_encontrou_sub_expressao = FALSO;
        }
        i++;
    }
    char* saida = (char*)malloc((*fim - *inicio) * sizeof(char));
    saida[(*fim - *inicio) - 1] = '\0';
    int j = 0;
    for(i = (*inicio + 1); i < *fim; i++){
        saida[j] = expressao[i];
        j++;
    }
    return saida;
}

int ResolverExpressaoCompletaComposta(char* expressao){
    if(ExisteParenteses(expressao)){
        int inicio, fim,i,j;
        char* saida_parcial = EncontrarSubExpressao(expressao,&inicio,&fim);//Expressão entre parenteses
        int saida_parcial_resolvida = ResolverExpressaoCompletaSimples(saida_parcial); //Resultado da expressão
        char* nova_expressao_parcial;
        int tamanho = ((int)log10(abs(saida_parcial_resolvida)) + 2);
        if(saida_parcial_resolvida < 0){
            tamanho++;
        }
        nova_expressao_parcial = (char*)malloc(tamanho * sizeof(char));
        nova_expressao_parcial[tamanho - 1] = '\0';
        itoa(saida_parcial_resolvida,nova_expressao_parcial,10); //Converte int em string
        char* nova_expressao;
        tamanho = strlen(expressao) - (strlen(saida_parcial) + 2) + strlen(nova_expressao_parcial) + 1;
        nova_expressao = (char*)malloc(tamanho * sizeof(char));
        for(i = 0; i < inicio; i++){
            nova_expressao[i] = expressao[i];
        }
        nova_expressao[i] = '\0';
        strcat(nova_expressao,nova_expressao_parcial); //Concatenação
        j = strlen(nova_expressao);
        for(i = fim + 1; i < strlen(expressao); i++){
            nova_expressao[j] = expressao[i];
            j++;
        }
        nova_expressao[j] = '\0';
        free(nova_expressao_parcial);
        ResolverExpressaoCompletaComposta(nova_expressao);
    }
    else{
        return ResolverExpressaoCompletaSimples(expressao);
    }
}

int main(int narg, char* argv[]){
    setlocale(LC_ALL, "Portuguese");
    int i;
    char buffer[32];
    Pilha pilha;
    pilha.topo = 0;

    printf("\n ---- CALCULADORA DE EXPRESSÕES NUMÉRICAS ---- \n");
    printf("Digite a expressão: ");
    fflush(stdin);
    fgets(buffer,32,stdin);
    if(buffer[strlen(buffer) - 1] == '\n'){
        buffer[strlen(buffer) - 1] = '\0';
    }
    pilha.conteudo = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    pilha.conteudo[strlen(buffer)] = '\0';
    for(i = 0; i < strlen(buffer); i++){
        Push(&pilha,buffer[i]);
    }
    printf("\nResultado: %d\n",ResolverExpressaoCompletaComposta(pilha.conteudo));
    free(pilha.conteudo);
    return 0;
}
