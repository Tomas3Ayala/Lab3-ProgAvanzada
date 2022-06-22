#ifndef IPARTIDAS_H
#define IPARTIDAS_H
#include "StandardHeaders.h"

class IPartidas
{
    public:
        virtual ~IPartidas()=0;
        virtual void realizarComentario()=0;
        virtual void abandonarPartida()=0;
        virtual void finalizarPartida()=0;
        virtual void iniciarPartida()=0;
        virtual ICollection* listarPartidas()=0;
        virtual ICollection* obtenerPartidas()=0;
        virtual ICollection* listarComentarios()=0;
        virtual ICollection* listarVideojuegosSuscritos()=0;







    private:
};

#endif // IPARTIDAS_H
