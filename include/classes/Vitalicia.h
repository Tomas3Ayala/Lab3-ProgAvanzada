#ifndef VITALICIA_H
#define VITALICIA_H

#include <classes/Suscripcion.h>


class Vitalicia : public Suscripcion
{
    public:
    	Vitalicia(float _costo, EnumMetodoPago metodo, float momento, DtFechaHora _fecha, Videojuego* _videojuego);
		virtual ~Vitalicia();

		float Getcosto() { return costo; }
		void Setcosto(float val) { costo = val; }

	private:
		float costo;
};

#endif // VITALICIA_H
