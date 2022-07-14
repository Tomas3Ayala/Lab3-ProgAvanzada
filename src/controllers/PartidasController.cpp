#include "controllers/PartidasController.h"

PartidasController* PartidasController::instance = nullptr;

PartidasController* PartidasController::get_instance()
{
	if (instance == nullptr)
		instance = new PartidasController;
	return instance;
}

PartidasController::PartidasController()
{
	//
}

// abandonar partida
ICollection* PartidasController::listarPartidasNoFinalizadasMultijugador()
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
	ICollection* partidas_unidas = jugador->Getpartidas_a_las_que_me_uni();
	ICollection* partidas_abandonadas = jugador->Getpartidas_abandonadas_multijugador();
	ICollection* partidas = new Lista;
	for (IIterator* it = partidas_unidas->iterator(); it->hasNext(); it->next())
	{
		Multijugador* partida = dynamic_cast<Multijugador*>(it->getCurrent());
		if (partida->Getduracion_finalizacion().es_cero()) // chequea si no se ha finalizado la partida
		{
			bool se_abandono = false;
			for (IIterator* jt = partidas_abandonadas->iterator(); jt->hasNext(); jt->next())
			{
				AbandonaMultijugador* abandona = dynamic_cast<AbandonaMultijugador*>(jt->getCurrent());
				if (abandona->Getpartida() == partida)
				{
					se_abandono = true;
					break;
				}
			}
			if (se_abandono)
				continue;
			partidas->add(partida);
		}
	}
	return partidas;
}

DtDatosPartida PartidasController::mostrarDatosPartida(ICollectible* partida)
{
	Partida* p = dynamic_cast<Partida*>(partida);
	DtDatosPartida datos_partida;
	datos_partida.Setidentificador(p->Getnropartida());
	datos_partida.Setfecha_comienzo(p->Getfecha_hora_comienzo());

	bool salir = false;
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	ICollection* videojuegos = games->listarVideojuegos();
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		ICollection* partidas = videojuego->Getpartidas();
		for (IIterator* jt = partidas->iterator(); jt->hasNext(); jt->next())
		{
			Partida* p = dynamic_cast<Partida*>(jt->getCurrent());
			if (p == partida)
			{
				salir = true;
				datos_partida.Setnombre_videojuego(videojuego->Getnombre());
				break;
			}
		}
		if (salir)
			break;
	}
	return datos_partida;
}

bool PartidasController::mostrarSiSeEstaTransmitiendoEnVivo(ICollectible* partida)
{
	Multijugador* multijugador = dynamic_cast<Multijugador*>(partida);
	return multijugador->Getes_transmitida_vivo();
}

string PartidasController::mostrarNicknameDelQueLaInicio(ICollectible* partida)
{
	Multijugador* multijugador = dynamic_cast<Multijugador*>(partida);
	IUsers* users = Fabrica::get_instance()->getIUsers();
	IDictionary* usuarios = users->listarUsuarios();
	for (IIterator* it = usuarios->getIteratorObj(); it->hasNext(); it->next())
	{
		Jugador* jugador = dynamic_cast<Jugador*>(it->getCurrent());
		if (jugador)
		{
			ICollection* partidas = jugador->Getpartidas_iniciadas();
			for (IIterator* jt = partidas->iterator(); jt->hasNext(); jt->next())
			{
				Multijugador* p = dynamic_cast<Multijugador*>(partida);
				if (p == multijugador)
					return jugador->Getnickname();
			}
		}
	}
	return "esta string no deberia estar aqui";
}

vector<string> PartidasController::mostrarNicknamesParticipantes(ICollectible* partida)
{
	vector<string> r;
	Multijugador* multijugador = dynamic_cast<Multijugador*>(partida);
	IUsers* users = Fabrica::get_instance()->getIUsers();
	IDictionary* usuarios = users->listarUsuarios();
	for (IIterator* it = usuarios->getIteratorObj(); it->hasNext(); it->next())
	{
		Jugador* jugador = dynamic_cast<Jugador*>(it->getCurrent());
		if (jugador)
		{
			ICollection* partidas = jugador->Getpartidas_a_las_que_me_uni();
			for (IIterator* jt = partidas->iterator(); jt->hasNext(); jt->next())
			{
				Multijugador* p = dynamic_cast<Multijugador*>(jt->getCurrent());
				if (p == multijugador)
				{
					bool se_abandono = false;
					for (IIterator* kt = jugador->Getpartidas_abandonadas_multijugador()->iterator(); kt->hasNext(); kt->next())
					{
						Multijugador* p2 = dynamic_cast<Multijugador*>(kt->getCurrent());
						if (multijugador == p2)
						{
							se_abandono = true;
							break;
						}
					}
					if (!se_abandono)
						r.push_back(jugador->Getnickname());
				}
			}
		}
	}
	return r;
}

