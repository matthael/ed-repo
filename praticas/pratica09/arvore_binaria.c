#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

// Estrutura interna do nó
typedef struct no_t {
    struct no_t* esquerda;
    int valor;
    struct no_t* direita;
} No;

// Estrutura interna da árvore
struct arvore_t {
    No* raiz;
};

// Função auxiliar para criar um nó
static No* criar_no(int valor) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        return NULL;
    }

    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

// Função auxiliar recursiva para inserir
static No* inserir_recursivo(No* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_recursivo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_recursivo(raiz->direita, valor);
    } else {
        printf("Valor %d já existe na árvore.\n", valor);
    }

    return raiz;
}

// Função auxiliar para exibir em pré-ordem
static void exibir_pre_ordem_recursivo(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        exibir_pre_ordem_recursivo(raiz->esquerda);
        exibir_pre_ordem_recursivo(raiz->direita);
    }
}

// Função auxiliar para exibir em ordem
static void exibir_em_ordem_recursivo(No* raiz) {
    if (raiz != NULL) {
        exibir_em_ordem_recursivo(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibir_em_ordem_recursivo(raiz->direita);
    }
}

// Função auxiliar para exibir em pós-ordem
static void exibir_pos_ordem_recursivo(No* raiz) {
    if (raiz != NULL) {
        exibir_pos_ordem_recursivo(raiz->esquerda);
        exibir_pos_ordem_recursivo(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// Função auxiliar para destruir a árvore
static void destruir_recursivo(No* raiz) {
    if (raiz != NULL) {
        destruir_recursivo(raiz->esquerda);
        destruir_recursivo(raiz->direita);
        free(raiz);
    }
}

Arvore* arvore_criar() {
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));

    if (arvore == NULL) {
        printf("Erro ao alocar memória para a árvore.\n");
        return NULL;
    }

    arvore->raiz = NULL;

    return arvore;
}

int arvore_esta_vazia(Arvore* arvore) {
    if (arvore == NULL) {
        return 1;
    }

    return arvore->raiz == NULL;
}

void arvore_inserir(Arvore* arvore, int valor) {
    if (arvore == NULL) {
        return;
    }

    arvore->raiz = inserir_recursivo(arvore->raiz, valor);
}

void arvore_exibir_pre_ordem(Arvore* arvore) {
    if (arvore == NULL || arvore_esta_vazia(arvore)) {
        printf("Árvore vazia.\n");
        return;
    }

    printf("Pré-ordem: ");
    exibir_pre_ordem_recursivo(arvore->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore* arvore) {
    if (arvore == NULL || arvore_esta_vazia(arvore)) {
        printf("Árvore vazia.\n");
        return;
    }

    printf("Em ordem: ");
    exibir_em_ordem_recursivo(arvore->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore* arvore) {
    if (arvore == NULL || arvore_esta_vazia(arvore)) {
        printf("Árvore vazia.\n");
        return;
    }

    printf("Pós-ordem: ");
    exibir_pos_ordem_recursivo(arvore->raiz);
    printf("\n");
}

void arvore_destruir(Arvore* arvore) {
    if (arvore == NULL) {
        return;
    }

    destruir_recursivo(arvore->raiz);
    free(arvore);
}