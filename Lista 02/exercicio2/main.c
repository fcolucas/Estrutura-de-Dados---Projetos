#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // para função setlocale

struct rgFuncionarios{
    char nome[35];
    char sexo;
    int qt_pecas;
};

void reg_funcionario(struct rgFuncionarios *fun, int len){
    int i=0;
    for(i=0; i<len; i++){
        printf("Funcionário %d: \n", i+1);
        printf("Nome: ");
        gets(fun[i].nome);

        printf("Sexo(M - masculino ou F - feminino): ");
        scanf("%s", &fun[i].sexo);

        printf("Qtde de peças produzidas: ");
        scanf("%d", &fun[i].qt_pecas);

        printf("\n");
        fflush(stdin);
    }
}

int pecas_sexo(struct rgFuncionarios *fun, int len, int sexo){
    int i=0, tpecas=0;
    for(i=0; i<len; i++){
        if(fun[i].sexo==sexo) tpecas+=fun[i].qt_pecas;
    }
    return tpecas;
}

char* funcionario_mes(struct rgFuncionarios *fun, int len){
    int i=0, j=0;
    for(i=0; i<len; i++){
        if(fun[i].qt_pecas>fun[j].qt_pecas) {
                i=j;
        }
    }
    return fun[j].nome;
}

int main()
{
    setlocale(LC_ALL, "");

    int f=6;
    struct rgFuncionarios Funcionarios[f];

    printf("-----REGISTRO DE FUNCIONÁRIOS------\n");
    reg_funcionario(Funcionarios, f);

    printf("Quantidade de peças produzidas por homens: %d\n", pecas_sexo(Funcionarios, f, 'M'));
    printf("Quantidade de peças produzidas por mulheres: %d\n", pecas_sexo(Funcionarios, f, 'F'));

    printf("Funcionário do mês: %s \n", funcionario_mes(Funcionarios, f));

    return 0;
}
