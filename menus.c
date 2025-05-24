#include <stdio.h>
#include "menus.h"
#include "constantes.h"

void mostraOpcoes() {
    printf(
        "\nSelecione uma opcao:\n"
        "0 - para sair\n"
        "1 - insere cliente\n"
        "2 - insere produto\n"
        "3 - listar clientes\n"
        "4 - editar cliente\n"
        "5 - editar produto\n"
    );
}

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
