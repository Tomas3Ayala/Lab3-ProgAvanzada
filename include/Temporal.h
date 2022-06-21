#ifndef TEMPORAL_H
#define TEMPORAL_H

#include <Suscripcion.h>


class Temporal : public Suscripcion
{
    public:
        Temporal();
        virtual ~Temporal();

        DtValidez Getperiodo_validez() { return periodo_validez; }
        void Setperiodo_validez(DtValidez val) { periodo_validez = val; }
        float Getvalor_cuota() { return valor_cuota; }
        void Setvalor_cuota(float val) { valor_cuota = val; }
        bool Getestado() { return estado; }
        void Setestado(bool val) { estado = val; }

    protected:

    private:
        DtValidez periodo_validez;
        float valor_cuota;
        bool estado;
};

#endif // TEMPORAL_H
