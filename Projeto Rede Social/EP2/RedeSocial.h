#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include "Perfil.h"
#include "Postagem.h"

class RedeSocial {

    public:
        RedeSocial();
        virtual ~RedeSocial();

        virtual void adicionar(Perfil* perfil);
        virtual vector<Perfil*>* getPerfis();

        virtual void imprimir();
        virtual void imprimirEstatisticas();

        Perfil* getPerfil(int id);
    protected:

    private:
        vector<Perfil*>* perfis;
        //const int capacidade = 100;
        //int quantidadeDePerfis = 0;

};

#endif // REDESOCIAL_H
