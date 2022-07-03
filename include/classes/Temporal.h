#ifndef TEMPORAL_H
#define TEMPORAL_H

#include <classes/Suscripcion.h>

enum class EnumValidez
{
	UN_MES,
	TRIMESTRE,
	ANIO,
};

class Temporal : public Suscripcion
{
    public:
        Temporal();
        virtual ~Temporal();

        EnumValidez Getperiodo_validez() { return periodo_validez; }
        void Setperiodo_validez(EnumValidez val) { periodo_validez = val; }
        float Getvalor_cuota() { return valor_cuota; }
        void Setvalor_cuota(float val) { valor_cuota = val; }
        bool Getestado() { return estado; }
        void Setestado(bool val) { estado = val; }
        DtFechaHora Getfecha_cancelacion() { return fecha_cancelacion; }
        void Setfecha_cancelacion(DtFechaHora val) { fecha_cancelacion = val; }

    private:
        EnumValidez periodo_validez;
        float valor_cuota;
        bool estado;
        DtFechaHora fecha_cancelacion;
};

#endif // TEMPORAL_H
