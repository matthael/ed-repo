#include <stdio.h>
#include "tabela_hash.h"

int main() {
    TabelaHash* hash = hash_criar(10);

    if (hash == NULL) {
        return 1;
    }

    printf("Criando tabela hash...\n");

    if (hash_esta_vazia(hash)) {
        printf("A tabela hash está vazia.\n");
    }

    printf("\nInserindo elementos...\n");

    hash_inserir(hash, 10);
    hash_inserir(hash, 20);
    hash_inserir(hash, 15);
    hash_inserir(hash, 25);
    hash_inserir(hash, 7);
    hash_inserir(hash, 17);
    hash_inserir(hash, 30);

    hash_exibir(hash);

    printf("\nBuscando elementos...\n");

    if (hash_buscar(hash, 25)) {
        printf("Valor 25 encontrado na tabela hash.\n");
    } else {
        printf("Valor 25 não encontrado na tabela hash.\n");
    }

    if (hash_buscar(hash, 99)) {
        printf("Valor 99 encontrado na tabela hash.\n");
    } else {
        printf("Valor 99 não encontrado na tabela hash.\n");
    }

    printf("\nRemovendo elemento 25...\n");

    if (hash_remover(hash, 25)) {
        printf("Valor 25 removido com sucesso.\n");
    } else {
        printf("Valor 25 não encontrado para remoção.\n");
    }

    hash_exibir(hash);

    printf("\nRemovendo elemento 10...\n");

    if (hash_remover(hash, 10)) {
        printf("Valor 10 removido com sucesso.\n");
    } else {
        printf("Valor 10 não encontrado para remoção.\n");
    }

    hash_exibir(hash);

    printf("\nDestruindo tabela hash...\n");
    hash_destruir(hash);

    return 0;
}