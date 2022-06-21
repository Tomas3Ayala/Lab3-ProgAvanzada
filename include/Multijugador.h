#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H

#include <Partida.h>


class Multijugador : public Partida
{
    public:
        Multijugador();
        virtual ~Multijugador();

        int Getparticipantes() { return participantes; }
        void Setparticipantes(int val) { participantes = val; }
        bool Getes_transmitida_vivo() { return es_transmitida_vivo; }
        void Setes_transmitida_vivo(bool val) {es_transmitida_vivo = val; }

    protected:

    private:
        int participantes;
        bool es_transmitida_vivo;
};

#endif // MULTIJUGADOR_H
