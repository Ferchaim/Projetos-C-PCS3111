#include <iostream>
#include "Story.h"

Story::Story(string texto, int data, int dataDeFim, Perfil* autor):
       Postagem(texto,data,autor), dataDeFim (dataDeFim) {

}

int Story::getDataDeFim() {
    return this->dataDeFim;
}

void Story::imprimir() {
    cout << "Texto: " << this->getTexto() << " - Data: " << this->getData() << " - Data De Fim: " << this->getDataDeFim() << " - Autor: " << this->getAutor()->getNome() << endl;
}

Story::~Story() {

}
