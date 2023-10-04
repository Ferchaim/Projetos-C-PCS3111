#ifndef PESSOANAOVERIFICADA_H
#define PESSOANAOVERIFICADA_H

#include "Perfil.h"

class PessoaNaoVerificada: public Perfil
{
    public:
        PessoaNaoVerificada(string nome, int maximoDeContatos, int maximoDePostagens);
        virtual ~PessoaNaoVerificada();

    protected:
    private:

};

#endif // PESSOANAOVERIFICADA_H
