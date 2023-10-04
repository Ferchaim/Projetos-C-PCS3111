#include "PersistenciaDaRede.h"
#include <stdexcept>

PersistenciaDaRede::PersistenciaDaRede(string arquivo) {

    this->arquivo = arquivo;

}

void PersistenciaDaRede::salvar(RedeSocial* r) {

    ofstream saida;
    saida.open(arquivo);

    vector<Perfil*> *rPerfis = r->getPerfis();
    saida << (*rPerfis)[0]->getUltimoId() << endl; //Escreve o ultimoId no arquivo

    vector<Perfil*>::iterator buscaTipo = rPerfis->begin();

    vector<PessoaVerificada*> *rPerfisPessoaVeri = new vector<PessoaVerificada*>();
    vector<Pessoa*> *rPerfisPessoa = new vector<Pessoa*>();
    vector<Pagina*> *rPerfisPagina = new vector<Pagina*>();

    while (buscaTipo != rPerfis->end()) {
        if (PessoaVerificada* varTemp=dynamic_cast<PessoaVerificada*>(*buscaTipo)) {
            rPerfisPessoaVeri->push_back(varTemp);
        }
        else if (Pessoa* varTemp=dynamic_cast<Pessoa*>(*buscaTipo)) {
            rPerfisPessoa->push_back(varTemp);
        }
        else if (Pagina* varTemp=dynamic_cast<Pagina*>(*buscaTipo)) {
            rPerfisPagina->push_back(varTemp);
        }
        else {

        }
        buscaTipo++;
    }
    //delete buscaTipo;

    saida << rPerfisPessoaVeri->size() << endl; //Escreve a qtd de pessoasVerficadas no arquivo

    vector<PessoaVerificada*>::iterator percorrePV1 = rPerfisPessoaVeri->begin();
    while (percorrePV1 != rPerfisPessoaVeri->end()) {
        saida << (*percorrePV1)->getId() << " " << (*percorrePV1)->getNome() << " " << (*percorrePV1)->getEmail() << endl;
        percorrePV1++;
    }
    //delete percorrePV;

    saida << rPerfisPessoa->size() << endl; //Escreve a qtd de pessoasNormais no arquivo

    vector<Pessoa*>::iterator percorrePes1 = rPerfisPessoa->begin();
    while (percorrePes1 != rPerfisPessoa->end()) {
        saida << (*percorrePes1)->getId() << " " << (*percorrePes1)->getNome() << endl;
        percorrePes1++;
    }
    //delete percorrePes;

    saida << rPerfisPagina->size() << endl; //Escreve a qtd de Paginas no arquivo

    vector<Pagina*>::iterator percorrePag1= rPerfisPagina->begin();
    while (percorrePag1 != rPerfisPagina->end()) {
        saida << (*percorrePag1)->getId() << " " << (*percorrePag1)->getProprietario()->getId() << " "
        << (*percorrePag1)->getNome() << endl;
        percorrePag1++;
    }
    //delete percorrePag;

    //vector<PessoaVerificada*>::iterator percorrePV = rPerfisPessoaVeri->begin();
    vector<PessoaVerificada*>::iterator percorrePV2 = rPerfisPessoaVeri->begin(); //Escreve os ids dos contatos
    while (percorrePV2 != rPerfisPessoaVeri->end()) {
        vector<Perfil*> *ContatosPessoVeri = (*percorrePV2)->getContatos();
        vector<Perfil*>::iterator percorreCPV = ContatosPessoVeri->begin();
        while (percorreCPV != ContatosPessoVeri->end()) {
            saida << (*percorrePV2)->getId() << " " << (*percorreCPV)->getId() << endl;
            percorreCPV++;
        }
        percorrePV2++;
    }
    //delete percorreCPV;
    //delete percorrePV;


    //vector<Pessoa*>::iterator percorrePes = rPerfisPessoa->begin();
    vector<Pessoa*>::iterator percorrePes2 = rPerfisPessoa->begin();
    while (percorrePes2 != rPerfisPessoa->end()) {
        vector<Perfil*> *ContatosPessoa = (*percorrePes2)->getContatos();
        vector<Perfil*>::iterator percorreCP = ContatosPessoa->begin();
        while (percorreCP != ContatosPessoa->end()) {
            saida << (*percorrePes2)->getId() << " " << (*percorreCP)->getId() << endl;
            percorreCP++;
        }
        percorrePes2++;
    }
    //delete percorreCP;
    //delete percorrePes;

    //vector<Pagina*>::iterator percorrePag = rPerfisPagina->begin();
    vector<Pagina*>::iterator percorrePag2= rPerfisPagina->begin();
    while (percorrePag2 != rPerfisPagina->end()) {
        vector<Perfil*> *ContatosPag = (*percorrePag2)->getContatos();
        vector<Perfil*>::iterator percorreCPag = ContatosPag->begin();
        while (percorreCPag != ContatosPag->end()) {
            saida << (*percorrePag2)->getId() << " " << (*percorreCPag)->getId() << endl;
            percorreCPag++;
        }
        percorrePag2++;
    }
    //delete percorreCPag;
    //delete percorrePag;

    saida.close();

    delete rPerfis;
    delete rPerfisPagina;
    delete rPerfisPessoa;
    delete rPerfisPessoaVeri;

}

