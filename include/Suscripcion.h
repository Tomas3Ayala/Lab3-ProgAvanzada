#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H
#include "StandardHeaders.h"

class Suscripcion : public ICollectible
{
    public:
        Suscripcion();
        virtual ~Suscripcion();

        int Getmetodo_pago() { return metodo_pago; }
        void Setmetodo_pago(EnumMetodoPago val) { metodo_pago = val; }
        int Getcosto_momento() { return costo_momento; }
        void Setcosto_momento(float val) { costo_momento = val; }
        int Getfecha_momento() { return fecha; }
        void Setfecha_momento(DtFechaHora val) { fecha = val; }

    private:
    	EnumMetodoPago metodo_pago;
    	float costo_momento;
    	DtFechaHora fecha;
};

#endif // SUSCRIPCION_H
