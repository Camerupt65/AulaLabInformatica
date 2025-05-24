#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "menus.h"

Cliente clientesStruct[QTD_CLIENTES];
int qtdClientesCadastrados = 0;

// 1
void cadastrarCliente() {
    if (qtdClientesCadastrados >= QTD_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }
    printf("Nome do cliente: ");
    scanf(" %s", clientesStruct[qtdClientesCadastrados].nome);
    qtdClientesCadastrados++;
}

// 3
void listarClientes() {
    for (int i = 0; i < qtdClientesCadastrados; i++) {
        printf("%d - %s\n", i + 1, clientesStruct[i].nome);
    }
}

// 4
void menuEditarCliente() {
    int opcao;
    do {
        mostraOpcoesClientes();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: buscarClienteMenu(); break;
            case 2: listarClientes(); break;
            case 0: printf("Voltando...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}


// 4.1
void buscarClienteMenu() {
    char selecao[200];
    int opcao, i = 0, encontrado = 0;

    printf("Digite o nome do cliente a ser editado: ");
    scanf(" %s", selecao);

    encontraIndexDeCliente(&encontrado, &i, selecao);

    if (!encontrado) {
        printf("Cliente '%s' nao encontrado.\n", selecao);
    } else {
        menuClienteSelecionado(selecao, i, encontrado);
    }
}
void encontraIndexDeCliente(int *encontrado, int *i, char selecao[200]) {
    for (*i = 0; *i < qtdClientesCadastrados; (*i)++) {
        if (strcmp(clientesStruct[*i].nome, selecao) == IGUAL) {
            *encontrado = 1;
            break;
        }
    }
}
void menuClienteSelecionado(char selecao[200], int i, int encontrado) {
    int opcao;
    mostraOpcoesClienteSelecionado();

    scanf("%d", &opcao);

    switch (opcao) {
        case 1: excluirCliente(selecao, i); break;
        case 2: alterarCliente(selecao, i); break;
        case 0: break;
        default: printf("Opcao invalida.\n");
    }
}

// 4.1.1
void excluirCliente(char clienteAExcluir[200], int index) {
    for (int j = index; j < qtdClientesCadastrados - 1; j++) {
        clientesStruct[j] = clientesStruct[j + 1];
    }
    qtdClientesCadastrados--;
    printf("Cliente '%s' excluido com sucesso.\n", clienteAExcluir);
}

// 4.1.2
void alterarCliente(char clienteAAlterar[200], int index) {
    char novoNome[200];
    printf("Digite o novo nome: ");
    scanf(" %s", novoNome);
    strcpy(clientesStruct[index].nome, novoNome);
    printf("Nome alterado com sucesso!\n");
}