RedeSocial* PersistenciaDaRede::carregar() {

    RedeSocial *Rede1 = new RedeSocial();
    ifstream entrada;
    entrada.open(arquivo);

    int ultId;
    entrada >> ultId; //Captura o ultimo id
    Perfil::setUltimoId(ultId); //faz o set do ultimo id

    int numPesVe;
    entrada >> numPesVe; //Captura a qtd de pessoas verificadas

    int leituraId;
    int leituraIdPropri;
    string leituraNome;
    string leituraEmail;

    int iPV = 0;
    while ((entrada) && (iPV < numPesVe)) { //Carrega as pessoas verificadas
        entrada >> leituraId;
        entrada >> leituraNome;
        entrada >> leituraEmail;
        PessoaVerificada *PessoaX = new PessoaVerificada(leituraId,leituraNome,leituraEmail);
        Rede1->adicionar(PessoaX);
        if (!entrada) {
            throw new logic_error("Erro");
        }
        iPV++;
    }

    int numPes;
    entrada >> numPes; //Captura o numero de Pessoas

    int iP = 0;
    while ((entrada) && (iP < numPes)) { //Carrega as pessoas
        entrada >> leituraId;
        entrada >> leituraNome;
        Pessoa *PessoaY = new Pessoa(leituraId,leituraNome);
        Rede1->adicionar(PessoaY);
        if (!entrada) {
            throw new logic_error("Erro");
        }
        iP++;
    }

    int numPag;
    entrada >> numPag; //Captura o numero de Paginas

    int iPag = 0;
    while ((entrada) && (iPag < numPag)) { //Carrega as paginas
        entrada >> leituraId;
        entrada >> leituraIdPropri;
        entrada >> leituraNome;
        Perfil *proprietario1 = Rede1->getPerfil(leituraIdPropri);
        PessoaVerificada *proprietario2 =dynamic_cast<PessoaVerificada*>(proprietario1);
        Pagina *PessoaZ = new Pagina(leituraId,leituraNome,proprietario2);
        Rede1->adicionar(PessoaZ);
        if (!entrada) {
            throw new logic_error("Erro");
        }
        iPag++;
    }

    //Percorrer o arquivo ate chegar ao seu final

    int idPerfilAdicionador;
    int idContatoAdicionado;
    while ((entrada) && (entrada.eof() != 1)) {
        entrada >> idPerfilAdicionador;
        entrada >> idContatoAdicionado;
        Perfil* Adicionador = Rede1->getPerfil(idPerfilAdicionador);
        Perfil* Adicionado = Rede1->getPerfil(idContatoAdicionado);
        Adicionador->adicionar(Adicionado);
    }

    if (!entrada.eof()) {
        throw new logic_error ("Erro");
            //entrada.close();
            //return 1;
    }

    entrada.close();
    return Rede1;

}

PersistenciaDaRede::~PersistenciaDaRede() {
    //dtor
}
