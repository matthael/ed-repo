#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

// Estrutura interna do nó
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

// Estrutura interna da tabela hash
struct hash_t {
    No** tabela;
    int tamanho;
};

// Função hash
static int funcao_hash(TabelaHash* hash, int valor) {
    int indice = valor % hash->tamanho;

    if (indice < 0) {
        indice += hash->tamanho;
    }

    return indice;
}

TabelaHash* hash_criar(int tamanho) {
    if (tamanho <= 0) {
        printf("Erro: tamanho inválido.\n");
        return NULL;
    }

    TabelaHash* hash = (TabelaHash*) malloc(sizeof(TabelaHash));

    if (hash == NULL) {
        printf("Erro ao alocar memória para a tabela hash.\n");
        return NULL;
    }

    hash->tamanho = tamanho;
    hash->tabela = (No**) malloc(tamanho * sizeof(No*));

    if (hash->tabela == NULL) {
        printf("Erro ao alocar memória para os buckets da tabela.\n");
        free(hash);
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        hash->tabela[i] = NULL;
    }

    return hash;
}

int hash_esta_vazia(TabelaHash* hash) {
    if (hash == NULL) {
        return 1;
    }

    for (int i = 0; i < hash->tamanho; i++) {
        if (hash->tabela[i] != NULL) {
            return 0;
        }
    }

    return 1;
}

void hash_inserir(TabelaHash* hash, int valor) {
    if (hash == NULL) {
        return;
    }

    int indice = funcao_hash(hash, valor);

    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        return;
    }

    novo->valor = valor;
    novo->proximo = hash->tabela[indice];

    hash->tabela[indice] = novo;
}

int hash_buscar(TabelaHash* hash, int valor) {
    if (hash == NULL || hash_esta_vazia(hash)) {
        return 0;
    }

    int indice = funcao_hash(hash, valor);

    No* atual = hash->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

int hash_remover(TabelaHash* hash, int valor) {
    if (hash == NULL || hash_esta_vazia(hash)) {
        return 0;
    }

    int indice = funcao_hash(hash, valor);

    No* atual = hash->tabela[indice];
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                hash->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual);
            return 1;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    return 0;
}

void hash_exibir(TabelaHash* hash) {
    if (hash == NULL || hash_esta_vazia(hash)) {
        printf("Tabela hash vazia.\n");
        return;
    }

    printf("Tabela Hash:\n");

    for (int i = 0; i < hash->tamanho; i++) {
        printf("[%d]: ", i);

        No* atual = hash->tabela[i];

        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }

        printf("NULL\n");
    }
}

void hash_destruir(TabelaHash* hash) {
    if (hash == NULL) {
        return;
    }

    for (int i = 0; i < hash->tamanho; i++) {
        No* atual = hash->tabela[i];

        while (atual != NULL) {
            No* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }

    free(hash->tabela);
    free(hash);
}