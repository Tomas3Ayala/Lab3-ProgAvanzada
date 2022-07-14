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
	ICollection* partidas = new Lista;
	for (IIterator* it = partidas_unidas->iterator(); it->hasNext(); it->next())
	{
		Multijugador* partida = dynamic_cast<Multijugador*>(it->getCurrent());
		if (partida->Getduracion_finalizacion().es_cero()) // chequea si no se ha finalizado la partida
			partidas->add(partida);
	}
	return partidas;
}

DtDatosPartida PartidasController::mostrarDatosPartida(ICollectible* partida)
{
	Multijugador* multijugador = dynamic_cast<Multijugador*>(partida);
	DtDatosPartida datos_partida;
	datos_partida.Setidentificador(multijugador->Getnropartida());
	datos_partida.Setfecha_comienzo(multijugador->Getfecha_hora_comienzo());

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
				Multijugador* p = dynamic_cast<Multijugador*>(partida);
				if (p == multijugador)
					r.push_back(jugador->Getnickname());
			}
		}
	}
	return r;
}

void PartidasController::confirmarPartidaQueDeseaAbandonar(int identificador)
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
	ICollection* partidas_unidas = jugador->Getpartidas_a_las_que_me_uni();
	for (IIterator* it = partidas_unidas->iterator(); it->hasNext(); it->next())
	{
		Multijugador* partida = dynamic_cast<Multijugador*>(it->getCurrent());
		if (partida->Getnropartida() == identificador)
			jugador->Getpartidas_abandonadas_multijugador()->add(partida);
	}
}

