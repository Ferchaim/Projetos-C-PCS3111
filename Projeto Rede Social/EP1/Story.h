#ifndef STORY_H
#define STORY_H

#include "Postagem.h"

class Story : public Postagem
{
    public:
        Story(string texto, int data, int dataDeFim, Perfil* autor);
        virtual ~Story();

        int getDataDeFim();
        virtual void imprimir();

    protected:

    private:
        int dataDeFim;
};

#endif // STORY_H
