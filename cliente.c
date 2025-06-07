#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "menus.h"

Cliente clientesStruct[QTD_CLIENTES];
int qtdClientesCadastrados = 0;
int ultimoIdCliente = 0;


// 1 insercao
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



// 2 listagem
void listarClientes() {
    if (qtdClientesCadastrados == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    printf("\n--------------------------");
    for (int i = 0; i < qtdClientesCadastrados; i++) {
        printf("\nid: %d | nome: %s", clientesStruct[i].id, clientesStruct[i].nome);
    }
    printf("\n--------------------------\n");
}



// 3 menu de edicao
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

// 3.1 busca
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

// 3.1 menu de edicao 2
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

// 3.1.1 exclusao
void excluirCliente(int id, int index) {
    for (int j = index; j < qtdClientesCadastrados - 1; j++) {
        clientesStruct[j] = clientesStruct[j + 1];
    }
    qtdClientesCadastrados--;
    printf("Cliente com ID %d excluído com sucesso.\n", id);
}

// 3.1.2 alteracao
void alterarCliente(int id, int index) {
    char novoNome[200];
    printf("Digite o novo nome: ");
    scanf(" %s", novoNome);
    strcpy(clientesStruct[index].nome, novoNome);
    printf("Cliente com ID %d alterado com sucesso!\n", id);
}














