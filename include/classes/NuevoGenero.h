#ifndef NUEVOGENERO_H
#define NUEVOGENERO_H

#include <classes/CategoriaGenero.h>


class NuevoGenero : public CategoriaGenero
{
    public:
        NuevoGenero(string _nombre, string _descripcion);
        virtual ~NuevoGenero();

};

#endif // NUEVOGENERO_H
