#ifndef ASIGNAPUNTAJE_H
#define ASIGNAPUNTAJE_H
#include "StandardHeaders.h"
#include "Videojuego.h"

class AsignaPuntaje : public ICollectible
{
	public:
		AsignaPuntaje(int _puntaje, Videojuego* _videojuego);

		int Getpuntaje() { return puntaje; }
		void Setpuntaje(int val) { puntaje = val; }
		Videojuego* Getvideojuego() { return videojuego; }
		void Setvideojuego(Videojuego* val) { videojuego = val; }

	private:
		int puntaje;
		Videojuego* videojuego;
};

#endif // ASIGNAPUNTAJE_H
