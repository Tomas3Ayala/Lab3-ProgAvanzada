#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <classes/Partida.h>


class Individual : public Partida
{
    public:
        Individual();
        virtual ~Individual();

        bool Getes_nueva() { return es_nueva; }
        void Setes_nueva(bool val) { es_nueva = val; }

    protected:

    private:
        bool es_nueva;
};

#endif // INDIVIDUAL_H
