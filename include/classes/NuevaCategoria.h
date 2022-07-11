#ifndef NUEVACATEGORIA_H
#define NUEVACATEGORIA_H

#include "CategoriaDeVideojuegos.h"


class NuevaCategoria : public CategoriaDeVideojuegos
{
    public:
        NuevaCategoria(string _nombre, string _descripcion);
        virtual ~NuevaCategoria();
};

#endif // NUEVACATEGORIA_H
