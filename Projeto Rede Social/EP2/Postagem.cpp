#include <iostream>
#include "Postagem.h"
#include "Story.h"

Postagem::~Postagem() {
    cout << "Destruidor de postagem: " << texto << endl;
}
Postagem::Postagem(string texto, int data, Perfil* autor) {
    this->texto = texto;
    this->data = data;
    this->autor = autor;
}

Perfil* Postagem::getAutor() {
    return this->autor;
}

string Postagem::getTexto() {
    return this->texto;
}

int Postagem::getData() {
    return this->data;
}

void Postagem::imprimir() {

    cout << "Texto: "<<  texto << " - Data: " << data << " - Autor: " << autor->getNome() << endl;

}
