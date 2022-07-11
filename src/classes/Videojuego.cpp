#include "classes/Videojuego.h"

Videojuego::Videojuego(string _nombre, string _descripcion, string _empresa_desarrollo, DtCostoSuscripcion costo, ICollection* categorias)
{
	nombre = _nombre;
	descripcion = _descripcion;
	empresa_desarrollo = _empresa_desarrollo;
	costo_suscripcion = costo;
	categorias_de_videojuegos = categorias;
}

Videojuego::~Videojuego()
{
	//dtor
}
