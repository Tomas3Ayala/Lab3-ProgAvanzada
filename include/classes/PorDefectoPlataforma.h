#ifndef PORDEFECTOPLATAFORMA_H
#define PORDEFECTOPLATAFORMA_H

#include <classes/CategoriaPlataforma.h>

enum class PLATAFORMA
{
	PC,
	Switch,
	PS4,
	Xbox,
	Xbox_One,
	Xbox_X,
	PS5
};

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
