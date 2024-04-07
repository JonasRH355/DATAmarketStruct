#include <iostream>
#include "MarketingPlace.h"

int main() {
    int i = 0;
    Local prateleira;
    Local carrinho;
    inserirProduto(prateleira,45,"george",45.99);
    inserirProduto(prateleira,27,"gloria a deus",35.99);
    inserirProduto(prateleira,27,"gloria a deus",35.99);
    while(i != 1){
        switch (menuprincipal()) {
            case 1:
                break;
            case 2:

                retirardaproduto(prateleira,27);
                break;
            case 3:
                break;
            case 4:
                std::cout<<getvalor(carrinho);
                i++;
                break;
            case 5:
                mostrarProdutos(carrinho);
                break;
            case 6:
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
