#include <stdio.h>
#include <string.h>
#define QTD_CLIENTES 10
#define QTD_PRODUTOS 20
#define IGUAL 0

// DeclaraC'C#o de variC!veis e structs
int qtdClientesCadastrados = 0, qtdProdutosCadastrados = 0;

typedef struct cliente {
	char nome[200];
	char email[200];
} Cliente;
struct cliente clientesStruct[QTD_CLIENTES];

typedef struct produto {
	char nome[200];
	char valor[20];
	char vendas[200];
} Produto;
struct produto produtosStruct[QTD_PRODUTOS];

// *DeclaraC'C#o de funC'C5es*
void menu();                    // 0
void mostraOpcoes();            // 0

void cadastrarCliente();        // 1
void insereProduto();           // 2
void listarClientes();          // 3
void menuEditarCliente();       // 4
void mostraOpcoesClientes();    // 4
void editarProdutos();          // 5

void buscarClienteMenu();       // 4.1
void encontraIndexDeCliente();  // 4.1
void menuClienteSelecionado();  // 4.1

void excluirCliente();          // 4.1.1
void alterarCliente();          // 4.1.2



int main() {
	menu();

	return 0;
}

// Menu principal:
void menu() {
	int opcao;

	do {
		mostraOpcoes();
		scanf("%d", &opcao);
		printf("Voce digitou: %d\n", opcao);
		printf("\n\n");

		switch(opcao) {
		case 1:
			cadastrarCliente();
			break;
		case 2:
			insereProduto();
			break;
		case 3:
			listarClientes();
			break;
		case 4:
			menuEditarCliente();
			break;
		case 5:
			editarProdutos();
			break;
		case 0:
			printf("Encerrando...\n");
			break;
		default:
			printf("OpC'C#o invC!lida. Tente novamente.\n");
		}
	} while (opcao != 0);
}
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


// 1 - inserir nome do cliente
void cadastrarCliente() {
	if (qtdClientesCadastrados >= QTD_CLIENTES) {
		printf("Limite de clientes atingido.\n");
		return;
	}
	printf("Nome do cliente: ");
	scanf(" %s", clientesStruct[qtdClientesCadastrados].nome);
	qtdClientesCadastrados++;
}

// 2 - inserir nome do produto
void insereProduto() {
	if (qtdProdutosCadastrados >= QTD_PRODUTOS) {
		printf("Limite de produtos atingido.\n");
		return;
	}
	printf("Nome do produto: ");
	scanf(" %s", produtosStruct[qtdProdutosCadastrados].nome);
	qtdProdutosCadastrados++;
}

// 3 - lista os clientes cadastrados
void listarClientes() {
	for (int i = 0; i < qtdClientesCadastrados; i++) {
		printf("%d - %s\n", i + 1, clientesStruct[i].nome);
	}
}



// 4 - menu para editar clientes
void menuEditarCliente() {
	int opcao;

	do {
		mostraOpcoesClientes();
		scanf("%d", &opcao);
		printf("Voce digitou: %d\n", opcao);
		printf("\n\n");

		switch(opcao) {
		case 1:
			buscarClienteMenu();
			break;
		case 2:
			listarClientes();
			break;
		case 0:
			printf("Voltando...\n");
			break;
		default:
			printf("OpC'C#o invC!lida. Tente novamente.\n");
		}
	} while (opcao != 0);
}
void mostraOpcoesClientes() {
	printf(
	    "\nSelecione uma opcao:\n"
	    "0 - para voltar\n"
	    "1 - selecionar cliente\n"
	    "2 - listar clientes\n"
	);
}


// 4.1 - menu de busca de cliente
void buscarClienteMenu() {
	char selecao[200];
	int opcao, i = 0, encontrado = 0;

	printf("Digite o nome do cliente a ser editado: ");
	scanf(" %s", selecao);

	encontraIndexDeCliente(&encontrado, &i, selecao);

	if (encontrado == 0) {
		printf("\nCliente '%s' nC#o encontrado.\n", selecao);
	}
	else {
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

// 4.1 - menu depois de selecionar o cliente
void menuClienteSelecionado(char selecao[200], int i, int encontrado) {
	int opcao;

	printf(
	    "\nSelecione uma opcao:\n"
	    "0 - voltar\n"
	    "1 - excluir\n"
	    "2 - alterar nome\n"
	);
	scanf("%d", &opcao);

	switch (opcao) {
	case 1:
		excluirCliente(selecao, i);
		break;
	case 2:
		alterarCliente(selecao, i);
		break;
	case 0:
		printf("Voltando...\n");
		break;
	default:
		printf("OpC'C#o invC!lida. Tente novamente.\n");
	}
}


// 4.1.1 - exclui o cliente pelo nome
void excluirCliente(char clienteAExcluir[200], int index) {
	for (int j = index; j < qtdClientesCadastrados - 1; j++) {
		clientesStruct[j] = clientesStruct[j + 1];
	}
	qtdClientesCadastrados--;
	printf("\nCliente '%s' excluido com sucesso.\n", clienteAExcluir);
}

// 4.1.2 - altera o nome do cliente procurando pelo nome
void alterarCliente(char clienteAALterar[200], int index) {
	char novoNome[200];

	printf("Digite o novo nome: ");
	scanf(" %s", novoNome);

	strcpy(clientesStruct[index].nome, novoNome);

	printf("\nNome alterado com sucesso!\n");
}



void editarProdutos() {

}
