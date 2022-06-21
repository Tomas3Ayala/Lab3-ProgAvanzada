#ifndef JUGADOR_H
#define JUGADOR_H

#include <Usuario.h>


class Jugador : public Usuario
{
    public:
        Jugador();
        virtual ~Jugador();

        string Getnickname() { return nickname; }
        void Setnickname(string val) { nickname = val; }
        string Getdescripcion() { return descripcion; }
        void Setdescripcion(string val) { descripcion = val; }

    protected:

    private:
        string nickname;
        string descripcion;
};

#endif // JUGADOR_H
