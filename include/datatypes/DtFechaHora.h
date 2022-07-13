#ifndef DTFECHAHORA_H
#define DTFECHAHORA_H
#include "StandardHeaders.h"

class DtFechaHora
{
	public:
		DtFechaHora();
		DtFechaHora(tm tiempo);

		time_t to_time_t();

		bool es_cero();
		DtFechaHora tiempo_actual();
		DtFechaHora restar(DtFechaHora otro);
		DtFechaHora sumar(DtFechaHora otro);
		int en_horas();

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
