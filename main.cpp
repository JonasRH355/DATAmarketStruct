#include <iostream>
#include "MarketingPlace.h"

int main() {
    int i = 0;
    do{
        switch (menuprincipal()) {
            case 1:
                i=0;
            case 2:
                i=0;
            case 3:
                i=0;
            case 4:
                i=0;
            case 5:
                i=0;
            case 6:
                i=0;
            case 7:
                sair(i);
        }
    }while(i == 1);

    Prateleiras camisas[3];
    inserirProduto(camisas[1],45,"gloria a deus",45.99);
    inserirProduto(camisas[1],27,"gloria a deus",35.99);
    mostrarProdutosdaPrat(camisas[1]);
    if(buscarnanaprateleira(camisas[1],"gloria a deus")){
        std::cout<<"tem ali dentro";
    }
    else{
        std::cout<<"tem nada não";
    }

    return 0;
}
