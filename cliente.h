#ifndef CLIENTE_H
#define CLIENTE_H

#include "constantes.h"

typedef struct cliente {
    char nome[200];
    char email[200];
} Cliente;

extern Cliente clientesStruct[QTD_CLIENTES];
extern int qtdClientesCadastrados;

void cadastrarCliente();
void listarClientes();
void menuEditarCliente();
void mostraOpcoesClientes();
void buscarClienteMenu();
void encontraIndexDeCliente(int*, int*, char[]);
void menuClienteSelecionado(char[], int, int);
void excluirCliente(char[], int);
void alterarCliente(char[], int);

#endif
