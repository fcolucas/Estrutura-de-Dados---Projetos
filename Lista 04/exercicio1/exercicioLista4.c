#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAM 10

int *cria_vetor(int *vet, int n){
    int i=0;
    for(i=0; i<n; i++){
        vet[i] = rand()%100;
    }
    return vet;
}

void mostra_vetor(int *vet, int n){
    int i;
    printf("{ ");
    for(i=0; i<n; i++){
        printf("%d ", vet[i]);
    }
    printf("}\n");
}

void bubbleSort (int *vet, int n){
    int i, j, aux, contador=0;
    for(i=1; i<n; i++){
        for(j=0; j<n-i; j++){
            if(vet[j]>vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                contador++;
            }
        }
    }
    printf("Qnte de trocas: %d \n", contador);
}

void insertionSort(int *vet, int n){
    int i, j, aux;
    for(i=1; i<n; i++){
        aux = vet[i];
        j = i - 1;
        while(j>=0 && aux < vet[j]){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1]=aux;
    }
}

void selectionSort(int *vet, int n){
    int i, j, min, aux, contador=0;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(vet[j] < vet[min]){
                min = j;
                contador++;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
    printf("Qnte de trocas: %d \n", contador);
}

void quickSort(int *vet, int inicio, int fim){

   int pivo, aux, i = inicio, j = fim, meio;

   meio = (i + j) / 2;
   pivo = vet[meio];

   do{
      while (vet[i] < pivo) i = i + 1;
      while (vet[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vet[i];
         vet[i] = vet[j];
         vet[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) quickSort(vet, inicio, j);
   if(i < fim) quickSort(vet, i, fim);
}

int main()
{
    setlocale(LC_ALL,"");
    int menu=1, op, vet[TAM];
    float time;
    time_t start, finish;
    cria_vetor(vet, TAM);

    do{
        printf(" ---- ORDENAÇÃO ----\n");
        printf("1- Bubble Sort \n");
        printf("2- Insertion Sort \n");
        printf("3- Selection Sort \n");
        printf("4- Quick Sort \n");
        printf("0- Sair \n");
        printf("Digite o método de ordenação (ou 0 para sair): ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
        case 1: //Bubble Sort
            printf("\n **** BUBBLE SORT **** \n");
            cria_vetor(vet, TAM);
            printf("Vetor original: "); mostra_vetor(vet, TAM);
            start = clock();
            bubbleSort(vet, TAM);
            finish = clock();
            printf("Vetor ordenado: "); mostra_vetor(vet, TAM);
            time = (difftime(finish, start)/CLOCKS_PER_SEC);
            printf("Tempo de execução: %.3f s \n\n", time);
            break;
        case 2: //Insertion Sort
            printf("\n **** INSERTION SORT **** \n");
            cria_vetor(vet, TAM);
            printf("Vetor original: "); mostra_vetor(vet, TAM);
            insertionSort(vet, TAM);
            printf("Vetor ordenado: "); mostra_vetor(vet, TAM);
            printf("\n ");
            break;
        case 3: //Selectiop Sort
            printf("\n **** SELECTION SORT **** \n");
            cria_vetor(vet, TAM);
            printf("Vetor original: "); mostra_vetor(vet, TAM);
            start = clock();
            selectionSort(vet, TAM);
            finish = clock();
            printf("Vetor ordenado: "); mostra_vetor(vet, TAM);
            time = (difftime(finish, start)/CLOCKS_PER_SEC);
            printf("Tempo de execução: %.4f s \n\n", time);
            break;
        case 4: //Quick Sort
            printf("\n **** QUICK SORT **** \n");
            cria_vetor(vet, TAM);
            printf("Vetor original: "); mostra_vetor(vet, TAM);
            quickSort(vet, 0, TAM-1);
            printf("Vetor ordenado: "); mostra_vetor(vet, TAM);
            printf("\n");
            break;
        case 0:
            printf(" \n--> Saindo da aplicação...\n");
            menu = 0;
            break;
        default:
            printf("Operação inválida");
            break;
        }
    }while(menu);
    return 0;
}
