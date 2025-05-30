#include <stdio.h>
#include "produto.h"
#include "menus.h"

Produto produtosStruct[QTD_PRODUTOS];
int qtdProdutosCadastrados = 0;
int ultimoIdProduto = 0;


void insereProduto() {
    if (qtdProdutosCadastrados >= QTD_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }
    printf("Nome do produto: ");
    scanf(" %s", produtosStruct[qtdProdutosCadastrados].nome);
    
    ultimoIdProduto++;
    produtosStruct[qtdProdutosCadastrados].id = ultimoIdProduto;
    
    qtdProdutosCadastrados++;
}

void listarProdutos() {
    if (qtdProdutosCadastrados == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtdProdutosCadastrados; i++) {
        printf("id: %d | nome: %s\n", produtosStruct[i].id, produtosStruct[i].nome);
    }
}


void editarProdutos() {
    printf("Funcao de editar produtos ainda nao implementada.\n");
}












