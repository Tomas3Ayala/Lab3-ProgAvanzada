#ifndef STANDARDHEADERS_H_INCLUDED
#define STANDARDHEADERS_H_INCLUDED

// STD
#include <iostream>
#include <vector>
#include <string>

// Collections
#include "../ColeccionesG/ICollection.h"
#include "../ColeccionesG/IDictionary.h"

using namespace std;

enum class EnumMetodoPago
{
	Tarjeta,
	PayPal,
};

enum class EnumTipoSuscripcion
{
	Vitalicia,
	Mensual,
	Trimestral,
	Anual,
};

enum class TipoCategoria
{
	Plataforma,
	Genero,
	Otro,
};

#endif // STANDARDHEADERS_H_INCLUDED
