#ifndef DTCOSTOSUSCRIPCION_H
#define DTCOSTOSUSCRIPCION_H
#include "StandardHeaders.h"

class DtCostoSuscripcion
{
	public:
		DtCostoSuscripcion();

		int Getcosto_mensual() { return costo_mensual; }
		void Setcosto_mensual(int val) { costo_mensual = val; }
		int Getcosto_trimestral() { return costo_trimestral; }
		void Setcosto_trimestral(int val) { costo_trimestral = val; }
		int Getcosto_anual() { return costo_anual; }
		void Setcosto_anual(int val) { costo_anual = val; }
		int Getcosto_vitalicia() { return costo_vitalicia; }
		void Setcosto_vitalicia(int val) { costo_vitalicia = val; }

	private:
		int costo_mensual;
		int costo_trimestral;
		int costo_anual;
		int costo_vitalicia;
};

#endif // DTCOSTOSUSCRIPCION_H
