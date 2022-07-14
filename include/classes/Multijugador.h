#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H

#include <classes/Partida.h>


class Multijugador : public Partida
{
    public:
        Multijugador(int _participantes, bool transmitida_en_vivo, DtFechaHora _fecha_hora_comienzo);
        virtual ~Multijugador();

        int Getparticipantes() { return participantes; }
        void Setparticipantes(int val) { participantes = val; }
        bool Getes_transmitida_vivo() { return es_transmitida_vivo; }
        void Setes_transmitida_vivo(bool val) {es_transmitida_vivo = val; }

    private:
        int participantes;
        bool es_transmitida_vivo;
};

#endif // MULTIJUGADOR_H
