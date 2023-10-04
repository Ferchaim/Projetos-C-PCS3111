#ifndef PAGINA_H
#define PAGINA_H

#include "Perfil.h"
#include "PessoaVerificada.h"

class Pagina : public Perfil {
    public:
        Pagina(string nome, PessoaVerificada* proprietario);
        Pagina(int id, string nome, PessoaVerificada* proprietario);
        virtual ~Pagina();

        PessoaVerificada* getProprietario();

        virtual void imprimir();
        //string getNome();

    protected:
        PessoaVerificada* proprietario;

    private:
};

#endif // PAGINA_H
