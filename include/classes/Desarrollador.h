#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H

#include <classes/Usuario.h>


class Desarrollador : public Usuario
{
    public:
        Desarrollador(string _email, string _contrasenia, string empresa);

        string Getempresa_donde_trabaja() { return empresa_donde_trabaja; }
        void Setempresa_donde_trabaja(string val) { empresa_donde_trabaja = val; }

    private:
        string empresa_donde_trabaja;
};

#endif // DESARROLLADOR_H
