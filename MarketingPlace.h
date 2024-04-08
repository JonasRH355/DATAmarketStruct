#include "DataSpace.h"
#include <string>


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

// ______________________________1- PESQUISAR___________________________________
int menupesquisar(){
    int x=0;

    std::cout<<"_________________________________\n";
    std::cout<<"        MERCADO DO DOMINUS       \n\n";
    std::cout<<"1- Pesquisar por Nome\n";
    std::cout<<"2- Pesquisar por preco (menor que)\n";
    std::cout<<"3- Pesquisar geral\n";
    std::cout<<"4- Mostrar todos os produtos\n";
    std::cout<<"7- SAIR\n\n";
    std::cout<<"_________________________________";
    std::cin>>x;
    return x;
}

bool pesquisaporNome(Local prateleira){
    std::string nomeabuscar;
    std::cout<<"Qual o nome do produto: ";
    std::cin.ignore();
    std::getline(std::cin,nomeabuscar);
    Produto *encontrar = prateleira.comeco;
    while(encontrar != nullptr){
        if(nomeabuscar == encontrar->nome)
        {
            std::cout<<"\nID: "<<encontrar->ID<<" | Produto: "<<encontrar->nome<<" | Valor: "<< encontrar->valordoproduto<<"\n";
            return true;
        }
        else{
            encontrar = encontrar->proximo;
        }

    }
    return false;
}

bool pesquisamenorque(Local prateleira){
    float valormaximo = 0;
    std::cout<<"Qual o valor maximo a pagar: ";
    std::cin>>valormaximo;
    Produto *encontrar = prateleira.comeco;
    std::cout<<"\n\n--------------------------\nPRODUTOS ENCONTRADOS:\n";
    while(encontrar != nullptr){

        if(valormaximo >= encontrar->valordoproduto)
        {
            std::cout<<"\nID: "<<encontrar->ID<<" | Produto: "<<encontrar->nome<<" | Valor: "<< encontrar->valordoproduto<<"\n";
        }

        if(encontrar->proximo == nullptr){return false;}
        encontrar = encontrar->proximo;

    }
    return true;
}

bool pesquisageral(Local prateleira){
    std::string nomeabuscar;
    float valorbuscar=0;
    std::cout<<"Qual o nome do produto: ";

    std::cin>>nomeabuscar;

    std::cin.ignore();
    std::getline(std::cin,nomeabuscar);

    std::cout<<"Qual o valor maximo dele:";
    std::cin>> valorbuscar;
    Produto *encontrar = prateleira.comeco;
    while(encontrar != nullptr){
        if(nomeabuscar == encontrar->nome && valorbuscar >= encontrar->valordoproduto)
        {
            std::cout<<"\nID: "<<encontrar->ID<<" | Produto: "<<encontrar->nome<<" | Valor: "<< encontrar->valordoproduto<<"\n";
            return true;
        }
        else{
            encontrar = encontrar->proximo;
        }

    }
    return false;
}

void pesquisar(Local prateleira){
    switch (menupesquisar()) {
        case 1:
            if(pesquisaporNome(prateleira)){
                break;
            }
            else{
                std::cout<<"\nNão foi encontrado\n";
            }
            break;
        case 2:
            pesquisamenorque(prateleira);
            break;
        case 3:
            if (pesquisageral(prateleira)){
                break;
            }else{
                std::cout<<"\nNão foi encontrado\n";
            }
            break;
        case 4:
            mostrarProdutos(prateleira);
            break;
        case 7:
            system("cls");
            break;
    }
}



//   1.1 - PESQUISAR POR ID
//   1.2 - PESQUISAR POR PRECO (menor que)
//   1.3 - PESQUISAR GERAL


//_________________________________________________FIM PESQUISAR_______________________________________________


// ____________INSERIR UM PRODUTO DA PRATELERIA DENTRO DO CARRINHO____________________________________________
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
//_______________________FIM INSERIR__________________________________________________________________________


// _________________________________RETIRAR UM PRODUTO DO CARRINHO E POR EM UMA PRATELEIRA____________________
void retirarprodutodocarrinho(Local &usuario, Local &camisas){
    int idescolhido;
    std::cout<<"\nQual item você deseja retirar do carrinho? ";
    std::cin>>idescolhido;
    Produto *encontrar = usuario.comeco;
    while(encontrar != nullptr){
        if( encontrar->ID == idescolhido)
        {
            inserirProduto(camisas,idescolhido,encontrar->nome,encontrar->valordoproduto);
            retirardaproduto(usuario,idescolhido);
            break;
        }
        else{
            encontrar = encontrar->proximo;
        }
    }
}
//____________________________FIM RETIRAR_____________________________________________________________________



// 4-  PAGAR

// ________________________________________________5 -MENU DO CLIENTE_________________________________
int menucliente(){
    int x=0;
    std::cout<<"_________________________________\n";
    std::cout<<"        MERCADO DO DOMINUS       \n\n";
    std::cout<<"1- Calcular Carrinho\n";
    std::cout<<"2- Mostrar Itens do Carrinho\n";
    std::cout<<"3- SAIR\n";
    std::cout<<"_________________________________";
    std::cin>>x;
    return x;
}

void cliente(Local carrinho){
    switch (menucliente()) {
        case 1:
            std::cout << "O valor do seu carrinho: R$" << getvalor(carrinho) << std::endl;
            break;
        case 3:
            break;
        case 2:
            std::cout << "Produtos no carrinho: \n";
            Produto *aux = carrinho.comeco;
            if (aux != nullptr) {
                mostrarProdutos(carrinho);
            } else {
                std::cout << "Seu carrinho está vazio!\n";
            }

            break;

    }
}


//  5.1- CALCULAR CARRINHO
//  5.2- MOSTRAR ITENS DO CARRINHO

// _________________________________FIM MENU DO CLIENTE_______________________________________________



// ________________________________________6 -MENU DO GERENTE_________________________________________
int menugerente(){
    int x=0;
    std::cout<<"_________________________________\n";
    std::cout<<"        MERCADO DO DOMINUS       \n\n";
    std::cout<<"1- Ajustar Preço de Produto\n";
    std::cout<<"2- Inserir Novo Produto\n";
    std::cout<<"3- Retirar Produto\n";
    std::cout<<"4- SAIR\n";
    std::cout<<"_________________________________";
    std::cin>>x;
    return x;
}

void gerente(Local &prateleira){
    switch (menugerente()) {
        case 1:
            int idproduto;
            std::cout << "Digite o ID do produto que você deseja alterar o valor: ";
            std::cin >> idproduto;
            alterarPreco(prateleira, idproduto);
            break;

        case 3:
            int idescolhido;
            std::cout<<"\nDigite o ID do item você deseja retirar da prateleira: ";
            std::cin>>idescolhido;
            retirardaproduto(prateleira, idescolhido);
            std::cout<<"\nO produto com ID " << idescolhido << " foi removido da prateleira!\n";
            break;

        case 4:
            break;

        case 2:
            std::string nome;
            float valor;
            std::cout << "Digite o Nome do produto: ";
            std::cin.ignore();
            getline(std::cin, nome);
            std::cout << "Digite o Preço do produto: ";
            std::cin >> valor;
            inserirProduto(prateleira, (prateleira.tamanho+1), nome, valor);
            break;
    }
}


//  6.1 - ajustar produto;
//  6.2 - inserir novo produto;

// _________________________________FIM MENU DO GERENTE_______________________________________________
