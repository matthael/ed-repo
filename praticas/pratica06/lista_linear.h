#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

// Tipo abstrato Lista
typedef struct lista_t Lista;

// Cria uma lista vazia
Lista* lista_criar();

// Insere um valor no final da lista
void lista_inserir(Lista* lista, int valor);

// Remove a primeira ocorrência de um valor da lista
int lista_remover(Lista* lista, int valor);

// Busca um valor na lista
int lista_buscar(Lista* lista, int valor);

// Exibe todos os elementos da lista
void lista_exibir(Lista* lista);

// Verifica se a lista está vazia
int lista_esta_vazia(Lista* lista);

// Libera toda a memória da lista
void lista_destruir(Lista* lista);

#endif