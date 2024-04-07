#include <iostream>
#include "MarketingPlace.h"

int main() {
    int i = 0;
    Prateleiras camisas[3];
    Carrinho usuario;
    while(i != 1){
        switch (menuprincipal()) {
            case 1:
                break;
            case 2:
                if(inserirProdutonocarrinho(usuario,camisas[1])){
                    std::cout<<"Produto posto no carrinho com sucesso";
                }
                else{
                    std::cout<<"não deu botar no carrinho";
                }
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                i++;
                break;
        }
    }


    inserirProduto(camisas[1],45,"gloria a deus",45.99);
    inserirProduto(camisas[1],27,"gloria a deus",35.99);
    mostrarProdutosdaPrat(camisas[1]);
    if(buscarnanaprateleira(camisas[1],"gloria a deus")){
        std::cout<<"tem ali dentro";
    }
    else{
        std::cout<<"tem nada não";
    }
    std::cout<<getvalor(camisas[1]);

    return 0;
}
