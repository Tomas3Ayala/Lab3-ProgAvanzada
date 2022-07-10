#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H
#include "datatypes/DtCostoSuscripcion.h"

class Videojuego : public ICollectible
{
    public:
        Videojuego();
        virtual ~Videojuego();

        string Getnombre() { return nombre; }
        void Setnombre(string val) { nombre = val; }
        string Getdescripcion() { return descripcion; }
        void Setdescripcion(string val) { descripcion = val; }
        int Gettotal_horas_videojuego() { return total_horas_videojuego; }
        void Settotal_horas_videojuego(int val) { total_horas_videojuego = val; }
        float Getpromedio_puntaje() { return promedio_puntaje; }
        void Setpromedio_puntaje(float val) { promedio_puntaje = val; }
        DtCostoSuscripcion Getcosto_suscripcion() { return costo_suscripcion; }
        void Setcosto_suscripcion(DtCostoSuscripcion val) { costo_suscripcion = val; }
        string Getempresa_desarrollo() { return empresa_desarrollo; }
        void Setempresa_desarrollo(string val) { empresa_desarrollo = val; }

    private:
        string nombre;
        string descripcion;
        string empresa_desarrollo;
        int total_horas_videojuego;
        float promedio_puntaje;
        DtCostoSuscripcion costo_suscripcion;
        ICollection* partidas;
        ICollection* categorias_de_videojuegos;
};

#endif // VIDEOJUEGO_H
