#ifndef TEMPORAL_H
#define TEMPORAL_H

#include <Suscripcion.h>

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

    protected:

    private:
        EnumValidez periodo_validez;
        float valor_cuota;
        bool estado;
};

#endif // TEMPORAL_H
