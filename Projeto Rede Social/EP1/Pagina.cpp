#include <iostream>
#include "Pagina.h"

Pagina::Pagina(string nome, PessoaVerificada* proprietario, int maximoDeContatos, int maximoDePostagens):
    Perfil(nome, maximoDeContatos, maximoDePostagens), proprietario (proprietario)
{
    this->adicionarContato(proprietario);
}

Pagina::~Pagina()
{
    cout << "Pagina destruida!" << endl;
}

PessoaVerificada* Pagina::getProprietario()
{
    return this->proprietario;
}
