#ifndef CATEGORIADEVIDEOJUEGOS_H
#define CATEGORIADEVIDEOJUEGOS_H
#include "StandardHeaders.h"

class CategoriaDeVideojuegos
{
    public:
        CategoriaDeVideojuegos();
        virtual ~CategoriaDeVideojuegos();

        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        string Getdescripcion() { return descripcion; }
        void Setdescripcion(string val) { descripcion = val; }

    protected:

    private:
        string nombre;
        string descripcion;
};

#endif // CATEGORIADEVIDEOJUEGOS_H
