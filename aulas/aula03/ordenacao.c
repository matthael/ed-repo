#include <stdio.h>
#include "ordenacao.h"

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(&v[j], &v[j + 1]);
            }
        }
    }
}

void imprimeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}   