void PartidasController::confirmarPartidaQueDeseaAbandonar(int identificador, DtFechaHora __opcional)
{
	if (__opcional.es_cero())
		__opcional = DtFechaHora().tiempo_actual();
	IUsers* users = Fabrica::get_instance()->getIUsers();
	Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
	ICollection* partidas_unidas = jugador->Getpartidas_a_las_que_me_uni();
	for (IIterator* it = partidas_unidas->iterator(); it->hasNext(); it->next())
	{
		Multijugador* partida = dynamic_cast<Multijugador*>(it->getCurrent());
		if (partida->Getnropartida() == identificador)
			jugador->Getpartidas_abandonadas_multijugador()->add(new AbandonaMultijugador(__opcional, partida));
	}
}

// finalizar partida
ICollection* PartidasController::obtenerPartidasNoFinalizadasAlInicio()
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
	ICollection* partidas_iniciadas = jugador->Getpartidas_iniciadas();
	ICollection* partidas = new Lista;
	for (IIterator* it = partidas_iniciadas->iterator(); it->hasNext(); it->next())
	{
		Partida* partida = dynamic_cast<Partida*>(it->getCurrent());
		//cout << "hellooo" << endl;
		if (partida->Getduracion_finalizacion().es_cero()) // chequea si no ha finalizado la partida
			partidas->add(partida);
	}
	return partidas;
}

bool PartidasController::mostrarSiEsContinuacion(ICollectible* partida)
{
	Individual* individual = dynamic_cast<Individual*>(partida);
	return !individual->Getes_nueva();
}

void PartidasController::confirmarPartidaQueDeseaFinalizar(int identificador, DtFechaHora __opcional)
{
	if (__opcional.es_cero())
		__opcional = DtFechaHora().tiempo_actual();
	IUsers* users = Fabrica::get_instance()->getIUsers();
	Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
	ICollection* partidas_iniciadas = jugador->Getpartidas_iniciadas();
	Partida* partida_a_finalizar = nullptr;
	for (IIterator* it = partidas_iniciadas->iterator(); it->hasNext(); it->next())
	{
		Partida* partida = dynamic_cast<Partida*>(it->getCurrent());
		if (partida->Getnropartida() == identificador)
		{
			partida->Setduracion_finalizacion(__opcional.restar(partida->Getfecha_hora_comienzo()));
			//cout << "Bueno " << DtFechaHora().tiempo_actual().to_segundos() << " " << partida->Getfecha_hora_comienzo().to_segundos() << " " << partida->Getduracion_finalizacion().es_cero() << endl;
			//system("pause");
			partida_a_finalizar = partida;
			break;
		}
	}
	Multijugador* multijugador = dynamic_cast<Multijugador*>(partida_a_finalizar);
	if (multijugador)
	{
		IDictionary* usuarios = users->listarUsuarios();
		for (IIterator* it = usuarios->getIteratorObj(); it->hasNext(); it->next())
		{
			Jugador* jugador = dynamic_cast<Jugador*>(it->getCurrent());
			if (jugador)
			{
				ICollection* partidas_unidas = jugador->Getpartidas_a_las_que_me_uni();
				for (IIterator* jt = partidas_unidas->iterator(); jt->hasNext(); jt->next())
				{
					Multijugador* m = dynamic_cast<Multijugador*>(jt->getCurrent());
					if (m == multijugador)
					{
						ICollection* partidas_abandonadas = jugador->Getpartidas_abandonadas_multijugador();
						partidas_abandonadas->add(new AbandonaMultijugador(DtFechaHora().tiempo_actual(), m));
					}
				}
			}
		}
	}
}

// iniciar partida
void PartidasController::seleccionarVideojuego(string nombre)
{
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	ICollection* videojuegos = games->listarVideojuegos();
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		Videojuego* vid = dynamic_cast<Videojuego*>(it->getCurrent());
		if (vid->Getnombre() == nombre)
			videojuego_para_empezar_partida = vid;
	}
	identificador_de_partida_a_continuar = -1;
	es_individual = true;
	participantes = new Lista;
}

ICollection* PartidasController::listarPartidasEnOrden() // individuales
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
	ICollection* copia = new Lista;
	ICollection* iniciadas = jugador->Getpartidas_iniciadas();
	for (IIterator* it = iniciadas->iterator(); it->hasNext(); it->next())
	{
		Individual* partida = dynamic_cast<Individual*>(partida);
		if (partida && !partida->Getduracion_finalizacion().es_cero())
			copia->add(partida);
	}
	ICollection* ordenado = new Lista;
	while (true)
	{
		if (copia->isEmpty())
			break;
		Individual* mas_antigua = nullptr;
		for (IIterator* it = copia->iterator(); it->hasNext(); it->next())
		{
			Individual* actual = dynamic_cast<Individual*>(it->getCurrent());
			DtFechaHora fecha = actual->Getfecha_hora_comienzo().sumar(actual->Getduracion_finalizacion());
			if (mas_antigua)
			{
				if (fecha.es_antes(mas_antigua->Getfecha_hora_comienzo().sumar(mas_antigua->Getduracion_finalizacion())))
					mas_antigua = actual;
			}
			else
				mas_antigua = actual;
		}
		copia->remove(mas_antigua);
		ordenado->add(mas_antigua);
	}
	return ordenado;
}

