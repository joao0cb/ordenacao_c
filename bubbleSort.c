#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 250000

void bubbleSort(int v[], int tam);
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
    bubbleSort(numeros, TAM);
    fim = clock();
    tempo = ((double)(fim-inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR TODO DESORDENADO\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    preencherVetorCrescente(numeros, TAM);
    inicio = clock();
    bubbleSort(numeros, TAM);
    fim = clock();
    tempo = ((double)(fim-inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR ORDENADO (ORDEM CRESCENTE)\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    preencherVetorDecrescente(numeros, TAM);
    inicio = clock();
    bubbleSort(numeros, TAM);
    fim = clock();
    tempo = ((double)(fim-inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR ORDENADO (ORDEM DECRESCENTE)\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    free(numeros);
    return 0;
}

void bubbleSort(int v[], int tam) {
    for(int r = 1; r <= tam-1; ++r) {
        int trocou = 0;
        for(int i = 0; i < tam-1-r; ++i) {
            if(v[i] > v[i+1]) {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                trocou = 1;
            }
        }
        if(!trocou) {
            break;
        }
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