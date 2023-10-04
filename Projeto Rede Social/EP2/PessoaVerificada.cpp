#include "PessoaVerificada.h"
#include <iostream>

PessoaVerificada::PessoaVerificada(string nome,
                                   string email
                                   ):
                                   Pessoa(nome),
                                   email (email) {

}

PessoaVerificada::PessoaVerificada(string nome
                                   ) : Pessoa(nome),
                                       email ("email.padrao@usp.br") {

}

/*
PessoaVerificada::PessoaVerificada(int id, string nome, string email) { //persistencia

    this->id = id;
    this->nome = nome;
    this->email = email;

} */


PessoaVerificada::PessoaVerificada(int id, string nome, string email) :
                                   Pessoa (id, nome),
                                   email (email){

}

PessoaVerificada::~PessoaVerificada() {

}

string PessoaVerificada::getEmail() {
    return this->email;
}



void PessoaVerificada::imprimir() {
    cout << "Email: " << email << endl;
    Perfil::imprimir();
}


