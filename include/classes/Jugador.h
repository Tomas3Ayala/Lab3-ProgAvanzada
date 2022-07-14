#ifndef JUGADOR_H
#define JUGADOR_H

#include <classes/Usuario.h>
#include <classes/AsignaPuntaje.h>


class Jugador : public Usuario
{
    public:
        Jugador(string _email, string _contrasenia, string _nickname, string _descripcion);
        ~Jugador();

        string Getnickname() { return nickname; }
        void Setnickname(string val) { nickname = val; }
        string Getdescripcion() { return descripcion; }
        void Setdescripcion(string val) { descripcion = val; }

        ICollection* Getpuntajes() { return puntajes; }
        void Setpuntajes(ICollection* val) { puntajes = val; }
        ICollection* Getpartidas_iniciadas() { return partidas_iniciadas; }
        void Setpartidas_iniciadas(ICollection* val) { partidas_iniciadas = val; }
        ICollection* Getpartidas_a_las_que_me_uni() { return partidas_a_las_que_me_uni; }
        void Setpartidas_a_las_que_me_uni(ICollection* val) { partidas_a_las_que_me_uni = val; }
        ICollection* Getpartidas_abandonadas_multijugador() { return partidas_abandonadas_multijugador; }
        void Setpartidas_abandonadas_multijugador(ICollection* val) { partidas_abandonadas_multijugador = val; }
	private:
        string nickname;
        string descripcion;
		ICollection* puntajes;
		ICollection* partidas_iniciadas; // partidas que el jugador ha iniciado, independientemente si las ha finalizado o no
		ICollection* partidas_a_las_que_me_uni; // partidas(multijugador) actuales a las que el Jugador se ha unido
        ICollection* partidas_abandonadas_multijugador; // lista de AbandonaMultijugador
};

#endif // JUGADOR_H
