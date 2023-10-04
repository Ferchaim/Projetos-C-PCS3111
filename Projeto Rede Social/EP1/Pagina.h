#ifndef PAGINA_H
#define PAGINA_H

#include "Perfil.h"
#include "PessoaVerificada.h"

class Pagina : public Perfil {
    public:
        Pagina(string nome, PessoaVerificada* proprietario, int maximoDeContatos, int maximoDePostagens);
        virtual ~Pagina();
        PessoaVerificada* getProprietario();

    protected:
        PessoaVerificada* proprietario;

    private:
};

#endif // PAGINA_H
