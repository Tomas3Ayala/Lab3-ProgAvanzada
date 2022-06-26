#ifndef IVIDEOJUEGOS_H
#define IVIDEOJUEGOS_H
#include "StandardHeaders.h"

class IVideojuegos
{
	public:
		virtual ~IVideojuegos();

		// ver informacion de videojuego
		virtual ICollection* listarVideojuegos()=0;
		virtual void seleccionarVideojuego(string nombre)=0;
		virtual void muestraDatosVideojuego()=0;
		virtual void muestraTotalHorasVideojuego()=0;

		// eliminar videojuego
		virtual ICollection* listarVideojuegosPublicadosNoFinalizados()=0;
		virtual // void seleccionarVideojuego(string nombre)=0;
		virtual void eliminarVideojuego()=0;
		virtual void cancelarEliminacionDeVideojuego()=0;

		// publicar videojuego
		virtual void agregarVideojuego(string nombre, string descripcion, DtCostoSuscripcion costo)=0;
		virtual ICollection* listarCategoriaGeneros()=0;
		void agregarCategoriaGenero(ICollectible* genero); // CategoriaGenero
		virtual ICollection* listarCategoriaPlataforma()=0;
		virtual void agregarCategoriaPlataforma(ICollectible* plataforma)=0;
		virtual ICollection* listarRestoCategorias()=0;
		virtual ICollection* agregarCategoria(ICollectible* categoria)=0;
		virtual void mostrarInformacionIngresadaDelVideojuego()=0;
		virtual void darDeAltaVideojuego()=0;
		virtual void cancelarCreacionDeVideojuego()=0;

		// Otro
		virtual ICollection* listarVideojuegos()=0;
		virtual ICollection* listarCategoriaGeneros()=0;
		virtual ICollection* listarCategoriaPlataformas()=0;
		virtual ICollection* listarRestoCategorias()=0;

	private:
};

#endif // IVIDEOJUEGOS_H
