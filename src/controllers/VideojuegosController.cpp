#include "controllers/VideojuegosController.h"
#include "Fabrica.h"

VideojuegosController* VideojuegosController::instance = nullptr;

VideojuegosController* VideojuegosController::get_instance()
{
	if (instance == nullptr)
		instance = new VideojuegosController;
	return instance;
}

VideojuegosController::VideojuegosController()
{
	videojuegos = new Lista;
	categorias_de_videojuegos = new Lista;
	videojuego = nullptr;
	categorias_de_un_videojuego = nullptr;
}

VideojuegosController::~VideojuegosController()
{
	delete dynamic_cast<Lista*>(videojuegos);
	delete dynamic_cast<Lista*>(categorias_de_videojuegos);
}

// ver informacion de videojuego
ICollection* VideojuegosController::listarVideojuegos()
{
	return videojuegos;
}

// publicar videojuego
void VideojuegosController::agregarVideojuego(string nombre, string descripcion, string empresa_lo_desarrollo, DtCostoSuscripcion costo)
{
	nombre_videojuego = nombre;
	_descripcion = descripcion;
	_empresa_lo_desarrollo = empresa_lo_desarrollo;
	costo_de_suscripcion = costo;
	categorias_de_un_videojuego = new Lista;
}

ICollection* VideojuegosController::listarCategoriaGeneros()
{
	ICollection* generos = new Lista;
	for (IIterator* it = categorias_de_videojuegos->iterator(); it->hasNext(); it->next())
	{
		CategoriaGenero* genero = dynamic_cast<CategoriaGenero*>(it->getCurrent());
		if (genero != nullptr)
			generos->add(genero);
	}
	return generos;
}

void VideojuegosController::agregarCategoriaGenero(ICollectible* genero)
{
	categorias_de_un_videojuego->add(genero);
}

ICollection* VideojuegosController::listarCategoriaPlataforma()
{
	ICollection* plataformas = new Lista;
	for (IIterator* it = categorias_de_videojuegos->iterator(); it->hasNext(); it->next())
	{
		CategoriaPlataforma* plataforma = dynamic_cast<CategoriaPlataforma*>(it->getCurrent());
		if (plataforma != nullptr)
			plataformas->add(plataforma);
	}
	return plataformas;
}

void VideojuegosController::agregarCategoriaPlataforma(ICollectible* plataforma)
{
	categorias_de_un_videojuego->add(plataforma);
}

ICollection* VideojuegosController::listarRestoCategorias()
{
	ICollection* categorias = new Lista;
	for (IIterator* it = categorias_de_videojuegos->iterator(); it->hasNext(); it->next())
	{
		NuevaCategoria* categoria = dynamic_cast<NuevaCategoria*>(it->getCurrent());
		if (categoria != nullptr)
			categorias->add(categoria);
	}
	return categorias;
}

void VideojuegosController::agregarCategoria(ICollectible* categoria)
{
	categorias_de_un_videojuego->add(categoria);
}

void VideojuegosController::mostrarInformacionIngresadaDelVideojuego()
{
	cout << "Info del videojuego:" << endl;
	cout << "Nombre: " << nombre_videojuego << endl;
	cout << "Descripcion: " << _descripcion << endl;
	cout << "Costo de suscripcion: " << endl;
	cout << "  Costo mensual: " << costo_de_suscripcion.Getcosto_mensual() << endl;
	cout << "  Costo trimestral: " << costo_de_suscripcion.Getcosto_trimestral() << endl;
	cout << "  Costo anual: " << costo_de_suscripcion.Getcosto_anual() << endl;
	cout << "  Costo vitalicia: " << costo_de_suscripcion.Getcosto_vitalicia() << endl;
	cout << "Categorias: " << endl;
	for (IIterator* it = categorias_de_un_videojuego->iterator(); it->hasNext(); it->next())
	{
		CategoriaDeVideojuegos* categoria = dynamic_cast<CategoriaDeVideojuegos*>(it->getCurrent());
		cout << "Nombre: " << categoria->Getnombre() << endl;
		cout << "  Descripcion: " << categoria->Getdescripcion() << endl;
		cout << "  Tipo: ";
		CategoriaGenero* genero;
		CategoriaPlataforma* plataforma;
		if ((genero = dynamic_cast<CategoriaGenero*>(categoria)) != nullptr)
			cout << "Genero";
		else if ((plataforma = dynamic_cast<CategoriaPlataforma*>(categoria)) != nullptr)
			cout << "Plataforma";
		else
			cout << "Otro";
		cout << endl;
	}
}

void VideojuegosController::darDeAltaVideojuego()
{
	videojuegos->add(new Videojuego(nombre_videojuego, _descripcion, _empresa_lo_desarrollo, costo_de_suscripcion, categorias_de_un_videojuego));
	categorias_de_un_videojuego = nullptr;
}

void VideojuegosController::cancelarCreacionDeVideojuego()
{
	categorias_de_un_videojuego = nullptr;
}

// agregar categoria
void VideojuegosController::listarNombresCategorias()
{
	cout << "Categorias:" << endl;
	if (categorias_de_videojuegos->isEmpty())
	{
		cout << "Actualmente no hay categorias en el sistema" << endl;
		return;
	}
	for (IIterator* it = categorias_de_videojuegos->iterator(); it->hasNext(); it->next())
	{
		CategoriaDeVideojuegos* categoria = dynamic_cast<CategoriaDeVideojuegos*>(it->getCurrent());
		cout << "Nombre: " << categoria->Getnombre() << endl;
	}
}

void VideojuegosController::agregarNuevaCategoria(string nombre, string descripcion, TipoCategoria tipo_categoria)
{
	_nombre = nombre;
	_descripcion = descripcion;
	_tipo_categoria = tipo_categoria;
}

void VideojuegosController::darDeAltaNuevaCategoria()
{
	switch (_tipo_categoria)
	{
	case TipoCategoria::Genero:
		categorias_de_videojuegos->add(new NuevoGenero(_nombre, _descripcion));
		break;
	case TipoCategoria::Plataforma:
		categorias_de_videojuegos->add(new NuevaPlataforma(_nombre, _descripcion));
		break;
	case TipoCategoria::Otro:
		categorias_de_videojuegos->add(new NuevaCategoria(_nombre, _descripcion));
		break;
	}
}

void VideojuegosController::cancelarNuevaCategoria()
{
	// no hay memoria que liberar aqui
}

// Demas
DtCostoSuscripcion VideojuegosController::listarSuscripciones(ICollectible* videojuego)
{
	Videojuego* vid = dynamic_cast<Videojuego*>(videojuego);
	return vid->Getcosto_suscripcion();
}

//iniciar Partida
ICollection* VideojuegosController::listarVideojuegosSuscritos()
{   IUsers* users = Fabrica::get_instance()->getIUsers();
    ICollection* juegos = new Lista;

   for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		bool suscripto = false;
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
		for (IIterator* jt = jugador->Getsuscripciones()->iterator(); jt->hasNext(); jt->next())
		{
			Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(jt->getCurrent());
			if (videojuego == suscripcion->Getvideojuego())
			{
				juegos->add(videojuego);
			}
		}

	}
	return juegos;
}

void VideojuegosController::seleccionarVideojuego(string nombre)
{
    IIterator* it = videojuegos->iterator();
	Videojuego* game;
	for (; it->hasNext(); it->next())
	{
		ICollectible* obj = it->getCurrent();
		if ((game = dynamic_cast<Videojuego*>(obj)) != nullptr)
		{
			if (game->Getnombre() == nombre)
            {
                videojuego=game;
                break;
            }

		}
	}

}
