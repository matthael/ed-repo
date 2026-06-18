#ifndef PILHA_H
#define PILHA_H

// Tipo abstrato Pilha
typedef struct pilha_t Pilha;

// Cria uma pilha vazia
Pilha* pilha_criar();

// Empilha um valor no topo da pilha
void pilha_empilhar(Pilha* pilha, int valor);

// Desempilha o elemento do topo
int pilha_desempilhar(Pilha* pilha);

// Retorna o valor do topo da pilha
int pilha_topo(Pilha* pilha);

// Verifica se a pilha está vazia
int pilha_esta_vazia(Pilha* pilha);

// Exibe os elementos da pilha
void pilha_exibir(Pilha* pilha);

// Libera toda a memória da pilha
void pilha_destruir(Pilha* pilha);

#endif