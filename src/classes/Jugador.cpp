#include "classes/Jugador.h"

Jugador::Jugador(string _email, string _contrasenia, string _nickname, string _descripcion)
{
	Setemail(_email);
	Setcontrasenia(_contrasenia);
	nickname = _nickname;
	descripcion = _descripcion;

	puntajes = new Lista;
	partidas_iniciadas = new Lista;
	partidas_a_las_que_me_uni = new Lista;
	partidas_abandonadas_multijugador = new Lista;
}

Jugador::~Jugador()
{
	delete dynamic_cast<Lista*>(puntajes);
	delete dynamic_cast<Lista*>(partidas_iniciadas);
	delete dynamic_cast<Lista*>(partidas_a_las_que_me_uni);
	delete dynamic_cast<Lista*>(partidas_abandonadas_multijugador);
}
