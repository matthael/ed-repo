#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    Arvore* arvore = arvore_criar();

    if (arvore == NULL) {
        return 1;
    }

    printf("Criando árvore binária...\n");

    if (arvore_esta_vazia(arvore)) {
        printf("A árvore está vazia.\n");
    }

    printf("\nInserindo elementos...\n");

    arvore_inserir(arvore, 50);
    arvore_inserir(arvore, 30);
    arvore_inserir(arvore, 70);
    arvore_inserir(arvore, 20);
    arvore_inserir(arvore, 40);
    arvore_inserir(arvore, 60);
    arvore_inserir(arvore, 80);

    printf("\nExibindo elementos nos diferentes percursos:\n\n");

    arvore_exibir_pre_ordem(arvore);
    arvore_exibir_em_ordem(arvore);
    arvore_exibir_pos_ordem(arvore);

    printf("\nTentando inserir valor repetido...\n");
    arvore_inserir(arvore, 30);

    printf("\nExibindo novamente em ordem:\n");
    arvore_exibir_em_ordem(arvore);

    printf("\nDestruindo árvore...\n");
    arvore_destruir(arvore);

    return 0;
}