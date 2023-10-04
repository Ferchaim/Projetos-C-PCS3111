#include <iostream>
#include "RedeSocial.h"
#include "PessoaNaoVerificada.h"
#include "PessoaVerificada.h"
#include "Pagina.h"

bool RedeSocial::adicionar(Perfil* perfil)
{
    if (this->quantidadeDePerfis < capacidade){
        this->perfis[quantidadeDePerfis] = perfil;
        quantidadeDePerfis += 1;
        return true;
    } else
        return false;
}

Perfil** RedeSocial::getPerfis()
{
    return perfis;
}

int RedeSocial::getQuantidadeDePerfis()
{
    return this->quantidadeDePerfis;
}

void RedeSocial::imprimir()
{
  cout << "==================================" << endl;
  cout << "Rede Social: " << quantidadeDePerfis << " perfis" << endl;
  cout << "==================================" << endl;
  if (quantidadeDePerfis == 0){
    cout << "Sem perfis" << endl;
    cout << "==================================" << endl;
  } else {
    for (int i = 0; i < quantidadeDePerfis; i++){
      perfis[i]->imprimir();
      cout << "==================================" << endl;
    }
  }
  cout << endl;
}

void RedeSocial::imprimirEstatisticas()
{
    int cVerificado=0;
    int cNVerificado=0;
    int contPa=0;
    int contPe=0;

     for (int i = 0; i < quantidadeDePerfis; i++){

            if(PessoaVerificada* temp=dynamic_cast<PessoaVerificada*>(perfis[i])){
                cVerificado++;
            }

            else if(PessoaNaoVerificada* temp=dynamic_cast<PessoaNaoVerificada*>(perfis[i])){
                cNVerificado++;
            }
            else if(Pagina* temp=dynamic_cast<Pagina*>(perfis[i])){
                contPa++;
            }
            else{
                contPe++;
            }
    }

    cout << "PessoaVerificada: " << cVerificado << endl;
            cout << "PessoaNaoVerificada: " << cNVerificado << endl;
                  cout << "Pagina: " << contPa<< endl;
                  cout << "Perfil: " << contPe << endl;
}

RedeSocial::RedeSocial()
{
    this->quantidadeDePerfis = 0;
    this->perfis = new Perfil*[capacidade];
}

RedeSocial::~RedeSocial()
{
    cout << "Destrutor de RedeSocial: " << quantidadeDePerfis << " perfis" << endl;

    for (int i = 0; i < quantidadeDePerfis; i++)
        delete perfis[i];

    cout << "RedeSocial deletada " << endl;
}
