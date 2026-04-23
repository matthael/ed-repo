#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAM 100

// Função para copiar vetor
void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int v_original[TAM];
    int v[TAM];

    srand(time(NULL));

    // Gerar números aleatórios
    for (int i = 0; i < TAM; i++) {
        v_original[i] = rand() % 1000;
    }

    clock_t inicio, fim;

    // 🔹 Bubble Sort
    copiar_vetor(v_original, v, TAM);
    inicio = clock();
    bubble_sort(v, TAM);
    fim = clock();
    printf("Bubble Sort: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    // 🔹 Selection Sort
    copiar_vetor(v_original, v, TAM);
    inicio = clock();
    selection_sort(v, TAM);
    fim = clock();
    printf("Selection Sort: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    // 🔹 Quick Sort
    copiar_vetor(v_original, v, TAM);
    inicio = clock();
    quick_sort(v, 0, TAM - 1);
    fim = clock();
    printf("Quick Sort: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}