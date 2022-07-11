#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H
#include "datatypes/DtFechaHora.h"
#include "classes/Videojuego.h"

class Suscripcion : public ICollectible
{
    public:
        Suscripcion();
        virtual ~Suscripcion();

        EnumMetodoPago Getmetodo_pago() { return metodo_pago; }
        void Setmetodo_pago(EnumMetodoPago val) { metodo_pago = val; }
        float Getcosto_momento() { return costo_momento; }
        void Setcosto_momento(float val) { costo_momento = val; }
        DtFechaHora Getfecha_momento() { return fecha; }
        void Setfecha_momento(DtFechaHora val) { fecha = val; }
        Videojuego* Getvideojuego() { return videojuego; }
        void Setvideojuego(Videojuego* val) { videojuego = val; }

    private:
    	EnumMetodoPago metodo_pago;
    	float costo_momento;
    	DtFechaHora fecha;
    	Videojuego* videojuego;
};

#endif // SUSCRIPCION_H
