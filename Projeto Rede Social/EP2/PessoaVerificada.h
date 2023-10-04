#ifndef PESSOAVERIFICADA_H
#define PESSOAVERIFICADA_H

#include "Pessoa.h"

class PessoaVerificada: public Pessoa {

    public:
        PessoaVerificada(string nome, string email);
        PessoaVerificada(string nome);
        PessoaVerificada(int id, string nome, string email);
        virtual ~PessoaVerificada();
        virtual void imprimir(); //Talvez n tenhamos q declarar esse metodo imprimir
        string getEmail();

    protected:

    private:
        string email;
};

#endif // PESSOAVERIFICADA_H
