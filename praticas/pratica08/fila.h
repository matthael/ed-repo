#ifndef FILA_H
#define FILA_H

// Tipo abstrato Fila
typedef struct fila_t Fila;

// Cria uma fila vazia
Fila* fila_criar();

// Insere um valor no fim da fila
void fila_enfileirar(Fila* fila, int valor);

// Remove e retorna o valor do início da fila
int fila_desenfileirar(Fila* fila);

// Retorna o valor do início da fila sem remover
int fila_inicio(Fila* fila);

// Exibe os elementos da fila
void lista_exibir(Fila* fila);

// Verifica se a fila está vazia
int fila_esta_vazia(Fila* fila);

// Libera toda a memória da fila
void fila_destruir(Fila* fila);

#endif