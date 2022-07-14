#include "classes/Temporal.h"

Temporal::Temporal(float cuota, EnumValidez periodo, EnumMetodoPago metodo, float momento, DtFechaHora _fecha, Videojuego* _videojuego)
{
	fecha_cancelacion = DtFechaHora(10, 10, 10000, 0, 0, 0);
	if (periodo == EnumValidez::UN_MES)
		fecha_cancelacion = _fecha.sumar(DtFechaHora(0, 1, 0, 0, 0, 0));
	else if (periodo == EnumValidez::TRIMESTRE)
		fecha_cancelacion = _fecha.sumar(DtFechaHora(0, 3, 0, 0, 0, 0));
	else if (periodo == EnumValidez::ANIO)
		fecha_cancelacion = _fecha.sumar(DtFechaHora(0, 0, 1, 0, 0, 0));
	estado = true;
	valor_cuota = cuota;
	periodo_validez = periodo;
	Setmetodo_pago(metodo);
	Setfecha_momento(_fecha);
	Setvideojuego(_videojuego);
	Setcosto_momento(momento);
}

Temporal::~Temporal()
{
    //dtor
}

bool Temporal::Getestado()
{
	DtFechaHora fecha = Getfecha_momento();
	if (!fecha.es_antes(fecha_cancelacion))
		estado = false;
	return estado;
}
