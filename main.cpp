#include <iostream>
#include "MarketingPlace.h"

int main() {
    int i = 0;
    Local camisas;
    Local usuario;
    inserirProduto(camisas,45,"gloria a deus",45.99);
    inserirProduto(camisas,27,"gloria a deus",35.99);
    while(i != 1){
        switch (menuprincipal()) {
            case 1:
                break;
            case 2:
                if(inserirProdutonocarrinho(usuario,camisas)){
                    std::cout<<"Produto posto no carrinho com sucesso\n";
                }
                else{
                    std::cout<<"não deu botar no carrinho";
                }
                break;
            case 3:
                break;
            case 4:
                std::cout<<getvalor(usuario);
                break;
            case 5:
                mostrarProdutosdaPrat(usuario);
                break;
            case 6:
                mostrarProdutosdaPrat(camisas);
                break;
            case 7:
                i++;
                break;
        }
    }

    return 0;
}
