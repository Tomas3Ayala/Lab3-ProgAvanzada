#ifndef PARTIDASCONTROLLER_H
#define PARTIDASCONTROLLER_H

#include <IPartidas.h>


class PartidasController : public IPartidas
{
    public:
        ~PartidasController();
        void realizarComentario();
        void abandonarPartida();
        void finalizarPartida();
        void iniciarPartida();
        ICollection* listarPartidas();
        ICollection* obtenerPartidas();
        ICollection* listarComentarios();
        ICollection* listarVideojuegosSuscritos();

    private:
         PartidasController();

};

#endif // PARTIDASCONTROLLER_H
