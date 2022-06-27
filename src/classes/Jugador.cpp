#include "classes/Jugador.h"

Jugador::Jugador(string _email, string _contrasenia, string _nickname, string _descripcion)
{
	Setemail(_email);
	Setcontrasenia(_contrasenia);
	nickname = _nickname;
	descripcion = _descripcion;
}
