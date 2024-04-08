#include <fstream>
#include <sstream>

struct Produto {
    Produto *anterior = nullptr;
    int ID;
    std::string nome;
    float valordoproduto;
    Produto * proximo = nullptr;
};

struct Local{
    Produto *comeco = nullptr;
    Produto *fim = nullptr;
    int tamanho = 0;
    float valortotal = 0;
};

bool inserirProduto(Local &localdesejado,int idNovo,std::string produntonovo, float valordesejado){
    Produto *novo = new Produto;
    novo->ID = idNovo;
    novo->nome = produntonovo;
    novo->valordoproduto = valordesejado;
    localdesejado.valortotal = localdesejado.valortotal + valordesejado;

    if (localdesejado.comeco == nullptr)
    {
        localdesejado.comeco = novo;
        localdesejado.fim = novo;
        localdesejado.tamanho++;
        return true;
    }
    else if(idNovo < localdesejado.comeco->ID){
        novo->proximo = localdesejado.comeco;
        localdesejado.comeco->anterior = novo;
        localdesejado.comeco = novo;
        localdesejado.tamanho++;
        return true;
    }
    else if (idNovo > localdesejado.fim->ID){
        localdesejado.fim->proximo = novo;
        novo->anterior = localdesejado.fim;
        localdesejado.fim= novo;
        localdesejado.tamanho++;
        return true;
    }
    else {
        Produto *aux = localdesejado.comeco;
        while (aux != nullptr){
            if (aux->ID < idNovo && idNovo < aux->proximo->ID)
            {
                novo->anterior = aux;
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                novo->proximo->anterior = novo;
                localdesejado.tamanho++;
                return true;
            }
            aux = aux->proximo;
        }
        return false;
    }
}

bool retirardaproduto(Local &localdesejado, int idDesejado){
    if( localdesejado.comeco == nullptr ) return false;

    Produto *aux = localdesejado.comeco;
    while( aux != nullptr && idDesejado != aux->ID ){
        aux = aux->proximo;
    }
    if( aux == nullptr ) return false;

    if( aux == localdesejado.comeco && aux == localdesejado.fim ){ // Caso 1
        localdesejado.valortotal = localdesejado.valortotal - aux->valordoproduto;
        localdesejado.comeco = nullptr;
        localdesejado.fim = nullptr;
        delete aux;
        return true;
    }
    if( aux == localdesejado.comeco ){ // Caso 2
        localdesejado.valortotal = localdesejado.valortotal - aux->valordoproduto;
        localdesejado.comeco = aux->proximo;
        localdesejado.comeco->anterior = nullptr;
        delete aux;
        return true;
    }
    Produto *ant = aux->anterior;
    if( aux == localdesejado.fim ){ // Caso 3
        localdesejado.valortotal = localdesejado.valortotal - aux->valordoproduto;
        ant->proximo = nullptr;
        localdesejado.fim = ant;
        delete aux;
        return true;
    }
    // Caso 4
    Produto *prox = aux->proximo;
    localdesejado.valortotal = localdesejado.valortotal - aux->valordoproduto;
    ant->proximo = prox;
    prox->anterior = ant;
    delete aux;
    return true;
}

void alterarPreco(Local lista, int idabuscar){
    Produto *encontrar = lista.comeco;
    while(encontrar != nullptr){
        if(idabuscar == encontrar->ID)
        {
            float novovalor = 0;
            std::cout << "\nID do produto:" << encontrar->ID << std::endl

            << "Nome do produto:" << encontrar->nome << std::endl
            << "Valor do produto: " << encontrar->valordoproduto << std::endl
            << "Novo valor do produto: " << novovalor;
            encontrar->valordoproduto = novovalor;

                      << "Nome do produto:" << encontrar->nome << std::endl
                      << "Valor do produto: " << encontrar->valordoproduto << std::endl
                      << "Novo valor do produto: ";
            std::cin>>novovalor;
            encontrar->valordoproduto = novovalor;
            system("cls");
            break;

        }
        else{
            encontrar = encontrar->proximo;
        }

    }
}

void mostrarProdutos (Local Prateleira){
    Produto *aux = Prateleira.comeco;
    while (aux != nullptr){
        std::cout<<"\nID: "<<aux->ID<<" | Produto: "<<aux->nome<<" | Valor: "<< aux->valordoproduto<<"\n";
        aux= aux->proximo;
    }

}

float getvalor(Local listadesejada){
    return listadesejada.valortotal;
}

void exportarProdutos(const Local& prateleira, const std::string& nomeDoArquivo) {

    std::ofstream arquivo(nomeDoArquivo);

    Produto* atual = prateleira.comeco;

    while (atual != nullptr) {
        arquivo << "ID: " << atual->ID << " | Produto: " << atual->nome << " | Valor: " << atual->valordoproduto << "\n";
        atual = atual->proximo;
    }

    arquivo.close();
}

void importarProdutos(Local& prateleira, const std::string& nomeDoArquivo) {
    std::ifstream arquivo(nomeDoArquivo);

    std::string linha;
    while (getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string parte;
        int ID;
        std::string nome;
        float valor;

        getline(iss, parte, '|');
        std::istringstream(parte.substr(parte.find(":") + 2)) >> ID;

        getline(iss, parte, '|');
        nome = parte.substr(parte.find(":") + 2);

        getline(iss, parte);
        std::istringstream(parte.substr(parte.find(":") + 2)) >> valor;

        inserirProduto(prateleira, ID, nome, valor);
    }

    arquivo.close();
}
