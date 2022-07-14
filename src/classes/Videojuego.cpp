#include "classes/Videojuego.h"

Videojuego::Videojuego(string _nombre, string _descripcion, string _email_desarrollador, string _empresa_desarrollo, DtCostoSuscripcion costo, ICollection* categorias)
{
	nombre = _nombre;
	descripcion = _descripcion;
	email_desarrollador = _email_desarrollador;
	empresa_desarrollo = _empresa_desarrollo;
	costo_suscripcion = costo;
	categorias_de_videojuegos = categorias;
	partidas = new Lista;
}

Videojuego::~Videojuego()
{
	delete partidas;
}
