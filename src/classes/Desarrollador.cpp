#include "classes/Desarrollador.h"

Desarrollador::Desarrollador(string _email, string _contrasenia, string empresa)
{
	Setemail(_email);
	Setcontrasenia(_contrasenia);
	empresa_donde_trabaja = empresa;
}
