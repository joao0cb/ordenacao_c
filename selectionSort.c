#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 250000

void selectionSort(int v[], int tam);
void preencherVetorAleatorio(int v[], int tam);
void preencherVetorCrescente(int v[], int tam);
void preencherVetorDecrescente(int v[], int tam);


int main() {
    clock_t inicio, fim;
    double tempo;
    int *numeros = (int *) malloc(TAM * sizeof(int));
    srand(22);

    if (numeros == NULL) {
        printf("Falha na alocação da memoria!\n");
        return 1;
    }

    preencherVetorAleatorio(numeros, TAM);
    inicio = clock();
    selectionSort(numeros, TAM);
    fim = clock();
    tempo = ((double)(fim-inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR TODO DESORDENADO\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    preencherVetorCrescente(numeros, TAM);
    inicio = clock();
    selectionSort(numeros, TAM);
    fim = clock();
    tempo = ((double)(fim-inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR ORDENADO (ORDEM CRESCENTE)\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    preencherVetorDecrescente(numeros, TAM);
    inicio = clock();
    selectionSort(numeros, TAM);
    fim = clock();
    tempo = ((double)(fim-inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR ORDENADO (ORDEM DECRESCENTE)\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    free(numeros);
    return 0;
}

void selectionSort(int v[], int tam) {
    for(int i = 0; i < tam-1; ++i) {
        int menor = i;
        for(int j = i+1; j < tam; ++j) {
            if(v[j] < v[menor]) {
                menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void preencherVetorAleatorio(int v[], int tam) {
    for(int i = 0; i < tam; ++i) {
        v[i] = rand() % 100;
    }
}

void preencherVetorCrescente(int v[], int tam) {
    for(int i = 0; i < tam; ++i) {
        v[i] = i;
    }
}

void preencherVetorDecrescente(int v[], int tam) {
    for(int i = 0; i < tam ; ++i) {
        v[i] = tam-i;
    }
}