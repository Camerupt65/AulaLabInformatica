#include <stdio.h>
#include "menus.h"
#include "constantes.h"

// menu principal
void mostraOpcoes() {
    printf(
        "\n"
        "\nSelecione uma opcao:\n"
        "\n"
        "0 - para sair\n"
        "\n"
        "------Clientes------\n"
        "1 - insere cliente\n"
        "2 - listar clientes\n"
        "3 - editar cliente\n"
        "\n"
        "------Produtos------\n"
        "4 - insere produto\n"
        "5 - listar produtos\n"
        "6 - editar produto\n"
        "\n"
        "-------Vendas-------\n"
        "7 - gerar venda\n"
    );
}

// menus clientes
void mostraOpcoesClientes() {
    printf(
        "\nSelecione uma opcao:\n"
        "0 - para voltar\n"
        "1 - selecionar cliente\n"
        "2 - listar clientes\n"
    );
}
void mostraOpcoesClienteSelecionado() {
    printf(
        "\nSelecione uma opcao:\n"
        "0 - voltar\n"
        "1 - excluir\n"
        "2 - alterar nome\n"
    );
}

// menus produtos
void mostraOpcoesProdutos() {
    printf(
        "\nSelecione uma opcao:\n"
        "0 - para voltar\n"
        "1 - selecionar produto\n"
        "2 - listar produtos\n"
    );
}
void mostraOpcoesProdutoSelecionado() {
    printf(
        "\nSelecione uma opcao:\n"
        "0 - voltar\n"
        "1 - excluir\n"
        "2 - alterar nome\n"
    );
}









