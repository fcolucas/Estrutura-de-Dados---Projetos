#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Grafo.h"

int main(){
    char op, op1, op2, op3, op4, op5;
    int num, vi, vf, i, d, p, excluido, ndfs, nbfs, nd;
    int *r;
    Grafo *gr;
    GRAFOP *grp;

    while(1)
    {
        //PRIMEIRO MENU CRIAR COM PESO E SEM PESO
        printf("\n********************************\n");
        printf("*             GRAFO            *\n");
        printf("********************************\n");

        op = menu_principal();
        printf("\n\n");

        if(op == '0')
        {
            break;
        }

        switch(op)
        {

        case '1':

            while(1)   //GRAFO SEM PESO
            {
                printf("\n********************************\n");
                printf("*     GRAFO SEM PESO            *\n");
                printf("********************************\n");

                op1 = sub_menuSP();
                printf("\n\n");

                if(op1 == '0')
                {
                    break;
                }

                switch(op1)
                {

                case '1':
                    system("cls");
                    printf("\n  Digite o tamanho do grafo: ");

                    scanf("%i", &num);
                    gr = criaGrafo(num);
                    fflush(stdin);

                    printf("\n  Grafo criado com sucesso!\n");

                    //gr = criaGrafo(6);

                    break;

                case '2':
                    system("cls");
                    printf("\n  Digite o v%crtice inicial: ", 130);
                    scanf("%i",&vi);
                    fflush(stdin);

                    printf("\n  Digite o v%crtice final: ", 130);
                    scanf("%i",&vf);
                    fflush(stdin);

                    addAresta(gr, vi, vf);
                    /*addAresta(gr, 0, 1);
                    addAresta(gr, 0, 2);
                    addAresta(gr, 1, 2);
                    addAresta(gr, 1, 4);
                    addAresta(gr, 1, 3);
                    addAresta(gr, 2, 4);*/

                    break;

                case '3':
                    system("cls");

                    imprime(gr);

                    break;

                case '4':
                    system("cls");

                    printf("\n  Digite o v%crtice para buscar: ", 130);
                    scanf("%i",&ndfs);
                    fflush(stdin);


                    DFS(gr, ndfs);

                    break;

                case '5':
                    system("cls");

                    printf("\n  Digite o v%crtice para buscar: ", 130);
                    scanf("%i",&nbfs);
                    fflush(stdin);

                    BFS(gr, nbfs);

                    break;

                case '6':

                    system("cls");
                    excluiGrafo(gr);

                    while(1)
                    {

                        op4 = sub_menuExcluir();
                        printf("\n\n");

                        if(op4 == '0')
                        {
                            system("cls");
                            break;
                        }

                        switch(op4)
                        {

                        case '1':
                            system("cls");

                            printf("\n  Digite o tamanho do grafo: ");

                            scanf("%i", &num);
                            gr = criaGrafo(num);
                            fflush(stdin);

                            printf("\n  Grafo criado com sucesso!\n");

                            break;
                        default:
                            system("cls");
                            printf("\n  Opcao Invalida\n");
                        }

                    }
                    break;

                default:
                    system("cls");
                    printf("\n  Opcao Invalida\n");
                }
            }
            break;

        case '2':
            while(1)  //SEGUNDO MENU DE CRIAR GRAFO
            {
                printf("\n********************************\n");
                printf("*     GRAFO COM PESO            *\n");
                printf("********************************\n");

                op3 = sub_menuCP();
                printf("\n\n");

                if(op3 == '0')
                {
                    break;
                }

                switch(op3)
                {
                case '1':

                    system("cls");
                    printf("\n  Digite o tamanho do grafo: ");

                    scanf("%i", &num);
                    grp = criaGrafoP(num);
                    fflush(stdin);

                    printf("\n  Grafo criado com sucesso!\n");

                    //grp = criaGrafoP(6);

                    break;

                case '2':
                    system("cls");
                    printf("\n  Digite o v%crtice inicial: ", 130);
                    scanf("%i",&vi);
                    fflush(stdin);

                    printf("\n  Digite o v%crtice final: ", 130);
                    scanf("%i",&vf);
                    fflush(stdin);

                    printf("\n  Digite o peso: ");
                    scanf("%i",&p);
                    fflush(stdin);

                    criaArestaP(grp, vi, vf, p);

                    break;

                case '3':
                    system("cls");
                    imprimeP(grp);

                    break;

                case '4':
                    system("cls");
                    /*Dijkstra*/

                    printf("\n  Digite o v%crtice para buscar: ", 130);
                    scanf("%i",&nd);
                    fflush(stdin);

                    r = dijkstra(grp, nd);

                    for(i = 0; i<grp->vertices; i++){
                        printf("  D(v%d -> v%d) = %d\n", nd, i, r[i]);
                    }

                    break;

                default:
                    system("cls");
                    printf("\n  Opcao Invalida\n");

                }
            }
            break;
        default:
            system("cls");
            printf("\n  Opcao Invalida\n");
        }
    }
    free(r);
    free(gr);
    free(grp);

    return 0;
}
