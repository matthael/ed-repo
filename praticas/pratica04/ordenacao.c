#include "ordenacao.h"

// Bubble Sort
void bubble_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        int temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
    }
}

// Função auxiliar do Quick Sort
static int particionar(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1;
}

// Quick Sort
void quick_sort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(v, inicio, fim);
        quick_sort(v, inicio, p - 1);
        quick_sort(v, p + 1, fim);
    }
}