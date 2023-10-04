#ifndef PESSOAVERIFICADA_H
#define PESSOAVERIFICADA_H

#include "Perfil.h"

class PessoaVerificada: public Perfil
{
    public:
        PessoaVerificada(string nome, string email, int maximoDeContatos, int maximoDePostagens);
        PessoaVerificada(string nome, int maximoDeContatos, int maximoDePostagens);
        virtual ~PessoaVerificada();
        string getEmail();
        virtual void imprimir();
    protected:

    private:
        string email;
};

#endif // PESSOAVERIFICADA_H
