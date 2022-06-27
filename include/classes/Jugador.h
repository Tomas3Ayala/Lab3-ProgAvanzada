#ifndef JUGADOR_H
#define JUGADOR_H

#include <classes/Usuario.h>


class Jugador : public Usuario
{
    public:
        Jugador(string _email, string _contrasenia, string _nickname, string _descripcion);

        string Getnickname() { return nickname; }
        void Setnickname(string val) { nickname = val; }
        string Getdescripcion() { return descripcion; }
        void Setdescripcion(string val) { descripcion = val; }

    private:
        string nickname;
        string descripcion;
};

#endif // JUGADOR_H
