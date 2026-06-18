#ifndef TABELA_HASH_H
#define TABELA_HASH_H

// Tipo abstrato TabelaHash
typedef struct hash_t TabelaHash;

// Cria uma tabela hash com um determinado tamanho
TabelaHash* hash_criar(int tamanho);

// Insere um valor na tabela hash
void hash_inserir(TabelaHash* hash, int valor);

// Busca um valor na tabela hash
int hash_buscar(TabelaHash* hash, int valor);

// Remove um valor da tabela hash
int hash_remover(TabelaHash* hash, int valor);

// Exibe os elementos da tabela hash
void hash_exibir(TabelaHash* hash);

// Verifica se a tabela hash está vazia
int hash_esta_vazia(TabelaHash* hash);

// Libera toda a memória da tabela hash
void hash_destruir(TabelaHash* hash);

#endif