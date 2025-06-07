#include <stdio.h>
#include <string.h>
#include "produto.h"
#include "menus.h"

Produto produtosStruct[QTD_PRODUTOS];
int qtdProdutosCadastrados = 0;
int ultimoIdProduto = 0;


// 4 insercao
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



// 5 listagem
void listarProdutos() {
    if (qtdProdutosCadastrados == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("\n--------------------------");
    for (int i = 0; i < qtdProdutosCadastrados; i++) {
        printf("\nid: %d | nome: %s", produtosStruct[i].id, produtosStruct[i].nome);
    }
    printf("\n--------------------------\n");
}



// 6 menu de edicao
void menuEditarProduto() {
    int opcao;
    do {
        mostraOpcoesProdutos();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: buscarProdutoMenu(); break;
            case 2: listarProdutos(); break;
            case 0: printf("Voltando...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}

// 6.1 busca
void buscarProdutoMenu() {
    int id, index;

    printf("Digite o ID do produto a ser editado: ");
    scanf("%d", &id);

    index = encontraIndexDeProduto(id);

    if (index == -1) {
        printf("Produto com ID %d nao encontrado.\n", id);
    } else {
        menuProdutoSelecionado(id, index);
    }
}
int encontraIndexDeProduto(int id) {
    for (int i = 0; i < qtdProdutosCadastrados; i++) {
        if (produtosStruct[i].id == id) {
            return i;
        }
    }
    return -1;
}

// 6.1 menu de edicao 2
void menuProdutoSelecionado(int id, int index) {
    int opcao;
    mostraOpcoesProdutoSelecionado();

    scanf("%d", &opcao);

    switch (opcao) {
        case 1: excluirProduto(id, index); break;
        case 2: alterarProduto(id, index); break;
        case 0: break;
        default: printf("Opcao invalida.\n");
    }
}

// 6.1.1 exclusao
void excluirProduto(int id, int index) {
    for (int j = index; j < qtdProdutosCadastrados - 1; j++) {
        produtosStruct[j] = produtosStruct[j + 1];
    }
    qtdProdutosCadastrados--;
    printf("Produto com ID %d excluído com sucesso.\n", id);
}

// 6.1.2 alteracao
void alterarProduto(int id, int index) {
    char novoNome[200];
    printf("Digite o novo nome: ");
    scanf(" %s", novoNome);
    strcpy(produtosStruct[index].nome, novoNome);
    printf("Produto com ID %d alterado com sucesso!\n", id);
}

























