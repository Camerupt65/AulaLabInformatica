#include <stdio.h>
#include "constantes.h"
#include "menus.h"
#include "cliente.h"
#include "produto.h"





void menu();

int main() {
    menu();

    return 0;
}

void menu() {
    int opcao;
    do {
        mostraOpcoes();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: cadastrarCliente(); break;
            case 2: insereProduto(); break;
            case 3: listarClientes(); break;
            case 4: menuEditarCliente(); break;
            case 5: editarProdutos(); break;
            case 6: listarProdutos(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}









