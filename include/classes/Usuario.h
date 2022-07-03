#ifndef USUARIO_H
#define USUARIO_H
#include "StandardHeaders.h"

class Usuario : public ICollectible
{
    public:
        Usuario();
        virtual ~Usuario();

        string Getemail() { return email; }
        void Setemail(string val) { email = val; }
        string Getcontrasenia() { return contrasenia; }
        void Setcontrasenia(string val) { contrasenia = val; }

    private:
        ICollection* suscripciones;
        string email;
        string contrasenia;
};

#endif // USUARIO_H
