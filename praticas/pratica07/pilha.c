#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Estrutura interna do nó
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

// Estrutura interna da pilha
struct pilha_t {
    No* topo;
};

Pilha* pilha_criar() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

    if (pilha == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        return NULL;
    }

    pilha->topo = NULL;

    return pilha;
}

int pilha_esta_vazia(Pilha* pilha) {
    if (pilha == NULL) {
        return 1;
    }

    return pilha->topo == NULL;
}

void pilha_empilhar(Pilha* pilha, int valor) {
    if (pilha == NULL) {
        return;
    }

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        return;
    }

    novo->valor = valor;
    novo->proximo = pilha->topo;

    pilha->topo = novo;
}

int pilha_desempilhar(Pilha* pilha) {
    if (pilha == NULL || pilha_esta_vazia(pilha)) {
        printf("Erro: pilha vazia.\n");
        return -1;
    }

    No* removido = pilha->topo;
    int valor = removido->valor;

    pilha->topo = removido->proximo;

    free(removido);

    return valor;
}

int pilha_topo(Pilha* pilha) {
    if (pilha == NULL || pilha_esta_vazia(pilha)) {
        printf("Erro: pilha vazia.\n");
        return -1;
    }

    return pilha->topo->valor;
}

void pilha_exibir(Pilha* pilha) {
    if (pilha == NULL || pilha_esta_vazia(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }

    No* atual = pilha->topo;

    printf("Pilha do topo para a base: ");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

void pilha_destruir(Pilha* pilha) {
    if (pilha == NULL) {
        return;
    }

    No* atual = pilha->topo;

    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(pilha);
}