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
    int numDeProdutosDiferentesComprados;
} Venda;


extern Venda venda[QTD_VENDAS];

void atribuicaoDeNumZeroAVarNumDeProComp();
void gerarVendaNova();
void solicitaClienteComprador();
void solicitaProdutoComprado();

#endif
