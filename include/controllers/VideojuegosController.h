#ifndef VIDEOJUEGOSCONTROLLER_H
#define VIDEOJUEGOSCONTROLLER_H

#include <interfaces/IVideojuegos.h>
#include <Fabrica.h>
#include <classes/Desarrollador.h>
#include <classes/Jugador.h>
#include <classes/AbandonaMultijugador.h>
#include <classes/Partida.h>
#include <classes/Videojuego.h>
#include <classes/NuevoGenero.h>
#include <classes/NuevaPlataforma.h>
#include <classes/NuevaCategoria.h>


class VideojuegosController : public IVideojuegos
{
    public:
    	static VideojuegosController* get_instance();
    	~VideojuegosController();

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
		void agregarVideojuego(string nombre, string descripcion, string empresa_lo_desarrollo, DtCostoSuscripcion costo);
		ICollection* listarCategoriaGeneros();
		void agregarCategoriaGenero(ICollectible* genero);
		ICollection* listarCategoriaPlataforma();
		void agregarCategoriaPlataforma(ICollectible* plataforma);
		ICollection* listarRestoCategorias();
		void agregarCategoria(ICollectible* categoria);
		void mostrarInformacionIngresadaDelVideojuego();
		void darDeAltaVideojuego();
		void cancelarCreacionDeVideojuego();

		// agregar categoria
		void listarNombresCategorias();
		void agregarNuevaCategoria(string nombre, string descripcion, TipoCategoria tipo_categoria);
		void darDeAltaNuevaCategoria();
		void cancelarNuevaCategoria();

		// Demas
		DtCostoSuscripcion listarSuscripciones(ICollectible* videojuego);

    private:
    	static VideojuegosController* instance;
        VideojuegosController();

        // Demas
        ICollection* videojuegos;
        ICollection* categorias_de_videojuegos;

        // Videojuego
        Videojuego* videojuego;

		// publicar videojuego
		string _descripcion, _email_desarrollador, _empresa_lo_desarrollo;
		DtCostoSuscripcion costo_de_suscripcion;
		ICollection* categorias_de_un_videojuego;

		// eliminar videojuego y publicar videojuego
		string nombre_videojuego;

		// agregar categoria
		string _nombre;
		TipoCategoria _tipo_categoria;
};

#endif // VIDEOJUEGOSCONTROLLER_H
