#include <stdio.h>
#include "produto.h"
#include "menus.h"

Produto produtosStruct[QTD_PRODUTOS];
int qtdProdutosCadastrados = 0;

void insereProduto() {
    if (qtdProdutosCadastrados >= QTD_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }
    printf("Nome do produto: ");
    scanf(" %s", produtosStruct[qtdProdutosCadastrados].nome);
    qtdProdutosCadastrados++;
}

void editarProdutos() {
    printf("Funcao de editar produtos ainda nao implementada.\n");
}
