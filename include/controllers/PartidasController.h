#ifndef PARTIDASCONTROLLER_H
#define PARTIDASCONTROLLER_H

#include <interfaces/IPartidas.h>
#include "classes/Partida.h"
#include "classes/AbandonaMultijugador.h"
#include "classes/Individual.h"
#include "classes/Multijugador.h"
#include "classes/Jugador.h"
#include "Fabrica.h"
#include "datatypes/DtDatosPartida.h"

class PartidasController : public IPartidas
{
	public:
		static PartidasController* get_instance();

		~PartidasController() = default;

		// realizar comentario
		ICollection* obtenerPartidas(); // DtPartidaInfo
		void seleccionarPartida(int identificador);
		ICollection* listarComentarios(); // DtComentarioRealizado
		void seleccionComentario(int identificador);
		void agregarTextoMensaje(string texto);
		void darDeAltaComentario(DtFechaHora fecha_hora);
		void cancelarRealizarComentario();

		// abandonar partida
		ICollection* listarPartidasNoFinalizadasMultijugador(); // partidas
		DtDatosPartida mostrarDatosPartida(ICollectible* partida);
		bool mostrarSiSeEstaTransmitiendoEnVivo(ICollectible* partida);
		string mostrarNicknameDelQueLaInicio(ICollectible* partida);
		vector<string> mostrarNicknamesParticipantes(ICollectible* partida);
		void confirmarPartidaQueDeseaAbandonar(int identificador);

		// finalizar partida
		ICollection* obtenerPartidasNoFinalizadasAlInicio();
		// DtDatosPartida mostrarDatosPartida(ICollectible* partida);
		bool mostrarSiEsContinuacion(ICollectible* partida);
		// bool mostrarSiSeEstaTransmitiendoEnVivo(ICollectible* partida);
		// vector<string> mostrarNicknamesParticipantes(ICollectible* partida);
		void confirmarPartidaQueDeseaFinalizar(int identificador);

		// iniciar partida

		void seleccionarVideojuego(ICollectible* videojuego);
		ICollection* listarPartidasEnOrden(); // partidas individuales
		// void seleccionarPartida(int identificador);
		void esTransmitidaEnVivo(bool es_transmitida_en_vivo);
		vector<string> listarDemasJugadoresConSuscripcionActiva();
		void agregarParticipante(string nickname);
		void darDeAltaNuevaPartida();

		// Otros
		ICollection* listarPartidas();

	private:
		static PartidasController* instance;
		PartidasController();

		// realizar comentario
		int partida_seleccionada, comentario_a_responder;
		string texto_mensaje;
		DtFechaHora fecha_hora_del_comentario;

		// abandonar partida
		int identificador_de_partida_a_abandonar;

		// iniciar partida
		int identificador_de_partida_a_continuar;
		ICollectible* videojuego_para_empezar_partida;
		bool es_transmitida_en_vivo_multijugador;
};

#endif // PARTIDASCONTROLLER_H
