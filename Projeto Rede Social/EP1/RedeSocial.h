#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include "Perfil.h"
#include "Postagem.h"

class RedeSocial {

    public:
        RedeSocial();
        virtual ~RedeSocial();

        virtual bool adicionar(Perfil* perfil);
        virtual Perfil** getPerfis();
        virtual int getQuantidadeDePerfis();

        virtual void imprimir();
        virtual void imprimirEstatisticas();
    protected:

    private:
        Perfil** perfis;
        const int capacidade = 100;
        int quantidadeDePerfis = 0;

};

#endif // REDESOCIAL_H
