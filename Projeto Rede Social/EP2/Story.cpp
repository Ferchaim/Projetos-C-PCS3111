#include "Story.h"
#include <iostream>

using namespace std;

Story::Story(string texto, int data, int dataDeFim, Perfil* autor):
       Postagem(texto,data,autor), dataDeFim (dataDeFim) {

}

int Story::getDataDeFim() {
    return this->dataDeFim;
}

Story::~Story() {

}

void Story::imprimir() {

    cout << "Texto: "<<  texto << " - Data: " << data << " - Data de fim: "<< dataDeFim
    << " - Autor: " << autor->getNome() << endl;

}
