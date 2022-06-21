#ifndef PORDEFECTOPLATAFORMA_H
#define PORDEFECTOPLATAFORMA_H

#include <CategoriaPlataforma.h>


class PorDefectoPlataforma : public CategoriaPlataforma
{
    public:
        PorDefectoPlataforma();
        virtual ~PorDefectoPlataforma();

        PLATAFORMA Getplataforma() { return plataforma; }
        void Setplataforma(PLATAFORMA val) { plataforma = val; }

    protected:

    private:
        PLATAFORMA plataforma;
};

#endif // PORDEFECTOPLATAFORMA_H
