#include "RedeSocial.h"
#include "Perfil.h"
#include "PerfilInexistente.h"
#include "Postagem.h"
#include  "PessoaVerificada.h"
#include "Pagina.h"
#include "Story.h"
#include "Pessoa.h"
#include "PersistenciaDaRede.h"
#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

void imprimePerfis(vector<Perfil*>*listaPerfil, string mensagem) {
    //Perfil** listaPerfil = Rede->getPerfis();
    cout << mensagem << endl;
    vector<Perfil*>::iterator iteradorlistaPerfil = listaPerfil->begin();
    while (iteradorlistaPerfil != listaPerfil->end()) {
        PessoaVerificada *veri1 = dynamic_cast<PessoaVerificada*>(*iteradorlistaPerfil);
        if (veri1 != NULL) {
            cout << veri1->getId() << ") " << veri1->getNome() << " (Verificada)"<< endl;
        } else {
            cout << (*iteradorlistaPerfil)->getId() << ") " << (*iteradorlistaPerfil)->getNome() << endl;
        }
        iteradorlistaPerfil++;
    }
    cout << "Digite o id ou 0 para cancelar: " << endl;
}

int main() {


    string arquivo;
    cout << "Arquivo: ";
    cin >> arquivo;

    //RedeSocial *Rede = new RedeSocial();
    PersistenciaDaRede *Persiste = new PersistenciaDaRede(arquivo);

    RedeSocial *Rede = Persiste->carregar();

    //RedeSocial *Rede = new RedeSocial();

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
                PessoaVerificada *pessoaVerificada1 = new PessoaVerificada(pessoa1,emailPessoa1);
                //PessoaVerificada *pessoaVerificada1 = new PessoaVerificada(pessoa1,emailPessoa1,20,20);
                Rede->adicionar(pessoaVerificada1);
            } else {
                Pessoa *pessoaNV1 = new Pessoa(pessoa1);
                //PessoaNaoVerificada *pessoaNaoVerificada1 = new PessoaNaoVerificada(pessoa1,20,20);
                Rede->adicionar(pessoaNV1);
            }
        }
        else if (opcao1 == 2) {
            string nomePagina1;
            cout << "Informe os dados da pagina" << endl;
            cout << "Nome: ";
            cin >> nomePagina1;
            //cout << "Proprietario:" << endl;
            vector<Perfil*> *listaPerfil1 = Rede->getPerfis();
            imprimePerfis(listaPerfil1, "Proprietario: ");
            //delete listaPerfil1; //Add agr
            int opcao2;
            cin >> opcao2;
            if (opcao2 != 0){ //Falta colocar algo do tipo "and opcao2 eh menor ou igual ao tamanho de listaPerfil"
                Perfil *proprietario1 = Rede->getPerfil(opcao2);
                PessoaVerificada *veri2 = dynamic_cast<PessoaVerificada*>(proprietario1);
                if (veri2 == NULL) {
                    cout << "Somente pessoas verificadas podem ser proprietarias"<< endl;
                } else {
                    Perfil *Pagina1 = new Pagina(nomePagina1,veri2);
                    //Perfil *Pagina1 = new Pagina(nomePagina1,veri,20,20);
                    Rede->adicionar(Pagina1);
                }
            }
        }
        else if (opcao1 == 3) {
            int opcao3;
            //cout << "Escolha um perfil:" << endl;
            vector<Perfil*> *listaPerfil2 = Rede->getPerfis();
            imprimePerfis(listaPerfil2, "Escolha um perfil: ");
            //delete listaPerfil2; //add agr
            cin >> opcao3;
            bool loop2 = true;
            if (opcao3 != 0) {
                while (loop2 == true) {
                    //Perfil** listaPerfil = Rede->getPerfis();
                    PessoaVerificada *perfilLogado = dynamic_cast<PessoaVerificada*>(Rede->getPerfil(opcao3));
                    if (perfilLogado != NULL){
                        cout << perfilLogado->getNome() << " - " << perfilLogado->getEmail() << endl;
                        cout << "Contatos: " << perfilLogado->getContatos()->size() << endl;
                    } else {
                        Pagina *perfilLogado = dynamic_cast<Pagina*>(Rede->getPerfil(opcao3));
                        if (perfilLogado != NULL) {
                            cout << perfilLogado->getNome() << endl;
                            cout << "Proprietario " << perfilLogado->getProprietario() << endl;
                            cout << "Contatos: " << perfilLogado->getContatos()->size() << endl;
                        }  else {
                            Pessoa *perfilLogado = dynamic_cast<Pessoa*>(Rede->getPerfil(opcao3));
                            cout << perfilLogado->getNome() << endl;
                            cout << "Contatos: " << perfilLogado->getContatos()->size() << endl;
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
                            perfilLogado->adicionar(story1);
                        } else {
                            string texto1;
                            cout << "Texto: ";
                            cin >> texto1;
                            Postagem *postagem1 = new Postagem(texto1,data1,perfilLogado);
                            perfilLogado->adicionar(postagem1);
                        }
                    }
                    else if (opcao4 == 2) {
                        int data2;
                        //int qtd;
                        cout << "Data: ";
                        cin >> data2;
                        cout << "Postagens dos ultimos 3 dias: ";
                        list<Postagem*> *listarPostagensContatos = perfilLogado->getPostagensDosContatos(data2);
                        list<Postagem*>::iterator iteraPostagemContatos = listarPostagensContatos->begin();
                        while (iteraPostagemContatos != listarPostagensContatos->end()) {
                            (*iteraPostagemContatos)->imprimir();
                            iteraPostagemContatos++;
                        }
                        //delete listarPostagensContatos; //add agr
                    }
                    else if (opcao4 == 3) {
                        //cout << "Perfil:" << endl;
                        vector<Perfil*> *listaPerfilContatos = Rede->getPerfis();
                        imprimePerfis(listaPerfilContatos, "Perfil: ");
                        //delete listaPerfilContatos; //add agr
                        int opcao5;
                        cin >> opcao5;
                        if (opcao5 == 0) {
                            cout << "Contato nao adicionado" << endl;
                        } else {
                            try {
                                Perfil *contatoAdd = Rede->getPerfil(opcao5);
                                perfilLogado->adicionar(contatoAdd);
                            } catch (invalid_argument *e) {
                                cout << "Contato nao adicionado" << endl;
                                delete e;
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

    cout << "Deseja Salvar? (s/n)" << endl;
    char salvar;
    cin >> salvar;

    if (salvar == 's') {
        Persiste->salvar(Rede);
    }

    delete Rede;

    return 0;
}
