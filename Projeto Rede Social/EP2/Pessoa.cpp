#include "Pessoa.h"
#include <iostream>

Pessoa::Pessoa(string nome) :
               Perfil(nome) {
}
/*
Pessoa::Pessoa(int id, string nome) { //Usado pela persistencia

    this->id = id;
    this->nome = nome;

} */


Pessoa::Pessoa(int id, string nome):
                Perfil(id,nome){
//Usado pela persistencia
}


Pessoa::~Pessoa() {
    //dtor
}


void Pessoa::imprimir() {
    Perfil::imprimir();
    //cout << "Nome: " << getNome()<<"- id: " << getId() << endl;
}


/*
int Pessoa::getId(){
    return this->id;
}

string Pessoa::getNome() {
    return this->nome;
} */
