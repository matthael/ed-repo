#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t tempo_inicial = clock();

    int soma = 10 + 20;

    clock_t tempo_final = clock();

    double duracao = (double)(tempo_inicial - tempo_final) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %.5f segundos\n", duracao);

    tempo_inicial = clock();

    for (int i = 0; i < 1000000000; i++) {
        soma += i;
    }

    tempo_final = clock();

    duracao = (double)(tempo_inicial - tempo_final) / CLOCKS_PER_SEC;
    printf("Tempo gasto para o loop: %.5f segundos\n", duracao);

    return 0;
}