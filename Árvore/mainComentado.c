#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    char op, op2, op3;
    int num;
    arvore* t;

    while(1){
        printf("\n********************************\n");
        printf("*        %cRVORE BIN%cRIA        *\n",181,181);
        printf("********************************\n");

    	op = menu_principal();
    	printf("\n\n");

        if(op == '0') {
            break;
        }

        switch(op)
        {
            /*Criar Árvore*/
            case '1':
            	system("cls");
            	printf("\n  %crvore criada com sucesso!\n",181);
            	t = criaArvore();
            	break;

            /*Inserir na Árvore*/
            case '2':
                printf("  Digite um n%cmero: ",163);
                scanf("%i",&num);
                fflush(stdin);

				system("cls");
				printf("\n  N%cmero %i inserido na %crvore\n",163,num,160);
                insereDadoArvore(&t, num);
                break;

            /*Listar Árvore*/
            case '3':

			    while(1){

			        printf("\n********************************\n");
			        printf("*        LISTAR %CRVORE        *\n",181);
			        printf("********************************\n");

			    	op2 = sub_menuPrint();
			    	printf("\n\n");

			        if(op2 == '0') {
			        	system("cls");
			            break;
			        }

			        switch(op2){
						case '1':
							system("cls");
							printf("\n  %cRVORE EM ORDEM:\n",181);
							exibirEmOrdem(t);
							printf("\n");
							break;

						case '2':
							system("cls");
							printf("\n  %cRVORE EM PR%c ORDEM:\n",181,144);
							exibirPreOrdem(t);
							printf("\n");
							break;

						case '3':
							system("cls");
							printf("\n  %cRVORE EM P%cS ORDEM:\n",181,224);
							exibirPosOrdem(t);
							printf("\n");
							break;

						default:
						    system("cls");
                			printf("\n  Opcao Invalida\n");
					}
				}
				break;

            /*Excluir itens da árvore*/
            case '4':

			    while(1){

			        printf("\n********************************\n");
			        printf("*        EXCLUIR %CRVORE        *\n",181);
			        printf("********************************\n");

			    	op3 = sub_menuDelete();
			    	printf("\n\n");

			        if(op3 == '0') {
			        	system("cls");
			            break;
			        }

			        switch(op3){
						case '1':

                            printf("  Digite um n%cmero: ",163);
                            scanf("%i",&num);
                            fflush(stdin);

                            system("cls");
                            remover(&t, num);
							break;

						case '2':

							system("cls");
							MaiorDireita(&t);
							break;

						case '3':
							system("cls");
                            MenorEsquerda(&t);
							break;

						default:
						    system("cls");
                			printf("\n  Opcao Invalida\n");
					}
				}

				break;

            /*Buscar número*/
            case '5':

                printf("  Digite um n%cmero: ",163);
                scanf("%i",&num);
                fflush(stdin);

				system("cls");
                if(estaNaArvore(t, num)){
                    printf("\n  O elemento %i pertence a %crvore!\n",num, 160);
                }else{
                    printf("\n  O elemento %i n%co pertence a %crvore!\n",num, 198, 160);
                }
                break;

            /*Quantidade de nós*/
            case '6':
				system("cls");
                printf("\n  Quantidade de n%cs: %d\n",162,contarNos(&t));
                break;

            /*Quantidade de folhas*/
            case '7':
        		system("cls");
                printf("\n  Quantidade de folhas: %d\n", contarFolhas(&t));
                break;

            /*Altura*/
            case '8':
				system("cls");
                printf("\n  Altura: %d\n", altura(t));
                break;

            /*Apaga Árvore*/
			case '9':
				system("cls");
                apagaArvore(t);
                printf("\n  %crvore deletada\n ", 181);
                t = criaArvore();
                break;

            default:
                system("cls");
                printf("\n  Opcao Invalida\n");
        }
    }

    free(t);

    return 0;
}
