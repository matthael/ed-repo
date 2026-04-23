#include <stdio.h>
#include <time.h>
#include "ordenacao.h"

#define TAMANHO 1000;

int main() {
    int vetor[TAMANHO] = {64, 34, 25, 12, 22, 11, 90, 0, -5, 3};

    for(int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 10000; // Preenche o vetor com números aleatórios
    }

    printf("Vetor original: \n");
    imprimeVetor(vetor, TAMANHO);

    clock_t start = clock();
    bubbleSort(vetor, TAMANHO);
    clock_t end = clock();
    float time_taken = (float)(end - start) / CLOCKS_PER_SEC;

    printf("Vetor ordenado: \n");
    imprimeVetor(vetor, TAMANHO);
    printf("Tempo de execucao: %f segundos\n", time_taken);
    return 0;
}