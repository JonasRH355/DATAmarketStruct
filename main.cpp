#include <iostream>
#include "MarketingPlace.h"

// Jônatas Régis Hellmann e Leonardo de Borba  Cardoso

int main() {
    int i = 0;
    Local prateleira;
    Local carrinho;
    std::string vendedor = "felix";
    importarProdutos(prateleira,"produtossalvos.txt");
    inserirProduto(prateleira, 1, "Camisa azul", 34.99);
    inserirProduto(prateleira, 2, "Camisa vermelha", 34.99);
    inserirProduto(prateleira, 3, "Meia rosa", 34.99);
    inserirProduto(prateleira, 4, "Boné preto", 34.99);


    while(i != 1){

        switch (menuprincipal()) {
            case 1:// 1- PESQUISAR
                system("cls");
                pesquisar(prateleira);
                break;

            case 2: // 2- INSERIR UM PRODUTO DA PRATELERIA DENTRO DO CARRINHO
                system("cls");
                inserirProdutonocarrinho(carrinho,prateleira);
                break;

            case 3:// 3- RETIRAR UM PRODUTO DO CARRINHO E POR EM UMA PRATELEIRA
                system("cls");
                retirarprodutodocarrinho(carrinho,prateleira);
                break;

            case 4: // 4-  PAGAR
                pagar(carrinho);
                break;

            case 5:// 5- CLIENTE
                system("cls");
                cliente(carrinho);
                break;

            case 6:// 6- GERENTE

                system("cls");

                gerente(prateleira);
                break;

            case 7:// SAIR
                system("cls");
                i++;
                break;
        }

    }
    exportarProdutos(prateleira,"produtossalvos.txt");
    return 0;
}
