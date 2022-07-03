#ifndef DTDATOSPARTIDA_H
#define DTDATOSPARTIDA_H
#include "DtFechaHora.h"

class DtDatosPartida
{
	public:
		DtDatosPartida();

		int Getidentificador() { return identificador; }
		void Setidentificador(int val) { identificador = val; }
		DtFechaHora Getfecha_comienzo() { return fecha_comienzo; }
		void Setfecha_comienzo(DtFechaHora val) { fecha_comienzo = val; }
		string Getnombre_videojuego() { return nombre_videojuego; }
		void Setnombre_videojuego(string val) { nombre_videojuego = val; }

	private:
		int identificador;
		DtFechaHora fecha_comienzo;
		string nombre_videojuego;
};

#endif // DTDATOSPARTIDA_H
