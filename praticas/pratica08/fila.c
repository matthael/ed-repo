#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Estrutura interna do nó
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

// Estrutura interna da fila
struct fila_t {
    No* inicio;
    No* fim;
};

Fila* fila_criar() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));

    if (fila == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        return NULL;
    }

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

int fila_esta_vazia(Fila* fila) {
    if (fila == NULL) {
        return 1;
    }

    return fila->inicio == NULL;
}

void fila_enfileirar(Fila* fila, int valor) {
    if (fila == NULL) {
        return;
    }

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        return;
    }

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_esta_vazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

int fila_desenfileirar(Fila* fila) {
    if (fila == NULL || fila_esta_vazia(fila)) {
        printf("Erro: fila vazia.\n");
        return -1;
    }

    No* removido = fila->inicio;
    int valor = removido->valor;

    fila->inicio = removido->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);

    return valor;
}

int fila_inicio(Fila* fila) {
    if (fila == NULL || fila_esta_vazia(fila)) {
        printf("Erro: fila vazia.\n");
        return -1;
    }

    return fila->inicio->valor;
}

void lista_exibir(Fila* fila) {
    if (fila == NULL || fila_esta_vazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    No* atual = fila->inicio;

    printf("Fila do início para o fim: ");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

void fila_destruir(Fila* fila) {
    if (fila == NULL) {
        return;
    }

    No* atual = fila->inicio;

    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(fila);
}