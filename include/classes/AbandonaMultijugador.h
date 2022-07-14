#ifndef ABANDONAMULTIJUGADOR_H
#define ABANDONAMULTIJUGADOR_H
#include "StandardHeaders.h"
#include "Multijugador.h"
#include "datatypes/DtFechaHora.h"

class AbandonaMultijugador : public ICollectible
{
	public:
		AbandonaMultijugador(DtFechaHora _fecha, Multijugador* _partida);

		DtFechaHora Getfecha() { return fecha; }
		void Setfecha(DtFechaHora val) { fecha = val; }
		Multijugador* Getpartida() { return partida; }
		void Setpartida(Multijugador* val) { partida = val; }

	private:
		DtFechaHora fecha;
		Multijugador* partida;
};

#endif // ABANDONAMULTIJUGADOR_H
