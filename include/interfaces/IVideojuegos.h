#ifndef IVIDEOJUEGOS_H
#define IVIDEOJUEGOS_H
#include "datatypes/DtCostoSuscripcion.h"

class IVideojuegos
{
	public:
		virtual ~IVideojuegos()=default;

		// ver informacion de videojuego
		virtual ICollection* listarVideojuegos()=0;
		virtual void seleccionarVideojuego(string nombre)=0;
		virtual void muestraDatosVideojuego()=0;
		virtual void muestraTotalHorasVideojuego()=0;

		// eliminar videojuego
		virtual ICollection* listarVideojuegosPublicadosNoFinalizados()=0;
		// virtual void seleccionarVideojuego(string nombre)=0;
		virtual void eliminarVideojuego()=0;
		virtual void cancelarEliminacionDeVideojuego()=0;

		// publicar videojuego
		virtual void agregarVideojuego(string nombre, string descripcion, string empresa_lo_desarrollo, DtCostoSuscripcion costo)=0;
		virtual ICollection* listarCategoriaGeneros()=0;
		virtual void agregarCategoriaGenero(ICollectible* genero)=0; // CategoriaGenero
		virtual ICollection* listarCategoriaPlataforma()=0;
		virtual void agregarCategoriaPlataforma(ICollectible* plataforma)=0;
		virtual ICollection* listarRestoCategorias()=0;
		virtual void agregarCategoria(ICollectible* categoria)=0;
		virtual void mostrarInformacionIngresadaDelVideojuego()=0;
		virtual void darDeAltaVideojuego()=0;
		virtual void cancelarCreacionDeVideojuego()=0;

		// agregar categoria
		virtual void listarNombresCategorias()=0;
		virtual void agregarNuevaCategoria(string nombre, string descripcion, TipoCategoria tipo_categoria)=0;
		virtual void darDeAltaNuevaCategoria()=0;
		virtual void cancelarNuevaCategoria()=0;
		// iniciar partida
		virtual ICollection* listarVideojuegosSuscritos()=0;

		// Demas
		virtual DtCostoSuscripcion listarSuscripciones(ICollectible* videojuego)=0;
};

#endif // IVIDEOJUEGOS_H
