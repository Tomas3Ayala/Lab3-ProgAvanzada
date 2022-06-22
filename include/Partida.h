#ifndef PARTIDA_H
#define PARTIDA_H
#include "DtFechaHora.h"

class Partida
{
    public:
        Partida();
        virtual ~Partida();

        int Getnropartida() { return nropartida; }
        void Setnropartida(int val) { nropartida = val; }
        DtFechaHora Getfecha_hora_comienzo() { return fecha_hora_comienzo; }
        void Setfecha_hora_comienzo(DtFechaHora val) { fecha_hora_comienzo = val; }
        DtFechaHora Getduracion_finalizacion() { return duracion_finalizacion; }
        void Setduracion_finalizacion(DtFechaHora val) { duracion_finalizacion = val; }

    protected:

    private:
        int nropartida;
        DtFechaHora fecha_hora_comienzo;
        DtFechaHora duracion_finalizacion;
};

#endif // PARTIDA_H
