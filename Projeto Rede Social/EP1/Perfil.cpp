#include <iostream>
#include "Perfil.h"

Perfil::Perfil(string nome, int maximoDeContatos, int maximoDePostagens)
{
    this->nome = nome;
    this->maximoDeContatos = maximoDeContatos;
    this->maximoDePostagens = maximoDePostagens;
    this->contatos = new Perfil*[maximoDeContatos];
    this->postagens = new Postagem*[maximoDePostagens];
    this->quantidadeDePostagens = 0;
    this->quantidadeDeContatos = 0;
}

string Perfil::getNome()
{
    return this->nome;
}

bool Perfil::adicionarContato(Perfil* contato) {
    bool presente = false;
    for (int u = 0; u < quantidadeDeContatos; u++){
        if (this->contatos[u] == contato)
            presente = true;
    }

    if (presente == false) {
        if (this->quantidadeDeContatos < maximoDeContatos) {
            this->contatos[quantidadeDeContatos] = contato;
            quantidadeDeContatos += 1;
            contato->adicionarContato(this);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Perfil::adicionarPostagem(Postagem* p)
{
    if (this->quantidadeDePostagens < maximoDePostagens) {
        this->postagens[quantidadeDePostagens] = p;
        this->quantidadeDePostagens += 1;
        return true;
    } else {
        return false;
    }
}

Postagem** Perfil::getPostagens()
{
    return this->postagens;
}

Postagem** Perfil::getPostagensDosContatos(int data, int& quantidade) {
    Postagem **listaDePostagens;
    int quantidadeAtual = 0;
    Perfil **listagemContatos = this->getContatos();
    for (int i = 0; i < quantidadeDeContatos ; i++){
        Postagem **postagensContatoAtual = listagemContatos[i]->getPostagens();
        for (int j = 0; j < quantidadeDePostagens; j++) {
            if ((postagensContatoAtual[j]->getData() <= data) && (postagensContatoAtual[j]->getData() >= data-3) ){
                    listaDePostagens[quantidadeAtual] = postagensContatoAtual[j];
                    quantidadeAtual += 1;
            }
        }
    }
    quantidade = quantidadeAtual;
    return listaDePostagens;
}

int Perfil::getQuantidadeDePostagens()
{
    return this->quantidadeDePostagens;
}

Perfil** Perfil::getContatos()
{
    return this->contatos;
}

int Perfil::getQuantidadeDeContatos()
{
    return this->quantidadeDeContatos;
}

void Perfil::imprimir() {
	cout << endl << "Nome: " << nome << endl;
	cout << "Numero de postagens feitas: " << quantidadeDePostagens << endl;
	for (int i = 0; i < quantidadeDePostagens; i++)
		cout << "Postagens na data: " << postagens[i]->getData()
		     << " - Texto: " << postagens[i]->getTexto() << endl;
	if (quantidadeDeContatos == 0)
		cout << "Sem contatos " << endl;
	else {
		for (int i = 0; i < quantidadeDeContatos; i++) {
			for (int j = 0; j < contatos[i]->getQuantidadeDePostagens(); j++)
				cout << "Postagens na data " << contatos[i]->getPostagens()[j]->getData()
				     << " do contato "<< contatos[i]->getNome()
				     << " - Texto: " << contatos[i]->getPostagens()[j]->getTexto() << endl;
		}
	}
}

Perfil::~Perfil()
{
    cout << "Destruidor de perfil: " << nome << " - Quantidade de postagens feitas: "
         << quantidadeDePostagens << endl;

    //Destruidor de postagens
     for (int i = 0; i < quantidadeDePostagens; i++)
        delete postagens[i];

    //Destruidor dos vetores:
    delete[] postagens;
    delete[] contatos;

    cout << "Perfil deletado" << endl;

}
