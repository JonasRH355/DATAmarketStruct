#include <iostream>
#include "MarketingPlace.h"

int main() {
    int i = 0;
    Local prateleira;
    Local carrinho;
    inserirProduto(prateleira,45,"george",45.99);
    inserirProduto(prateleira,27,"gloria a deus",35.99);

    while(i != 1){
        switch (menuprincipal()) {
            case 1:
                break;

            case 2: // 2- INSERIR UM PRODUTO DA PRATELERIA DENTRO DO CARRINHO
                inserirProdutonocarrinho(carrinho,prateleira);
                break;

            case 3:// 3- RETIRAR UM PRODUTO DO CARRINHO E POR EM UMA PRATELEIRA
                retirarprodutodocarrinho(carrinho,prateleira);
                break;

            case 4:
                std::cout<<getvalor(carrinho);
                i++;
                break;

            case 5:
                mostrarProdutos(carrinho);
                break;
                
            case 6:
                std::cout<<getvalor(prateleira);
                mostrarProdutos(prateleira);
                break;

            case 7:
                i++;
                break;
        }
    }

    mostrarProdutos(carrinho);
    return 0;
}
