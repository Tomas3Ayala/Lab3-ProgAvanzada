#ifndef USUARIO_H
#define USUARIO_H
#include "classes/Suscripcion.h"

class Usuario : public ICollectible
{
    public:
        Usuario();
        virtual ~Usuario();

        string Getemail() { return email; }
        void Setemail(string val) { email = val; }
        string Getcontrasenia() { return contrasenia; }
        void Setcontrasenia(string val) { contrasenia = val; }
        ICollection* Getsuscripciones() { return suscripciones; };
        void Setsuscripciones(ICollection* val) { suscripciones = val; };
        ICollection* Getsigue_a() { return sigue_a; };
        void Setsigue_a(ICollection* val) { sigue_a = val; };

    private:
        ICollection* suscripciones;
        ICollection* sigue_a; // no eliminar
        string email;
        string contrasenia;
};

#endif // USUARIO_H
