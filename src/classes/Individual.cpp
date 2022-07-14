#include "classes/Individual.h"

Individual::Individual(bool _es_nueva, Individual* continua, DtFechaHora _fecha_hora_comienzo)
{
	es_nueva = _es_nueva;
	partida_que_continua = continua;
	Setfecha_hora_comienzo(_fecha_hora_comienzo);
	Setduracion_finalizacion(DtFechaHora());
	Setnropartida(++Partida::ultimo_nro);
	Setcomentarios(new Lista);
}

Individual::~Individual()
{
	//
}
