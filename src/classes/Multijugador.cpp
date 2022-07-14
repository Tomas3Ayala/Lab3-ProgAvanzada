#include "classes/Multijugador.h"

Multijugador::Multijugador(int _participantes, bool transmitida_en_vivo, DtFechaHora _fecha_hora_comienzo)
{
	participantes = _participantes;
	es_transmitida_vivo = transmitida_en_vivo;
	Setfecha_hora_comienzo(_fecha_hora_comienzo);
	Setduracion_finalizacion(DtFechaHora());
	Setnropartida(++Partida::ultimo_nro);
	Setcomentarios(new Lista);
}

Multijugador::~Multijugador()
{
    //dtor
}
