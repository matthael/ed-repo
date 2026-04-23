#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAM 100

int main() {
    int v[TAM];
    int chave;
    clock_t inicio, fim;
    double tempo;

    // Gerar números aleatórios
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }

    // Escolher uma chave aleatória do vetor
    chave = v[rand() % TAM];

    // =========================
    // TESTE BUSCA LINEAR
    // =========================
    inicio = clock();
    int pos = linear_search(v, TAM, chave);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Busca Linear:\n");
    printf("Chave: %d | Posicao: %d\n", chave, pos);
    printf("Tempo: %f segundos\n\n", tempo);

    // =========================
    // TESTE QUICK SELECT
    // =========================
    int k = TAM / 2; // mediana

    // Copiar vetor (Quick Select altera o vetor)
    int v2[TAM];
    for (int i = 0; i < TAM; i++) {
        v2[i] = v[i];
    }

    inicio = clock();
    int resultado = quick_select(v2, 0, TAM - 1, k);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Quick Select:\n");
    printf("%d-esimo menor elemento: %d\n", k, resultado);
    printf("Tempo: %f segundos\n", tempo);

    return 0;
}