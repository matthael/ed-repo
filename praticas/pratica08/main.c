#include <stdio.h>
#include "fila.h"

int main() {
    Fila* fila = fila_criar();

    if (fila == NULL) {
        return 1;
    }

    printf("Criando fila...\n");

    if (fila_esta_vazia(fila)) {
        printf("A fila está vazia.\n");
    }

    printf("\nEnfileirando elementos...\n");

    fila_enfileirar(fila, 10);
    fila_enfileirar(fila, 20);
    fila_enfileirar(fila, 30);
    fila_enfileirar(fila, 40);

    lista_exibir(fila);

    printf("\nConsultando o início da fila...\n");
    printf("Início da fila: %d\n", fila_inicio(fila));

    printf("\nDesenfileirando elementos...\n");

    printf("Valor removido: %d\n", fila_desenfileirar(fila));
    lista_exibir(fila);

    printf("Valor removido: %d\n", fila_desenfileirar(fila));
    lista_exibir(fila);

    printf("\nConsultando o novo início da fila...\n");
    printf("Início da fila: %d\n", fila_inicio(fila));

    printf("\nEnfileirando novo elemento...\n");
    fila_enfileirar(fila, 50);

    lista_exibir(fila);

    printf("\nDestruindo fila...\n");
    fila_destruir(fila);

    return 0;
}