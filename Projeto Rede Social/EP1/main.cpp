#include <iostream>
#include <string>
#include "Perfil.h"
#include "PessoaNaoVerificada.h"
#include "PessoaVerificada.h"
#include "Pagina.h"
#include "Postagem.h"
#include "Story.h"
#include "RedeSocial.h"

using namespace std;

void imprimePerfis(Perfil** listaPerfil,int noPerfis) {
    //Perfil** listaPerfil = Rede->getPerfis();
    for (int i = 0; i < noPerfis; i++){
        PessoaVerificada *veri = dynamic_cast<PessoaVerificada*>(listaPerfil[i]);
        if (veri == NULL) {
            cout << i+1 << ") " << listaPerfil[i]->getNome() << endl;
        } else{
            cout << i+1 << ") " << listaPerfil[i]->getNome() << " (Verificada)"<< endl;
        }
    }
}

int main() {

    RedeSocial *Rede = new RedeSocial();

    bool loop1 = true;
    int opcao1;

    while (loop1 == true){
        cout << "Escolha uma opcao" << endl;
        cout << "1) Cadastrar Pessoa" << endl;
        cout << "2) Cadastrar Pagina" << endl;
        cout << "3) Logar" << endl;
        cout << "0) Terminar" << endl;

        cin >> opcao1;

        if (opcao1 == 1){
            string pessoa1;
            char verficado;
            cout << "Informe os dados da pessoa" << endl;
            cout << "Nome: ";
            cin >> pessoa1;
            cout << "Verificada (s/n)?";
            cin >> verficado;
            if (verficado == 's'){
                string emailPessoa1;
                cout << "Email: ";
                cin >> emailPessoa1;
                PessoaVerificada *pessoaVerificada1 = new PessoaVerificada(pessoa1,emailPessoa1,20,20);
                Rede->adicionar(pessoaVerificada1);
            } else {
                PessoaNaoVerificada *pessoaNaoVerificada1 = new PessoaNaoVerificada(pessoa1,20,20);
                Rede->adicionar(pessoaNaoVerificada1);
            }
        }
        else if (opcao1 == 2) {
            string nomePagina1;
            cout << "Informe os dados da pagina" << endl;
            cout << "Nome: ";
            cin >> nomePagina1;
            cout << "Proprietario:" << endl;
            Perfil** listaPerfil = Rede->getPerfis();
            int nPerfis = Rede->getQuantidadeDePerfis();
            imprimePerfis(listaPerfil,nPerfis);
            int opcao2;
            cout << "Digite o numero ou 0 para cancelar: ";
            cin >> opcao2;
            if (opcao2 != 0){ //Falta colocar algo do tipo "and opcao2 eh menor ou igual ao tamanho de listaPerfil"
                PessoaVerificada *veri = dynamic_cast<PessoaVerificada*>(listaPerfil[opcao2-1]);
                if (veri == NULL) {
                    cout << "Somente pessoas verificadas podem ser proprietarias"<< endl;
                } else {
                    Perfil *Pagina1 = new Pagina(nomePagina1,veri,20,20);
                    Rede->adicionar(Pagina1);
                }
            }
        }
        else if (opcao1 == 3) {
            int opcao3;
            cout << "Escolha um perfil:" << endl;
            Perfil** listaPerfil = Rede->getPerfis();
            int nPerfis = Rede->getQuantidadeDePerfis();
            imprimePerfis(listaPerfil,nPerfis);
            cout << "Digite o numero ou 0 para cancelar: ";
            cin >> opcao3;
            bool loop2 = true;
            if (opcao3 != 0) {
                while (loop2 == true) {
                    Perfil** listaPerfil = Rede->getPerfis();
                    PessoaVerificada *perfilLogado = dynamic_cast<PessoaVerificada*>(listaPerfil[opcao3-1]);
                    if (perfilLogado != NULL){
                        cout << perfilLogado->getNome() << " - " << perfilLogado->getEmail() << endl;
                        cout << "Contatos: " << perfilLogado->getQuantidadeDeContatos() << endl;
                    } else {
                        Pagina *perfilLogado = dynamic_cast<Pagina*>(listaPerfil[opcao3-1]);
                        if (perfilLogado != NULL) {
                            cout << perfilLogado->getNome() << endl;
                            cout << "Proprietario " << perfilLogado->getProprietario() << endl;
                            cout << "Contatos: " << perfilLogado->getQuantidadeDeContatos() << endl;
                        }  else {
                            PessoaNaoVerificada *perfilLogado = dynamic_cast<PessoaNaoVerificada*>(listaPerfil[opcao3-1]);
                            cout << perfilLogado->getNome() << endl;
                            cout << "Contatos: " << perfilLogado->getQuantidadeDeContatos() << endl;
                        }
                    }

                    int opcao4;

                    cout << "---" << endl;
                    cout << "Escolha uma opcao:" << endl;
                    cout << "1) Fazer postagem" << endl;
                    cout << "2) Ver postagem dos contatos" << endl;
                    cout << "3) Adicionar contato" << endl;
                    cout << "0) Desligar" << endl;
                    cin >> opcao4;
                    if (opcao4 == 1) {
                        char storya;
                        int data1;
                        cout << "Story (s/n): ";
                        cin >> storya;
                        cout << "Data: ";
                        cin >> data1;
                        if (storya == 's') {
                            int dataFinal;
                            cout << "Data de fim: ";
                            cin >> dataFinal;
                            string texto1;
                            cout << "Texto: ";
                            cin >> texto1;
                            Story *story1 = new Story(texto1,data1,dataFinal,perfilLogado);
                            perfilLogado->adicionarPostagem(story1);
                        } else {
                            string texto1;
                            cout << "Texto: ";
                            cin >> texto1;
                            Postagem *postagem1 = new Postagem(texto1,data1,perfilLogado);
                            perfilLogado->adicionarPostagem(postagem1);
                        }
                    }
                    else if (opcao4 == 2) {
                        int data2;
                        int qtd;
                        cout << "Data: ";
                        cin >> data2;
                        cout << "Postagens dos ultimos 3 dias: ";
                        Postagem **listarPostagensContatos = perfilLogado->getPostagensDosContatos(data2,qtd);
                        for (int k=0; k < qtd; k++){
                            listarPostagensContatos[k]->imprimir();
                        }
                    }
                    else if (opcao4 == 3) {
                        cout << "Perfil:" << endl;
                        Perfil** listaPerfil = Rede->getPerfis();
                        int nPerfis = Rede->getQuantidadeDePerfis();
                        imprimePerfis(listaPerfil,nPerfis);
                        int opcao5;
                        cin >> opcao5;
                        bool foiPossivel;
                        if (opcao5 == 0) {
                            cout << "Contato nao adicionado" << endl;
                        } else {
                            foiPossivel = perfilLogado->adicionarContato(listaPerfil[opcao5-1]);
                            if (foiPossivel == false) {
                                cout << "Contato nao adicionado" << endl;
                            }
                        }
                    }
                    else if (opcao4 == 0) {
                        loop2 = false;
                    }
                } //while loop2
            } //if opcao3!=0
        } //else if opcao1 == 3
        else if (opcao1 == 0){
            loop1 = false;
        }
    }
    delete Rede;


    return 0;
}
