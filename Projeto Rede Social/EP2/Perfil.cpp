#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "Perfil.h"
#include "Postagem.h"

using namespace std;

int Perfil::ultimoid = 0;

Perfil::Perfil(string nome) {
    this->nome = nome;
    //this->maximoDeContatos = maximoDeContatos;
    //this->maximoDePostagens = maximoDePostagens;
    //this->contatos = new Perfil*[maximoDeContatos];
    this->contatos = new vector<Perfil*>();
    this->postagens = new list<Postagem*>();
    //this->quantidadeDePostagens = 0;
    //this->quantidadeDeContatos = 0;
    ultimoid++;
    this->id = Perfil::getUltimoId();
} //blz

Perfil::Perfil(int id, string nome) { //usado apenas pela persistencia
    this->nome = nome;
    this->contatos = new vector<Perfil*>();
    this->postagens = new list<Postagem*>();
    //ultimoid++; Nao sei se vai ter q ter isso
    this->id = id;
}

string Perfil::getNome() {
    return this->nome;
} //blz

void Perfil::adicionar(Perfil* contato) {
    if (contato == this) {
        throw new invalid_argument("Perfil adicionando ele mesmo");
    } //acho que isso esta correto

    vector<Perfil*>::iterator ite = find(this->contatos->begin(),this->contatos->end(),contato);
    if (ite != this->contatos->end()) {
        throw new invalid_argument("Perfil ja adicionado");
    } else {
        this->contatos->push_back(contato);
        contato->adicionarContato2(this);
    }
}
    /*void Perfil::adicionarContato(Perfil* contato) {
        if (contato == this) {
            throw new invalid_argument("Perfil adicionando ele mesmo");
    } //acho que isso esta correto
        bool presente = false;
        for (int u = 0; u < quantidadeDeContatos; u++){
            if (this->contatos[u] == contato)
            presente = true;
    }

        if (presente == false) {
            if (this->quantidadeDeContatos < maximoDeContatos) {
            this->contatos[quantidadeDeContatos] = contato;
            contato->adicionarContato2(this);
            } else {
                throw new overflow_error("Maximo de contatos");
            }
        } else {
            throw new invalid_argument("Perfil ja adicionado");
        }
}*/
 //precisa modificar

void Perfil::adicionarContato2(Perfil* contato) {
    if (contato == this) {
        throw new invalid_argument("Perfil adicionando ele mesmo");
    } //acho que isso esta correto

    vector<Perfil*>::iterator ite = find(this->contatos->begin(),this->contatos->end(),contato);
    if (ite != this->contatos->end()) {
        throw new invalid_argument("Perfil ja adicionado");
    } else {
        this->contatos->push_back(contato);
    }
}

/*
void Perfil::adicionarContato2(Perfil* contato) {
    if (contato == this) {
        throw new invalid_argument("Perfil adicionando ele mesmo");
    }

    bool presente = false;
    for (int u = 0; u < quantidadeDeContatos; u++){
        if (this->contatos[u] == contato)
            presente = true;
    }

    if (presente == false) {
        if (this->quantidadeDeContatos < maximoDeContatos) {
            this->contatos[quantidadeDeContatos] = contato;
            quantidadeDeContatos += 1;
            //contato->adicionarContato2(this);
        } else {
            throw new overflow_error("Maximo de contatos");
        }
    } else {
        throw new invalid_argument("Perfil ja adicionado");
    }
} */

void Perfil::adicionar(Postagem* p) {
    this->postagens->push_back(p);
} //alterado

list<Postagem*>* Perfil::getPostagens() {
    return this->postagens;
} //alterado

list<Postagem*>* Perfil::getPostagensDosContatos(int data) {

    list<Postagem*>* listaDePostagens = new list<Postagem*>;
    //Perfil **listagemContatos = this->getContatos();
    vector<Perfil*>::iterator i = this->contatos->begin();
    while (i != this->contatos->end()){
        list<Postagem*>* postagensContatoAtual = (*i)->getPostagens();
        list<Postagem*>::iterator j = postagensContatoAtual->begin();
        while (j != postagensContatoAtual->end()) {
            int dataDeAgora;
            dataDeAgora = (*j)->getData();
             if ((dataDeAgora <= data) && (dataDeAgora >= data-3))
                listaDePostagens->push_back(*j);
            j++;
        }
        i++;
    }
    return listaDePostagens;
} //alterado

list<Postagem*>* Perfil::getPostagensDosContatos() {

    list<Postagem*>* listaDePostagens = new list<Postagem*>;
    //Perfil **listagemContatos = this->getContatos();
    vector<Perfil*>::iterator i = this->contatos->begin();
    while (i != this->contatos->end()){
        list<Postagem*>* postagensContatoAtual = (*i)->getPostagens();
        list<Postagem*>::iterator j = postagensContatoAtual->begin();
        while (j != postagensContatoAtual->end()) {
            listaDePostagens->push_back(*j);
            j++;
        }
        i++;
    }
    return listaDePostagens;
} //alterado

vector<Perfil*>* Perfil::getContatos() {
    return this->contatos;
}


void Perfil::imprimir() {
    cout << endl << "Nome: " << nome << " - id: " << Perfil::getId() <<endl;
    cout << "Numero de postagens feitas: " << this->postagens->size() << endl;

    list<Postagem*>::iterator j = postagens->begin();
    while (j != postagens->end()) {
        cout << "Postagens na data " << (*j)->getData()
         << " - Texto: " << (*j)->getTexto() << endl;
         j++;
    }

    if (this->contatos->empty())
        cout << "Sem contatos " << endl;
    else {
        vector<Perfil*>::iterator i = this->contatos->begin();
        while (i != this->contatos->end()){
            list<Postagem*>::iterator k = (*i)->getPostagens()->begin();
            while(k != (*i)->getPostagens()->end()) {
                cout << "Postagens na data "
                << (*k)->getData()
                << " do contato " << (*i)->getNome()
                << " - Texto: " << (*k)->getTexto()
                << endl;
                k++;
            }
            i++;
        }

    }
} //alterado

Perfil::~Perfil() {
    cout << "Destruidor de perfil: " << nome << " - Quantidade de postagens feitas: "
         << postagens->size() << endl;

    //Destruidor de postagens
    list<Postagem*>::iterator i = postagens->begin();
    while (i != postagens->end()) {
        delete(*i);
        i++;
    }
    /*
     for (int i = 0; i < postagens->size(); i++)
        delete (postagens*)[i]; */

    //Destruidor dos vetores:
    delete postagens;
    delete contatos;

    cout << "Perfil deletado" << endl;

} //alterado
int Perfil::getId() {
    return this->id;
} //blz

int Perfil::getUltimoId() { //Certo
    return ultimoid;
} //blz

void Perfil::setUltimoId(int ultimoid) { //usado apenas pela persistencia
    Perfil::ultimoid = ultimoid;
}
