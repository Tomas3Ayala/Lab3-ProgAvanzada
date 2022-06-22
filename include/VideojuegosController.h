#ifndef VIDEOJUEGOSCONTROLLER_H
#define VIDEOJUEGOSCONTROLLER_H

#include <IVideojuegos.h>


class VideojuegosController : public IVideojuegos
{
    public:
    ~VideojuegosController();
    void asignarPuntajeAVideojuego();
    void verInformacionDeVideojuego();
    void eliminarVideojuego();
    void publicarVideojuego();
    ICollection* listarVideojuegos();
    ICollection* listarCategoriaGeneros();
    ICollection* listarCategoriaPlataformas();
    ICollection* listarRestoCategorias();

    private:
        VideojuegosController();
        ICollection* videojuegos;
        ICollection* categorias_de_videojuegos;
};

#endif // VIDEOJUEGOSCONTROLLER_H
