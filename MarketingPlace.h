// quantidades disponíveis e descontos, dentre outras que você julgar necessário.
// pesquisar, verificar valores, reajustar preços, remover produtos do estoque, controlar
#include "DataSpace.h"

// OBS: MANTER OS RECURSOS DAS LISTAS EM UM ARQUIVO eternos.
// OBS2: FAZER COM QUE TENHA DESCONTO

int menuprincipal(){
    int x=0;

    std::cout<<"_________________________________\n";
    std::cout<<"        MERCADO DO DOMINUS       \n\n";
    std::cout<<"1- Pesquisar\n";
    std::cout<<"2- Colocar no carrinho\n";
    std::cout<<"3- Retirar do carrinho\n";
    std::cout<<"4- Pagar/Pedir a conta\n";
    std::cout<<"5- Cliente\n";
    std::cout<<"6- Gerente\n";
    std::cout<<"7- SAIR\n\n";
    std::cout<<"_________________________________";
    std::cin>>x;
    return x;
}

// 1- PESQUISAR
//   1.1 - PESQUISAR POR ID
//   1.2 - PESQUISAR POR PRECO (menor que)
//   1.3 - PESQUISAR GERAL
// 2- INSERIR UM PRODUTO DA PRATELERIA DENTRO DO CARRINHO

void inserirProdutonocarrinho(Local &usuario, Local &camisas){
    int idescolhido;
    std::cout<<"\nQual item você deseja inserir no carrinho? ";
    std::cin>>idescolhido;
    Produto *encontrar = camisas.comeco;
    while(encontrar != nullptr){
        if( encontrar->ID == idescolhido)
        {
            inserirProduto(usuario,idescolhido,encontrar->nome,encontrar->valordoproduto);
            retirardaproduto(camisas,idescolhido);
            break;
        }
        else{
            encontrar = encontrar->proximo;
        }
    }
}

// 3- RETIRAR UM PRODUTO DO CARRINHO E POR EM UMA PRATELEIRA
// 4-  PAGAR
// 5- CLIENTE
//  5.1- CALCULAR CARRINHO
//  5.2- MOSTRAR ITENS DO CARRINHO
// 6- GERENTE

