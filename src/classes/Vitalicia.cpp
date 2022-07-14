#include "classes/Vitalicia.h"

Vitalicia::Vitalicia(float _costo, EnumMetodoPago metodo, float momento, DtFechaHora _fecha, Videojuego* _videojuego)
{
	costo = _costo;
	Setmetodo_pago(metodo);
	Setcosto_momento(momento);
	Setfecha_momento(_fecha);
	Setvideojuego(_videojuego);
}

Vitalicia::~Vitalicia()
{
	//dtor
}
