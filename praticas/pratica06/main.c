#include <stdio.h>
#include "lista_linear.h"

int main() {
    Lista* lista = lista_criar();

    if (lista == NULL) {
        return 1;
    }

    printf("Criando lista...\n");

    if (lista_esta_vazia(lista)) {
        printf("A lista está vazia.\n");
    }

    printf("\nInserindo elementos...\n");
    lista_inserir(lista, 10);
    lista_inserir(lista, 20);
    lista_inserir(lista, 30);
    lista_inserir(lista, 40);

    lista_exibir(lista);

    printf("\nBuscando elementos...\n");

    if (lista_buscar(lista, 20)) {
        printf("Valor 20 encontrado na lista.\n");
    } else {
        printf("Valor 20 não encontrado na lista.\n");
    }

    if (lista_buscar(lista, 99)) {
        printf("Valor 99 encontrado na lista.\n");
    } else {
        printf("Valor 99 não encontrado na lista.\n");
    }

    printf("\nRemovendo elemento 20...\n");

    if (lista_remover(lista, 20)) {
        printf("Valor 20 removido com sucesso.\n");
    } else {
        printf("Valor 20 não encontrado para remoção.\n");
    }

    lista_exibir(lista);

    printf("\nRemovendo elemento 10...\n");

    if (lista_remover(lista, 10)) {
        printf("Valor 10 removido com sucesso.\n");
    } else {
        printf("Valor 10 não encontrado para remoção.\n");
    }

    lista_exibir(lista);

    printf("\nDestruindo lista...\n");
    lista_destruir(lista);

    return 0;
}