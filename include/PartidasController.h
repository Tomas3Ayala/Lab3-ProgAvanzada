#ifndef PARTIDASCONTROLLER_H
#define PARTIDASCONTROLLER_H

#include <IPartidas.h>


class PartidasController : public IPartidas
{
    public:
		static PartidasController* get_instance();

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
    	static PartidasController* instance;
    	PartidasController();

};

#endif // PARTIDASCONTROLLER_H
