#ifndef PRODUTO_H
#define PRODUTO_H

#include "constantes.h"

typedef struct produto {
    char nome[200];
    char valor[20];
    char vendas[200];
} Produto;

extern Produto produtosStruct[QTD_PRODUTOS];
extern int qtdProdutosCadastrados;

void insereProduto();
void editarProdutos();

#endif
