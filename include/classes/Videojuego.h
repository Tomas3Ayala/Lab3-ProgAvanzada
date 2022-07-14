#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H
#include "datatypes/DtCostoSuscripcion.h"

class Videojuego : public ICollectible
{
    public:
        Videojuego(string _nombre, string _descripcion, string _email_desarrollador, string _empresa_desarrollo, DtCostoSuscripcion costo, ICollection* categorias);
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
        string Getemail_desarrollador() { return email_desarrollador; }
        void Setemail_desarrollador(string val) { email_desarrollador = val; }
        ICollection* Getpartidas() { return partidas; }
        void Setpartidas(ICollection* val) { partidas = val; }
        ICollection* Getcategorias_de_videojuegos() { return categorias_de_videojuegos; }
        void Setcategorias_de_videojuegos(ICollection* val) { categorias_de_videojuegos = val; }

    private:
        string nombre;
        string descripcion;
        string empresa_desarrollo;
        string email_desarrollador;
        int total_horas_videojuego; // este dato se calcula
        float promedio_puntaje; // este tambien se calcula
        DtCostoSuscripcion costo_suscripcion;
        ICollection* partidas;
        ICollection* categorias_de_videojuegos;
};

#endif // VIDEOJUEGO_H
