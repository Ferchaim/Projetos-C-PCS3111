#include <string>
using namespace std;

#ifndef POSTAGEM_H
#define POSTAGEM_H

#include "Perfil.h"

class Perfil;

class Postagem {
    public:
        Postagem(string texto, int data, Perfil* autor);
        virtual ~Postagem();

        Perfil* getAutor();
        string getTexto();
        int getData();
        virtual void imprimir();

    protected:
        string texto;
        Perfil* autor;
        int data;

    private:
};

#endif // POSTAGEM_H
