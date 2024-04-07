#include <iostream>
#include "MarketingPlace.h"

int main() {
    int i = 0;
    Local prateleira;
    Local carrinho;
    std::string vendedor = "felix";
    importarProdutos(prateleira,"produtossalvos.txt");

    while(i != 1){
        switch (menuprincipal()) {
            case 1:// 1- PESQUISAR
                pesquisar(prateleira);
                break;

            case 2: // 2- INSERIR UM PRODUTO DA PRATELERIA DENTRO DO CARRINHO
                inserirProdutonocarrinho(carrinho,prateleira);
                break;

            case 3:// 3- RETIRAR UM PRODUTO DO CARRINHO E POR EM UMA PRATELEIRA
                retirarprodutodocarrinho(carrinho,prateleira);
                break;

            case 4: // 4-  PAGAR
                std::cout<<"Valor total:"<<getvalor(carrinho)<<"\nVendedor: "<<vendedor;
                mostrarProdutos(carrinho);
                i++;
                break;

            case 5:// 5- CLIENTE
                mostrarProdutos(carrinho);
                break;

            case 6:// 6- GERENTE
                std::cout<<getvalor(prateleira);
                mostrarProdutos(prateleira);
                break;

            case 7:// SAIR
                i++;
                break;
        }
    }
    exportarProdutos(prateleira,"produtossalvos.txt");
    return 0;
}
