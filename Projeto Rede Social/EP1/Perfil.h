#include <string>

using namespace std;

#ifndef PERFIL_H
#define PERFIL_H

#include "Postagem.h"

class Postagem;

class Perfil {
    public:
        Perfil(string nome, int maximoDeContatos, int maximoDePostagens);
        virtual ~Perfil();

        string getNome();

        virtual bool adicionarContato(Perfil* contato);
        virtual bool adicionarPostagem(Postagem* p);

        virtual Postagem** getPostagens();
        virtual Postagem** getPostagensDosContatos(int data, int &quantidade);
        virtual int getQuantidadeDePostagens();

        virtual Perfil** getContatos();
        virtual int getQuantidadeDeContatos();

        virtual void imprimir();

    protected:
        string nome;
        int maximoDeContatos;
        int maximoDePostagens;
        int quantidadeDeContatos;
        int quantidadeDePostagens;
        Perfil** contatos;
        Postagem** postagens;
    private:
};

#endif // PERFIL_H
