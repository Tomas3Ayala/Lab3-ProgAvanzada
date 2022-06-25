#ifndef VIDEOJUEGOSCONTROLLER_H
#define VIDEOJUEGOSCONTROLLER_H

#include <IVideojuegos.h>


class VideojuegosController : public IVideojuegos
{
    public:
    	static VideojuegosController* get_instance();
		~VideojuegosController();

		// ver informacion de videojuego

		// eliminar videojuego

		// publicar videojuego
		void agregarVideojuego(string nombre, string descripcion, DtCostoSuscripcion costo);
		ICollection* listarCategoriaGeneros();
		void agregarCategoriaGenero(ICollectible* genero); // CategoriaGenero
		ICollection* listarCategoriaPlataforma();
		void agregarCategoriaPlataforma(ICollectible* plataforma);
		ICollection* listarRestoCategorias();
		ICollection* agregarCategoria(ICollectible* categoria);
		void mostrarInformacionIngresadaDelVideojuego();
		void darDeAltaVideojuego();
		void cancelarCreacionDeVideojuego();

		// Otro
		ICollection* listarVideojuegos();
		ICollection* listarCategoriaGeneros();
		ICollection* listarCategoriaPlataformas();
		ICollection* listarRestoCategorias();

    private:
    	static VideojuegosController* instance;
        VideojuegosController();

        // Demas
        ICollection* videojuegos;
        ICollection* categorias_de_videojuegos;

		// publicar videojuego
		string _descripcion;
		DtCostoSuscripcion costo_de_suscripcion;
		ICollection* categorias; // categorias de genero
};

#endif // VIDEOJUEGOSCONTROLLER_H
