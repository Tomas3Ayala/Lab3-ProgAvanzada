#include "classes/Usuario.h"

Usuario::Usuario()
{
	suscripciones = new Lista;
	sigue_a = new Lista;
}

Usuario::~Usuario()
{
	delete dynamic_cast<Lista*>(suscripciones);
}
