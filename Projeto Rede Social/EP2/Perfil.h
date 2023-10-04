#include <string>
#include <stdexcept>
#include <list>
#include <vector>

using namespace std;

#ifndef PERFIL_H
#define PERFIL_H

#include "Postagem.h"

class Postagem;

class Perfil {
    public:
        Perfil(string nome);
        Perfil(int id, string nome);
        virtual ~Perfil();

        string getNome();

        virtual void adicionar(Perfil* contato); //Precisa modificar o metodo
        virtual void adicionar(Postagem* p); // Precisa modificar o metodo

        virtual list<Postagem*>* getPostagens();
        virtual list<Postagem*>* getPostagensDosContatos(int data);
        virtual list<Postagem*>* getPostagensDosContatos();

        vector<Perfil*>* getContatos();
        //virtual int getQuantidadeDeContatos();

        virtual void imprimir()=0;

        virtual int getId();
        static int getUltimoId();
        static void setUltimoId(int ultimoid);

    protected:
        string nome;
        int maximoDeContatos;
        //int maximoDePostagens; //Talvez suma
        //int quantidadeDeContatos;
        int id;
        static int ultimoid;
        vector<Perfil*>* contatos;
        //Postagem** postagens;
        list<Postagem*>* postagens;
        virtual void adicionarContato2(Perfil* contato);
    private:
};

#endif // PERFIL_H
