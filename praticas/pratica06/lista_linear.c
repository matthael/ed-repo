#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

// Estrutura interna do nó
typedef struct no_t {
    struct no_t* anterior;
    int valor;
    struct no_t* proximo;
} No;

// Estrutura interna da lista
struct lista_t {
    No* primeiro;
    No* ultimo;
};

Lista* lista_criar() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));

    if (lista == NULL) {
        printf("Erro ao alocar memória para a lista.\n");
        return NULL;
    }

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

int lista_esta_vazia(Lista* lista) {
    if (lista == NULL) {
        return 1;
    }

    return lista->primeiro == NULL;
}

void lista_inserir(Lista* lista, int valor) {
    if (lista == NULL) {
        return;
    }

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        return;
    }

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;

    if (lista_esta_vazia(lista)) {
        lista->primeiro = novo;
        lista->ultimo = novo;
    } else {
        novo->anterior = lista->ultimo;
        lista->ultimo->proximo = novo;
        lista->ultimo = novo;
    }
}

int lista_remover(Lista* lista, int valor) {
    if (lista == NULL || lista_esta_vazia(lista)) {
        return 0;
    }

    No* atual = lista->primeiro;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (atual == lista->primeiro && atual == lista->ultimo) {
                lista->primeiro = NULL;
                lista->ultimo = NULL;
            } else if (atual == lista->primeiro) {
                lista->primeiro = atual->proximo;
                lista->primeiro->anterior = NULL;
            } else if (atual == lista->ultimo) {
                lista->ultimo = atual->anterior;
                lista->ultimo->proximo = NULL;
            } else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }

            free(atual);
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

int lista_buscar(Lista* lista, int valor) {
    if (lista == NULL || lista_esta_vazia(lista)) {
        return 0;
    }

    No* atual = lista->primeiro;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

void lista_exibir(Lista* lista) {
    if (lista == NULL || lista_esta_vazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = lista->primeiro;

    printf("Lista: ");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

void lista_destruir(Lista* lista) {
    if (lista == NULL) {
        return;
    }

    No* atual = lista->primeiro;

    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(lista);
}