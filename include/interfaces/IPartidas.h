#ifndef IPARTIDAS_H
#define IPARTIDAS_H
#include "datatypes/DtFechaHora.h"
#include "datatypes/DtDatosPartida.h"

class IPartidas
{
    public:
        virtual ~IPartidas()=default;

		/*/ realizar comentario
		virtual ICollection* obtenerPartidas()=0; // DtPartidaInfo
		virtual void seleccionarPartida(int identificador)=0;
		virtual ICollection* listarComentarios()=0; // DtComentarioRealizado
		virtual void seleccionComentario(int identificador)=0;
		virtual void agregarTextoMensaje(string texto)=0;
		virtual void darDeAltaComentario(DtFechaHora fecha_hora)=0;
		virtual void cancelarRealizarComentario()=0;
		//*/

		// abandonar partida
		virtual ICollection* listarPartidasNoFinalizadasMultijugador()=0; // partidas
		virtual DtDatosPartida mostrarDatosPartida(ICollectible* partida)=0;
		virtual bool mostrarSiSeEstaTransmitiendoEnVivo(ICollectible* partida)=0;
		virtual string mostrarNicknameDelQueLaInicio(ICollectible* partida)=0;
		virtual vector<string> mostrarNicknamesParticipantes(ICollectible* partida)=0;
		virtual void confirmarPartidaQueDeseaAbandonar(int identificador)=0;

		// finalizar partida
		virtual ICollection* obtenerPartidasNoFinalizadasAlInicio()=0;
		// virtual DtDatosPartida mostrarDatosPartida(ICollectible* partida)=0;
		virtual bool mostrarSiEsContinuacion(ICollectible* partida)=0;
		// virtual bool mostrarSiSeEstaTransmitiendoEnVivo(ICollectible* partida)=0;
		// virtual vector<string> mostrarNicknamesParticipantes(ICollectible* partida)=0;
		virtual void confirmarPartidaQueDeseaFinalizar(int identificador)=0;

		// iniciar partida
		virtual void seleccionarVideojuego(ICollectible* videojuego)=0;
		virtual ICollection* listarPartidasEnOrden()=0; // partidas individuales
		// virtual void seleccionarPartida(int identificador)=0;
		virtual void esTransmitidaEnVivo(bool es_transmitida_en_vivo)=0;
		virtual vector<string> listarDemasJugadoresConSuscripcionActiva()=0;
		virtual void agregarParticipante(string nickname)=0;
		virtual void darDeAltaNuevaPartida()=0;

		// Otros
		virtual ICollection* listarPartidas()=0;
		//*/

};

#endif // IPARTIDAS_H
