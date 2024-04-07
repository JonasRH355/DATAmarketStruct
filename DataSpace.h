// Objetos que estao a venda
struct Produto {
    Produto *anterior = nullptr;
    int ID;
    std::string nome;
    float valordoproduto;
    Produto * proximo = nullptr;
};

// locas a ser posto os produtos (linha)
struct Local{
    Produto *comeco = nullptr;
    Produto *fim = nullptr;
    int tamanho = 0;
    float valortotal = 0;
};

//Função para inserir um novo no na lista (produto na prateleira)
bool inserirProduto(Local &localdesejado,int idNovo,std::string produntonovo, float valordesejado){
    Produto *novo = new Produto;
    novo->ID = idNovo;
    novo->nome = produntonovo;
    novo->valordoproduto = valordesejado;

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
        localdesejado.comeco = nullptr;
        localdesejado.fim = nullptr;
        delete aux;
        return true;
    }
    if( aux == localdesejado.comeco ){ // Caso 2
        localdesejado.comeco = aux->proximo;
        localdesejado.comeco->anterior = nullptr;
        delete aux;
        return true;
    }
    Produto *ant = aux->anterior;
    if( aux == localdesejado.fim ){ // Caso 3
        ant->proximo = nullptr;
        localdesejado.fim = ant;
        delete aux;
        return true;
    }
    // Caso 4
    Produto *prox = aux->proximo;
    ant->proximo = prox;
    prox->anterior = ant;
    delete aux;
    return true;
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
