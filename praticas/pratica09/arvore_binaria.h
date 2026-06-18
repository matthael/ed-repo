#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

// Tipo abstrato Arvore
typedef struct arvore_t Arvore;

// Cria uma árvore vazia
Arvore* arvore_criar();

// Insere um valor na árvore
void arvore_inserir(Arvore* arvore, int valor);

// Exibe os elementos em pré-ordem
void arvore_exibir_pre_ordem(Arvore* arvore);

// Exibe os elementos em ordem
void arvore_exibir_em_ordem(Arvore* arvore);

// Exibe os elementos em pós-ordem
void arvore_exibir_pos_ordem(Arvore* arvore);

// Verifica se a árvore está vazia
int arvore_esta_vazia(Arvore* arvore);

// Libera toda a memória da árvore
void arvore_destruir(Arvore* arvore);

#endif