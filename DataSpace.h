// Objetos que estao a venda
struct Produto {
    Produto *anterior = nullptr;
    int ID = 0;
    std::string objeto;
    float valordoproduto;
    Produto * proximo = nullptr;
};

// locas a ser posto os produtos (linha)
struct Local{
    Produto *comeco = nullptr;
    Produto *fim = nullptr;
    int contprodutos = 0;
    float valortotal = 0;
};

//Função para inserir um novo no na lista (produto na prateleira)
bool inserirProduto(Local &localdesejado,int idNovo,std::string produntonovo, float valordesejado){
    Produto *novo = new Produto;
    novo->ID = idNovo;
    novo->objeto = produntonovo;
    novo->valordoproduto = valordesejado;
    localdesejado.valortotal = localdesejado.valortotal + valordesejado;

    if (localdesejado.comeco == nullptr)
    {
        localdesejado.comeco = novo;
        localdesejado.fim = novo;
        localdesejado.contprodutos++;
        return true;
    }
    else if(idNovo < localdesejado.comeco->ID){
        novo->proximo = localdesejado.comeco;
        localdesejado.comeco->anterior = novo;
        localdesejado.comeco = novo;
        localdesejado.contprodutos++;
        return true;
    }
    else if (idNovo > localdesejado.fim->ID){
        localdesejado.fim->proximo = novo;
        novo->anterior = localdesejado.fim;
        localdesejado.fim= novo;
        localdesejado.contprodutos++;
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
                localdesejado.contprodutos++;
                return true;
            }
            aux = aux->proximo;
        }
        return false;
    }
}

template<class PouC>
bool retirardaproduto(PouC &localdesejado, int idDesejado){
    if( localdesejado.comeco == nullptr ) return false;

    Produto *aux = localdesejado.comeco;
    while( aux != nullptr && idDesejado != aux->ID ){
        aux = aux->proximo;

        if( aux == nullptr ) {return false;}

        if( aux == localdesejado.comeco && aux == localdesejado.fim ){ // Caso 1
            localdesejado.valortotal = localdesejado.valortotal - aux->valordoproduto;
            localdesejado.comeco = nullptr;
            localdesejado.fim = nullptr;
            delete aux;
            return true;
        }
        else if( aux == localdesejado.comeco ){ // Caso 2
            localdesejado.valortotal = localdesejado.valortotal - aux->valordoproduto;
            localdesejado.comeco = aux->proximo;
            localdesejado.comeco->anterior = nullptr;
            delete aux;
            return true;
        }
        else if( aux == localdesejado.fim ){ // Caso 3
            localdesejado.valortotal = localdesejado.valortotal - aux->valordoproduto;
            Produto *ant = aux->anterior;
            ant->proximo = nullptr;
            localdesejado.fim = ant;
            delete aux;
            return true;
        }
        // Caso 4
        else {
            localdesejado.valortotal = localdesejado.valortotal - aux->valordoproduto;
            Produto *ant = aux->anterior;
            Produto *prox = aux->proximo;
            ant->proximo = prox;
            prox->anterior = ant;
            delete aux;
            return true;
        }
    }
}

void buscarnanaprateleira(Local lista, int idabuscar){
    Produto *encontrar = lista.comeco;
    while(encontrar != nullptr){
        if(idabuscar == encontrar->ID)
        {

        }
        else{
            encontrar = encontrar->proximo;
        }

    }
}

//mostra todos os produtos da prateleira escolhida
void mostrarProdutosdaPrat (Local Prateleira){
    Produto *aux = Prateleira.comeco;
    while (aux != nullptr){
        std::cout<<"\nID: "<<aux->ID<<" | Produto: "<<aux->objeto<<" | Valor: "<< aux->valordoproduto<<"\n";
        aux= aux->proximo;
    }
}

template<class PouC>
float getvalor(PouC listadesejada){
    return listadesejada.valortotal;
}
