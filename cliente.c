#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "menus.h"

Cliente clientesStruct[QTD_CLIENTES];
int qtdClientesCadastrados = 0;
int ultimoIdCliente = 0;


// 1
void cadastrarCliente() {
    if (qtdClientesCadastrados >= QTD_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }
    printf("Nome do cliente: ");
    scanf(" %s", clientesStruct[qtdClientesCadastrados].nome);
    
    ultimoIdCliente++;
    clientesStruct[qtdClientesCadastrados].id = ultimoIdCliente;

    qtdClientesCadastrados++;
}

// 3
void listarClientes() {
    if (qtdClientesCadastrados == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtdClientesCadastrados; i++) {
        printf("id: %d | nome: %s\n", clientesStruct[i].id, clientesStruct[i].nome);
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
    int id, index;

    printf("Digite o ID do cliente a ser editado: ");
    scanf("%d", &id);

    index = encontraIndexDeCliente(id);

    if (index == -1) {
        printf("Cliente com ID %d nao encontrado.\n", id);
    } else {
        menuClienteSelecionado(id, index);
    }
}
int encontraIndexDeCliente(int id) {
    for (int i = 0; i < qtdClientesCadastrados; i++) {
        if (clientesStruct[i].id == id) {
            return i;
        }
    }
    return -1;
}

void menuClienteSelecionado(int id, int index) {
    int opcao;
    mostraOpcoesClienteSelecionado();

    scanf("%d", &opcao);

    switch (opcao) {
        case 1: excluirCliente(id, index); break;
        case 2: alterarCliente(id, index); break;
        case 0: break;
        default: printf("Opcao invalida.\n");
    }
}

// 4.1.1
void excluirCliente(int id, int index) {
    for (int j = index; j < qtdClientesCadastrados - 1; j++) {
        clientesStruct[j] = clientesStruct[j + 1];
    }
    qtdClientesCadastrados--;
    printf("Cliente com ID %d excluído com sucesso.\n", id);
}


// 4.1.2
void alterarCliente(int id, int index) {
    char novoNome[200];
    printf("Digite o novo nome: ");
    scanf(" %s", novoNome);
    strcpy(clientesStruct[index].nome, novoNome);
    printf("Cliente com ID %d alterado com sucesso!\n", id);
}














