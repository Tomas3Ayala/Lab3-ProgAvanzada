#ifndef VIDEOJUEGOSCONTROLLER_H
#define VIDEOJUEGOSCONTROLLER_H

#include <interfaces/IVideojuegos.h>
#include <classes/Videojuego.h>


class VideojuegosController : public IVideojuegos
{
    public:
    	static VideojuegosController* get_instance();
		~VideojuegosController() = default;

		// ver informacion de videojuego
		ICollection* listarVideojuegos();
		void seleccionarVideojuego(string nombre);
		void muestraDatosVideojuego();
		void muestraTotalHorasVideojuego();

		// eliminar videojuego
		ICollection* listarVideojuegosPublicadosNoFinalizados();
		// void seleccionarVideojuego(string nombre);
		void eliminarVideojuego(); // elimina el videojuego que lleva el nombre nombre_videojuego;
		void cancelarEliminacionDeVideojuego();

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

    private:
    	static VideojuegosController* instance;
        VideojuegosController();

        // Demas
        ICollection* videojuegos;
        ICollection* categorias_de_videojuegos;

        // Videojuego
        Videojuego* videojuego;

		// publicar videojuego
		string _descripcion;
		DtCostoSuscripcion costo_de_suscripcion;
		ICollection* categorias; // categorias de genero

		// eliminar videojuego y publicar videojuego
		string nombre_videojuego;
};

#endif // VIDEOJUEGOSCONTROLLER_H
