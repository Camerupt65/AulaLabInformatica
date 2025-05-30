#ifndef VENDA_H
#define VENDA_H


typedef struct produtoVenda {
    int idProduto;
    int quantidade;
} ProdutoVenda;

typedef struct venda {
    int idNotaFiscal;
    int idCliente;
    ProdutoVenda produtos[10];
    float valorTotal;
} Venda;

void gerarVenda();

#endif
