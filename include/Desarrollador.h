#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H

#include <Usuario.h>


class Desarrollador : public Usuario
{
    public:
        Desarrollador();
        virtual ~Desarrollador();

        string Getempresa_donde_trabaja() { return empresa_donde_trabaja; }
        void Setempresa_donde_trabaja(string val) { empresa_donde_trabaja = val; }

    protected:

    private:
        string empresa_donde_trabaja;
};

#endif // DESARROLLADOR_H
