#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10000000

void bubbleSort(int v[], int tam);
void preencherVetor(int v[], int tam);
void imprimirVetor(int v[], int tam);

int main() {
    clock_t inicio, fim;
    double tempo;
    int *numeros = (int *) malloc(TAM * sizeof(int));
    srand(23);

    if (numeros == NULL) {
        printf("Falha na alocação da memoria!\n");
        return 1;
    }

    preencherVetor(numeros, TAM);

    inicio = clock();
    bubbleSort(numeros, TAM);
    fim = clock();
    tempo = ((double)(fim-inicio) / CLOCKS_PER_SEC) * 1000;

    printf("Tempo de execução: %f ms\n", tempo);

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
            }
        }
        if(!trocou) {
            break;
        }
    }
}

void preencherVetor(int v[], int tam) {
    for(int i = 0; i < TAM; ++i) {
        v[i] = i*3;
    }
}

void imprimirVetor(int v[], int tam) {
    for(int i = 0; i < TAM; ++i) {
        printf("%d ", v[i]);
    }
}