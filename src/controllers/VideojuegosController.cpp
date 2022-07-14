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

void VideojuegosController::seleccionarVideojuego(string nombre)
{
	nombre_videojuego = nombre;
}

void VideojuegosController::muestraDatosVideojuego()
{
	IDictionary* usuarios = Fabrica::get_instance()->getIUsers()->listarUsuarios();
	Videojuego* videojuego;
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		if (videojuego->Getnombre() == nombre_videojuego)
		{
			int cuanto = 0;
			float suma_puntaje = 0;
			// recorre los usuarios
			for (IIterator* jt = usuarios->getIteratorObj(); jt->hasNext(); jt->next())
			{
				Jugador* jugador = dynamic_cast<Jugador*>(jt->getCurrent());
				if (jugador) // los usuarios son jugadores
				{
					ICollection* puntajes = jugador->Getpuntajes(); // obtiene los puntajes que hecho el jugador
					for (IIterator* kt = puntajes->iterator(); kt->hasNext(); kt->next()) // recorre los puntajes asignados pro el jugador
					{
						AsignaPuntaje* asigna_puntaje = dynamic_cast<AsignaPuntaje*>(kt->getCurrent());
						if (asigna_puntaje->Getvideojuego() == videojuego) // chequea que el videojuego al que le asigna el puntaje es el seleccionado
						{
							suma_puntaje += asigna_puntaje->Getpuntaje(); // suma el puntaje
							cuanto++; // aumenta el contador de puntajes
						}
					}
				}
			}
			if (cuanto == 0)
				cuanto = 1; // si no hay puntajes se asigna 0 al puntaje promedio
			float puntaje_promedio = suma_puntaje / cuanto; // divide la suma de puntajes por la cantidad que se han hecho
			videojuego->Setpromedio_puntaje(puntaje_promedio);
			cout << "Descripcion: " << videojuego->Getdescripcion() << endl;
			cout << "Costo de suscripcion: " << endl;
			cout << "  Costo mensual: " << videojuego->Getcosto_suscripcion().Getcosto_mensual() << endl;
			cout << "  Costo trimestral: " << videojuego->Getcosto_suscripcion().Getcosto_trimestral() << endl;
			cout << "  Costo anual: " << videojuego->Getcosto_suscripcion().Getcosto_anual() << endl;
			cout << "  Costo vitalicia: " << videojuego->Getcosto_suscripcion().Getcosto_vitalicia() << endl;
			cout << "Puntaje promedio: " << videojuego->Getpromedio_puntaje() << endl;
			cout << "Categorias a las que pertence:" << endl;
			ICollection* categorias = videojuego->Getcategorias_de_videojuegos();
			for (IIterator* jt = categorias->iterator(); jt->hasNext(); jt->next())
			{
				CategoriaDeVideojuegos* categoria = dynamic_cast<CategoriaDeVideojuegos*>(jt->getCurrent());
				cout << "  " << categoria->Getnombre() << endl;
			}
			cout << "Empresa desarrolladora: " << videojuego->Getempresa_desarrollo() << endl;
			break;
		}
	}
}

void VideojuegosController::muestraTotalHorasVideojuego()
{
	Videojuego* videojuego;
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		if (videojuego->Getnombre() == nombre_videojuego)
		{
			ICollection* partidas = videojuego->Getpartidas();
			int total_horas = 0;
			for (IIterator* jt = partidas->iterator(); jt->hasNext(); jt->next())
			{
				Partida* partida = dynamic_cast<Partida*>(jt->getCurrent());
				if (partida->Getfecha_hora_comienzo().es_cero())
					total_horas += DtFechaHora().tiempo_actual().restar(partida->Getfecha_hora_comienzo()).en_horas();
				else
					total_horas += partida->Getfecha_hora_comienzo().sumar(partida->Getduracion_finalizacion()).en_horas();
			}
			videojuego->Settotal_horas_videojuego(total_horas);
			cout << "Total de horas jugadas: " << videojuego->Gettotal_horas_videojuego() << endl;
		}
	}
}

// eliminar videojuego
ICollection* VideojuegosController::listarVideojuegosPublicadosNoFinalizados()
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	Usuario* usuario = dynamic_cast<Usuario*>(users->get_usuario_seleccionado());
	string email = usuario->Getemail();
	ICollection* finalizados = new Lista;
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		Videojuego* vid = dynamic_cast<Videojuego*>(it->getCurrent());
		if (vid->Getemail_desarrollador() == email)
		{
			bool todas_las_partidas_finalizadas = true;
			ICollection* partidas = vid->Getpartidas();
			for (IIterator* jt = partidas->iterator(); jt->hasNext(); jt->next())
			{
				Partida* partida = dynamic_cast<Partida*>(jt->getCurrent());
				if (partida->Getduracion_finalizacion().es_cero())
				{
					todas_las_partidas_finalizadas = false;
					break;
				}
			}
			if (todas_las_partidas_finalizadas)
				finalizados->add(vid);
		}
	}
	return finalizados;
}

