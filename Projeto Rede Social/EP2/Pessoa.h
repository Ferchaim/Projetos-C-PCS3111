#ifndef PESSOA_H
#define PESSOA_H

#include "Perfil.h"

class Pessoa: public Perfil {
    public:
        Pessoa(string nome);
        Pessoa(int id, string nome);

        virtual ~Pessoa();

        virtual void imprimir() override;
        /*
        virtual int getId() override;
        virtual string getNome(); */
    protected:

    private:
};

#endif // PESSOA_H
