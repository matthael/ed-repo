#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* pilha = pilha_criar();

    if (pilha == NULL) {
        return 1;
    }

    printf("Criando pilha...\n");

    if (pilha_esta_vazia(pilha)) {
        printf("A pilha está vazia.\n");
    }

    printf("\nEmpilhando elementos...\n");

    pilha_empilhar(pilha, 10);
    pilha_empilhar(pilha, 20);
    pilha_empilhar(pilha, 30);
    pilha_empilhar(pilha, 40);

    pilha_exibir(pilha);

    printf("\nConsultando o topo...\n");
    printf("Topo da pilha: %d\n", pilha_topo(pilha));

    printf("\nDesempilhando elementos...\n");

    printf("Valor removido: %d\n", pilha_desempilhar(pilha));
    pilha_exibir(pilha);

    printf("Valor removido: %d\n", pilha_desempilhar(pilha));
    pilha_exibir(pilha);

    printf("\nConsultando o novo topo...\n");
    printf("Topo da pilha: %d\n", pilha_topo(pilha));

    printf("\nDestruindo pilha...\n");
    pilha_destruir(pilha);

    return 0;
}