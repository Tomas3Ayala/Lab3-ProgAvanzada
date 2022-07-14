#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <classes/Partida.h>


class Individual : public Partida
{
    public:
        Individual(bool _es_nueva, Individual* continua, DtFechaHora _fecha_hora_comienzo);
        virtual ~Individual();

        bool Getes_nueva() { return es_nueva; }
        void Setes_nueva(bool val) { es_nueva = val; }
        Individual* Getpartida_que_continua() { return partida_que_continua; }
        void Setpartida_que_continua(Individual* val) { partida_que_continua = val; }

    private:
        bool es_nueva;
        Individual* partida_que_continua;
};

#endif // INDIVIDUAL_H
