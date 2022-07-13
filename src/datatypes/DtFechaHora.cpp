#include "datatypes/DtFechaHora.h"

DtFechaHora::DtFechaHora()
{
	dia = mes = anio = horas = minutos = segundos = 0;
}

DtFechaHora::DtFechaHora(tm tiempo)
{
	Setdia(tiempo.tm_mday);
	Setmes(tiempo.tm_mon);
	Setanio(tiempo.tm_year + 1900);
	Sethoras(tiempo.tm_hour);
	Setminutos(tiempo.tm_min);
	Setsegundos(tiempo.tm_sec);
}

time_t DtFechaHora::to_time_t()
{
	time_t r = segundos + minutos * 60 + horas * 60 * 60 + dia * 24 * 60 * 60 + mes * 30 * 24 * 60 * 60 + (anio - 1900) * 12 * 30 * 24 * 60 * 60;
	return r;
}

bool DtFechaHora::es_cero()
{
	return dia == 0 || mes == 0 || anio == 0 || horas == 0 || minutos == 0 || segundos == 0;
}

DtFechaHora DtFechaHora::tiempo_actual()
{
	time_t tiempo = time(NULL);
	tm local_tm = *localtime(&tiempo);
	DtFechaHora dt(local_tm);
	return *this;
}

DtFechaHora DtFechaHora::restar(DtFechaHora otro)
{
	time_t tiempo = to_time_t() - otro.to_time_t();
	return DtFechaHora(*localtime(&tiempo));
}

DtFechaHora DtFechaHora::sumar(DtFechaHora otro)
{
	time_t tiempo = to_time_t() + otro.to_time_t();
	return DtFechaHora(*localtime(&tiempo));
}

int DtFechaHora::en_horas()
{
	return to_time_t() / 60 / 60;
}
