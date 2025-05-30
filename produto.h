#ifndef PRODUTO_H
#define PRODUTO_H

#include "constantes.h"

typedef struct produto {
    char nome[200];
    char vendas[200];
    double valor;
    int id;
} Produto;

extern Produto produtosStruct[QTD_PRODUTOS];
extern int qtdProdutosCadastrados;

void insereProduto();
void listarProdutos();
void editarProdutos();

#endif












