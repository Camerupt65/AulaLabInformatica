#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "produto.h"
#include "venda.h"

int ultimoIdVendaCadastrada = 0;
int numDeVendasGeradas = 0;
int numDeClientes = 0;
int idCliente;

Venda venda[QTD_VENDAS];
ProdutoVenda produtoVenda;


void atribuicaoDeNumZeroAVarNumDeProComp() {
    for (int i = 0; i < QTD_VENDAS; i++) venda[i].numDeProdutosDiferentesComprados = 0;
}

void gerarVendaNova() {
    solicitaClienteComprador();
    solicitaProdutoComprado();
    
    venda[numDeVendasGeradas].idNotaFiscal = ultimoIdVendaCadastrada;
    venda[numDeVendasGeradas].idCliente = idCliente;
    venda[numDeVendasGeradas].produtos[venda[numDeVendasGeradas].numDeProdutosDiferentesComprados] = produtoVenda;
    
    numDeVendasGeradas++;
}

void solicitaClienteComprador() {
    listarClientes();
    
    printf("Informe o ID do cliente: \n");
    scanf("%d", &idCliente);
    numDeClientes++;
}

void solicitaProdutoComprado() {
    listarProdutos();
    
    printf("Informe o Id do produto: \n");
    scanf("%d", &produtoVenda.idProduto);
    printf("Informe a quantidade do produto: \n");
    scanf("%d", &produtoVenda.quantidade);

    ultimoIdVendaCadastrada++;
    venda[numDeVendasGeradas].numDeProdutosDiferentesComprados++;
}







