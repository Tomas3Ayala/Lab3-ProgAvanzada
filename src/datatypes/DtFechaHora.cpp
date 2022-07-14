#include "datatypes/DtFechaHora.h"

DtFechaHora::DtFechaHora()
{
	dia = mes = anio = horas = minutos = segundos = 0;
}

DtFechaHora::DtFechaHora(long long segundos)
{
	anio = static_cast<int>(segundos / 60 / 60 / 24 / 30 / 12);
	mes = static_cast<int>(segundos / 60 / 60 / 24 / 30 - static_cast<long long>(anio) * 12);
	dia = static_cast<int>(segundos / 60 / 60 / 24 - static_cast<long long>(mes) * 30 - static_cast<long long>(anio) * 12 * 30);
	horas = static_cast<int>(segundos / 60 / 60 - static_cast<long long>(dia) * 24 - static_cast<long long>(mes) * 24 * 30 - static_cast<long long>(anio) * 24 * 12 * 30);
	minutos = static_cast<int>(segundos / 60 - static_cast<long long>(horas) * 60 - static_cast<long long>(dia) * 60 * 24 - static_cast<long long>(mes) * 60 * 24 * 30 - static_cast<long long>(anio) * 60 * 24 * 12 * 30);
	segundos = static_cast<int>(segundos - static_cast<long long>(minutos) * 60 - static_cast<long long>(horas) * 60 * 60 - static_cast<long long>(dia) * 60 * 60 * 24 - static_cast<long long>(mes) * 60 * 60 * 24 * 30 - static_cast<long long>(anio) * 60 * 60 * 24 * 12 * 30);
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

DtFechaHora::DtFechaHora(int _dia, int _mes, int _anio, int _horas, int _minutos, int _segundos)
{
	dia = _dia;
	mes = _mes;
	anio = _anio;
	horas = _horas;
	minutos = _minutos;
	segundos = _segundos;
}

double DtFechaHora::to_segundos()
{
	double r = static_cast<double>(segundos) + static_cast<double>(minutos) * 60 + static_cast<double>(horas) * 60 * 60 + static_cast<double>(dia) * 24 * 60 * 60 + static_cast<double>(mes) * 30 * 24 * 60 * 60 + static_cast<double>(anio) * 12 * 30 * 24 * 60 * 60;
	return r;
}

bool DtFechaHora::es_cero()
{
	return dia == 0 && mes == 0 && anio == 0 && horas == 0 && minutos == 0 && segundos == 0;
}

DtFechaHora DtFechaHora::tiempo_actual()
{
	time_t tiempo = time(NULL);
	tm local_tm = *localtime(&tiempo);
	DtFechaHora dt(local_tm);
	return dt;
}

DtFechaHora DtFechaHora::restar(DtFechaHora otro)
{
	double dif = to_segundos() - otro.to_segundos();
	long long segundos = static_cast<long long>(dif);
	return DtFechaHora(segundos);
}

DtFechaHora DtFechaHora::sumar(DtFechaHora otro)
{
	double sum = to_segundos() + otro.to_segundos();
	long long segundos = static_cast<long long>(sum);
	return DtFechaHora(segundos);
}

int DtFechaHora::en_horas()
{
	return to_segundos() / 60 / 60;
}

bool DtFechaHora::es_antes(DtFechaHora otro)
{
	if (anio > otro.Getanio())
		return false;
	else if (anio == otro.Getanio())
	{
		if (mes > otro.Getmes())
			return false;
		else if (mes == otro.Getmes())
		{
			if (dia > otro.Getdia())
				return false;
			else if (dia == otro.Getdia())
			{
				if (horas > otro.Gethoras())
					return false;
				else if (horas == otro.Gethoras())
				{
					if (minutos > otro.Getminutos())
						return false;
					else if (minutos == otro.Getminutos())
					{
						if (segundos > otro.Getsegundos())
							return false;
						else if (segundos == otro.Getsegundos())
							return true;
					}
				}
			}
		}
	}
	return true;
}

string DtFechaHora::as_string()
{
	return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio) + " " + to_string(horas) + ":" + to_string(minutos) + ":" + to_string(segundos);
}

string DtFechaHora::as_string_as_duration()
{
	vector<string> cosas;
	string r;
	if (anio)
		cosas.push_back(to_string(anio) + " anios");
	if (mes)
		cosas.push_back(to_string(mes) + " meses");
	if (dia)
		cosas.push_back(to_string(dia) + " dias");
	if (horas)
		cosas.push_back(to_string(horas) + " horas");
	if (minutos)
		cosas.push_back(to_string(minutos) + " minutos");
	if (segundos)
		cosas.push_back(to_string(segundos) + " segundos");
	if (cosas.size() == 1)
	{
		return cosas[0];
	}
	else if (cosas.size() == 0)
	{
		return "0 segundos";
	}
	else
	{
		for (auto it = cosas.begin(); it != cosas.end(); it++)
		{
			if (it != cosas.begin())
			{
				if (it + 1 == cosas.end())
					r += " y ";
				else
					r += ", ";
			}
			r += (*it);
		}
	}
	return r;
}
