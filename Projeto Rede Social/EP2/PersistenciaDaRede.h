#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H

#include <fstream>
#include <string>
#include <vector>
#include "RedeSocial.h"
#include "Perfil.h"
#include "Pessoa.h"
#include "Pagina.h"
#include "PessoaVerificada.h"

class PersistenciaDaRede {

    public:
        PersistenciaDaRede(string arquivo);
        virtual ~PersistenciaDaRede();

        void salvar(RedeSocial *r);
        RedeSocial* carregar();

    protected:

    private:
        string arquivo;
};

#endif // PERSISTENCIADAREDE_H
