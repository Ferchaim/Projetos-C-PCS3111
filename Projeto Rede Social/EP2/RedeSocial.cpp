#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "RedeSocial.h"
#include "PerfilInexistente.h"
#include "PessoaVerificada.h"
#include "Pagina.h"

void RedeSocial::adicionar(Perfil* perfil) {
    vector<Perfil*>::iterator itera = find(this->perfis->begin(),this->perfis->end(),perfil);
    if (itera != this->perfis->end()) {
        throw new invalid_argument("Perfil ja adicionado");
    } else {
        this->perfis->push_back(perfil);
    }
}

vector<Perfil*>* RedeSocial::getPerfis() {
    return perfis;
}

void RedeSocial::imprimir() {
  cout << "==================================" << endl;
  cout << "Rede Social: " << this->perfis->size() << " perfis" << endl;
  cout << "==================================" << endl;
  if (this->perfis->empty()){
    cout << "Sem perfis" << endl;
    cout << "==================================" << endl;
  } else {
    vector<Perfil*>::iterator it = this->perfis->begin();
    while (it != this->perfis->end()) {
        (*it)->imprimir();
        cout << "==================================" << endl;
        it++;
    }
  }
  cout << endl;
}

void RedeSocial::imprimirEstatisticas() {

    int numPerfis = 0;
    int numPessoa = 0;
    int numPessoaVeri = 0;
    int numPag = 0;

    vector<Perfil*>::iterator contaTipo = this->perfis->begin();
    while (contaTipo != this->perfis->end()) {
        if (PessoaVerificada* varTemp=dynamic_cast<PessoaVerificada*>(*contaTipo)) {
            numPessoaVeri += 1;
        }
        else if (Pessoa* varTemp=dynamic_cast<Pessoa*>(*contaTipo)) {
            numPessoa += 1;
        }
        else if (Pagina* varTemp=dynamic_cast<Pagina*>(*contaTipo)) {
            numPag += 1;
        }
        else {
            numPerfis += 1;
        }
        contaTipo++;
    }

    cout << "Pessoa: " << numPessoa << endl;
    cout << "PessoaVerificada: " << numPessoaVeri << endl;
    cout << "Pagina: " << numPag<< endl;
    cout << "Perfil: " << numPerfis << endl;
}

RedeSocial::RedeSocial() {
    this->perfis = new vector<Perfil*>();
}

RedeSocial::~RedeSocial() {
    cout << "Destrutor de RedeSocial: " << this->perfis->size() << " perfis" << endl;

    vector<Perfil*>::iterator deletorPerfRede = this->perfis->begin();
    while (deletorPerfRede != this->perfis->end()) {
        delete (*deletorPerfRede);
        deletorPerfRede++;
    }
    cout << "RedeSocial deletada " << endl;
} //talvez nao esteja completamente correto

Perfil* RedeSocial::getPerfil(int id) {

    if (this->perfis->size() == 0) {
        throw new PerfilInexistente();
    } else {
        vector<Perfil*>::iterator iterPerfil = this->perfis->begin();
        while (iterPerfil != this->perfis->end()) {
            if ((*iterPerfil)->getId() == id) {
                return (*iterPerfil);
            }
            iterPerfil++;
        }
        throw new PerfilInexistente();
    }
}
