#include <iostream>
#include "Pagina.h"

Pagina::Pagina(string nome, PessoaVerificada* proprietario):
    Perfil(nome), proprietario (proprietario) {
    this->adicionar(proprietario);
}


Pagina::Pagina(int id,string nome, PessoaVerificada* proprietario): //persistencia
    Perfil(id,nome), proprietario (proprietario) {

}

Pagina::~Pagina() {
    cout << "Pagina destruida!" << endl;
}

void Pagina::imprimir() {
    cout << "Nome: " << getNome() << " - id: " << Perfil::getId() << " - Proprietario: "
        << proprietario->getNome() << endl;
}

PessoaVerificada* Pagina::getProprietario() {
    return this->proprietario;
}

/*
string Pagina::getNome() {

    return this->nome;
} */
