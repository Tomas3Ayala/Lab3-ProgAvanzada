#ifndef IUSERS_H
#define IUSERS_H
#include "DtCostoSuscripcion.h"

class IUsers
{
    public:
        virtual ~IUsers()=0;
        virtual void altaDeUsuario()=0;
        virtual void iniciarSesion()=0;
        virtual void seguirJugador()=0;
        virtual void suscribirseVideojuego()=0;
        virtual void agregarCategoria()=0;
        virtual ICollection* listarNickNameDescripciones()=0;
        virtual DtCostoSuscripcion listarSuscripciones(string)=0;
        virtual ICollection* listarNombreCategorias()=0;




    private:
};

#endif // IUSERS_H
