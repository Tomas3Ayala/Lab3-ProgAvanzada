#ifndef USERSCONTROLLERS_H
#define USERSCONTROLLERS_H

#include <IUsers.h>


class UsersControllers : public IUsers
{
    public:

    ~UsersControllers();
    void altaDeUsuario();
    void iniciarSesion();
    void seguirJugador();
    void suscribirseVideojuego();
    void agregarCategoria();
    ICollection* listarNickNameDescripciones();
    DtCostoSuscripcion listarSuscripciones(string);
    ICollection* listarNombreCategorias();

    private:
        ICollection* usuarios;
        UsersControllers();
};

#endif // USERSCONTROLLERS_H