void VideojuegosController::eliminarVideojuego() // elimina el videojuego que lleva el nombre nombre_videojuego
{
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		Videojuego* vid = dynamic_cast<Videojuego*>(it->getCurrent());
		if (vid->Getnombre() == nombre_videojuego)
		{
			ICollection* partidas_vid = vid->Getpartidas();

			IUsers* users = Fabrica::get_instance()->getIUsers();
			IDictionary* usuarios = users->listarUsuarios();
			for (IIterator* jt = usuarios->getIteratorObj(); jt->hasNext(); jt->next())
			{
				Jugador* jugador = dynamic_cast<Jugador*>(jt->getCurrent());
				if (jugador)
				{
					bool se_encontro_una;
					// eliminando referencias de partidas en jugador
					ICollection* partidas = nullptr;
					for (int i = 0; i < 2; i++)
					{
						if (i == 0)
							partidas = jugador->Getpartidas_a_las_que_me_uni();
						else
							partidas = jugador->Getpartidas_iniciadas();
						do
						{
							se_encontro_una = false;
							for (IIterator* kt = partidas->iterator(); kt->hasNext(); kt->next()) // recorremos las partidas
							{
								Partida* partida = dynamic_cast<Partida*>(kt->getCurrent());
								for (IIterator* lt = partidas_vid->iterator(); lt->hasNext(); lt->next()) // recorremos las partidas dentro del videojuego
								{
									Partida* partida_vid = dynamic_cast<Partida*>(lt->getCurrent());
									if (partida_vid == partida) // chequea si la partida del videojuego es la que esta guardada en partidas
									{
										se_encontro_una = true;
										partidas->remove(partida);
										break;
									}
								}
								if (se_encontro_una)
									break;
							}
						} while(se_encontro_una); // siempre y cuando halla alguna partida encontrada entonces se repite la eliminacion por si hay otra
					}

					// eliminando suscripciones al videojuego
					ICollection* suscripciones = jugador->Getsuscripciones();
					do
					{
						se_encontro_una = false;
						for (IIterator* kt = suscripciones->iterator(); kt->hasNext(); kt->next())
						{
							Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(kt->getCurrent());
							if (suscripcion->Getvideojuego() == vid)
							{
								suscripciones->remove(suscripcion);
								se_encontro_una = true;
								break;
							}
						}
					} while(se_encontro_una);

					// eliminando asigna puntaje
					ICollection* puntajes_asignados = jugador->Getpuntajes();
					do
					{
						se_encontro_una = false;
						for (IIterator* kt = puntajes_asignados->iterator(); kt->hasNext(); kt->next())
						{
							AsignaPuntaje* asigna_puntaje = dynamic_cast<AsignaPuntaje*>(kt->getCurrent());
							if (asigna_puntaje->Getvideojuego() == vid)
							{
								puntajes_asignados->remove(asigna_puntaje);
								se_encontro_una = true;
								break;
							}
						}
					} while(se_encontro_una);

					// eliminando abandona multijugador
					ICollection* multijugadores_abandonados = jugador->Getpartidas_abandonadas_multijugador();
					do
					{
						se_encontro_una = false;
						for (IIterator* kt = multijugadores_abandonados->iterator(); kt->hasNext(); kt->next()) // recorremos los AbandonaMultijugador
						{
							AbandonaMultijugador* abandona = dynamic_cast<AbandonaMultijugador*>(kt->getCurrent());
							Partida* partida = dynamic_cast<Partida*>(abandona->Getpartida());
							for (IIterator* lt = partidas_vid->iterator(); lt->hasNext(); lt->next()) // recorremos las partidas dentro del videojuego
							{
								Partida* partida_vid = dynamic_cast<Partida*>(lt->getCurrent());
								if (partida_vid == partida) // chequea si la partida del videojuego es la que esta guardada en en el multijugador abandona
								{
									se_encontro_una = true;
									partidas->remove(partida);
									break;
								}
							}
							if (se_encontro_una)
								break;
						}
					} while(se_encontro_una); // siempre y cuando halla alguna partida encontrada entonces se repite la eliminacion por si hay otra
				}
			}
			// elimina finalmente el videojuego con todas sus partidas y los comentarios de esta
			videojuegos->remove(vid);
			break;
		}
	}
}

void VideojuegosController::cancelarEliminacionDeVideojuego()
{
	nombre_videojuego = "";
}

// publicar videojuego
void VideojuegosController::agregarVideojuego(string nombre, string descripcion, string empresa_lo_desarrollo, DtCostoSuscripcion costo)
{
	nombre_videojuego = nombre;
	_descripcion = descripcion;
	_email_desarrollador = dynamic_cast<Usuario*>(Fabrica::get_instance()->getIUsers()->get_usuario_seleccionado())->Getemail();
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
	videojuegos->add(new Videojuego(nombre_videojuego, _descripcion, _email_desarrollador, _empresa_lo_desarrollo, costo_de_suscripcion, categorias_de_un_videojuego));
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
