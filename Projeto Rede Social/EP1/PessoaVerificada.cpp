#include "PessoaVerificada.h"
#include <iostream>

PessoaVerificada::PessoaVerificada(string nome,
                                   string email,
                                   int maximoDeContatos,
                                   int maximoDePostagens) : Perfil(nome, maximoDeContatos, maximoDePostagens),
                                   email (email)

{

}

PessoaVerificada::PessoaVerificada(string nome,
                                   int maximoDeContatos,
                                   int maximoDePostagens) : Perfil(nome, maximoDeContatos, maximoDePostagens)
{

    email = "email.padrao@usp.br";
}


string PessoaVerificada::getEmail()
{
    return this->email;
}

void PessoaVerificada::imprimir()
{
    cout << email << endl << endl;
     Perfil::imprimir();

}

PessoaVerificada::~PessoaVerificada()
{

}
