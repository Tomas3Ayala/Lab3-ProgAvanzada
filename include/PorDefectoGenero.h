#ifndef PORDEFECTOGENERO_H
#define PORDEFECTOGENERO_H

#include <CategoriaGenero.h>

enum class GENERO
{
	Accion,
	Aventura,
	Estrategia,
	Deporte
};

class PorDefectoGenero : public CategoriaGenero
{
    public:
        PorDefectoGenero();
        virtual ~PorDefectoGenero();

        GENERO Getgenero() { return genero; }
        void Setgenero(GENERO val) { genero = val; }

    protected:

    private:
        GENERO genero;
};

#endif // PORDEFECTOGENERO_H
