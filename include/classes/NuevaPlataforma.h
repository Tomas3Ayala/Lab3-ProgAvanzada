#ifndef NUEVAPLATAFORMA_H
#define NUEVAPLATAFORMA_H

#include <classes/CategoriaPlataforma.h>


class NuevaPlataforma : public CategoriaPlataforma
{
    public:
        NuevaPlataforma(string _nombre, string _descripcion);
        virtual ~NuevaPlataforma();

};

#endif // NUEVAPLATAFORMA_H