void PartidasController::seleccionarPartida(int identificador)
{
	identificador_de_partida_a_continuar = identificador;
}

void PartidasController::esTransmitidaEnVivo(bool es_transmitida_en_vivo)
{
	es_transmitida_en_vivo_multijugador = es_transmitida_en_vivo;
	es_individual = false; // indica que la partida no es individual
}

vector<string> PartidasController::listarDemasJugadoresConSuscripcionActiva()
{
	vector<string> nicknames;
	IUsers* users = Fabrica::get_instance()->getIUsers();
	IDictionary* usuarios = users->listarUsuarios();
	for (IIterator* it = usuarios->getIteratorObj(); it->hasNext(); it->next())
	{
		Jugador* jugador = dynamic_cast<Jugador*>(it->getCurrent());
		if (jugador && jugador != dynamic_cast<Jugador*>(users->get_usuario_seleccionado()))
		{
			ICollection* suscripciones = jugador->Getsuscripciones();
			for (IIterator* it = suscripciones->iterator(); it->hasNext(); it->next())
			{
				Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(it->getCurrent());
				if (suscripcion->Getvideojuego() == videojuego_para_empezar_partida)
				{
					Temporal* temporal = dynamic_cast<Temporal*>(suscripcion);
					if (temporal)
					{
						if (temporal->Getestado())
						{
							nicknames.push_back(jugador->Getnickname());
							break;
						}
					}
					else
					{
						nicknames.push_back(jugador->Getnickname());
						break;
					}
				}
			}
		}
	}
	return nicknames;
}

void PartidasController::agregarParticipante(string nickname)
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	IDictionary* usuarios = users->listarUsuarios();
	for (IIterator* it = usuarios->getIteratorObj(); it->hasNext(); it->next())
	{
		Jugador* jugador = dynamic_cast<Jugador*>(it->getCurrent());
		if (jugador && jugador->Getnickname() == nickname)
			participantes->add(jugador);
	}
}

void PartidasController::darDeAltaNuevaPartida(DtFechaHora __opcional)
{
	if (__opcional.es_cero())
		__opcional = DtFechaHora().tiempo_actual();

//	cout << "as string " << __opcional.as_string() << ", " << __opcional.es_cero() << endl;
//	system("pause");

	IUsers* users = Fabrica::get_instance()->getIUsers();
	Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
	Videojuego* videojuego = dynamic_cast<Videojuego*>(videojuego_para_empezar_partida);
	ICollection* partidas = videojuego->Getpartidas();
	if (es_individual)
	{
		if (identificador_de_partida_a_continuar != -1)
		{
			for (IIterator* it = partidas->iterator(); it->hasNext(); it->next())
			{
				Individual* partida = dynamic_cast<Individual*>(it->getCurrent());
				if (partida->Getnropartida() == identificador_de_partida_a_continuar)
				{
					Individual* indi = new Individual(false, partida, __opcional);
					partidas->add(indi);
//					cout << "aniadido" << endl;
					jugador->Getpartidas_iniciadas()->add(indi);
					break;
				}
			}
		}
		else
		{
//			cout << "aniadido no continua" << endl;
			Individual* indi = new Individual(true, nullptr, __opcional);
			partidas->add(indi);
			jugador->Getpartidas_iniciadas()->add(indi);
		}
	}
	else
	{
		int parti = 0;
		for (IIterator* it = participantes->iterator(); it->hasNext(); it->next())
			parti++;
		Multijugador* multijugador = new Multijugador(parti, es_transmitida_en_vivo_multijugador, __opcional);
		//cout << jugador->Getnickname() << ", con " << parti << endl;
		for (IIterator* it = participantes->iterator(); it->hasNext(); it->next())
		{
			Jugador* jugador = dynamic_cast<Jugador*>(it->getCurrent());
//			cout << "agregando " << jugador->Getnickname() << endl;
			ICollection* partidas_u = jugador->Getpartidas_a_las_que_me_uni();
			partidas_u->add(multijugador);
		}
//		cout << "agregando multijugador" << endl;
		partidas->add(multijugador);
		jugador->Getpartidas_iniciadas()->add(multijugador);
	}
	participantes = nullptr;
//	cout << "pasa" << endl;
//	system("pause");
}

// Otro
//ICollection* PartidasController::listarPartidas()
//{
//	//
//}



