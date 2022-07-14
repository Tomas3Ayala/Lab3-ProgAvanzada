#ifndef DTFECHAHORA_H
#define DTFECHAHORA_H
#include "StandardHeaders.h"

class DtFechaHora
{
	public:
		DtFechaHora();
		DtFechaHora(tm tiempo);
		DtFechaHora(long long segundos);
		DtFechaHora(int _dia, int _mes, int _anio, int _horas, int _minutos, int _segundos);

		double to_segundos();

		bool es_cero();
		DtFechaHora tiempo_actual();
		DtFechaHora restar(DtFechaHora otro);
		DtFechaHora sumar(DtFechaHora otro);
		int en_horas();

		bool es_antes(DtFechaHora otro); // cheque que this sea una fecha anterior que otro

		string as_string();
		string as_string_as_duration();

		int Getdia() { return dia; }
		void Setdia(int val) { dia = val; }
		int Getmes() { return mes; }
		void Setmes(int val) { mes = val; }
		int Getanio() { return anio; }
		void Setanio(int val) { anio = val; }
		int Gethoras() { return horas; }
		void Sethoras(int val) { horas = val; }
		int Getminutos() { return minutos; }
		void Setminutos(int val) { minutos = val; }
		int Getsegundos() { return segundos; }
		void Setsegundos(int val) { segundos = val; }

	private:
		int dia;
		int mes;
		int anio;
		int horas;
		int minutos;
		int segundos;
};

#endif // DTFECHAHORA_H
