#ifndef USERSCONTROLLERS_H
#define USERSCONTROLLERS_H

#include <interfaces/IUsers.h>
#include "controllers/VideojuegosController.h"
#include "classes/Jugador.h"
#include "classes/Desarrollador.h"

class UsersControllers : public IUsers
{
    public:
    	static UsersControllers* get_instance();

		~UsersControllers();

		// alta de usuario
		void ingresarDatosUsuario(string email, string contrasenia);
		void ingresarempresa(string nomempresa);
		void ingresardatos(string nickname, string descripcion);
		void cancelarAltaDeUsuario();
		void altaUsuario();

		// iniciar sesion
		void iniciarSesion(string email, string contrasenia);

		// seguir jugador
		IDictionary* listarNicknamesYDescripciones();
		void seleccionarJugador(string nickname); // tambien sigue al jugador

		// suscribirse a videojuego
		void ingresarNombreVideojuegoParaSuscripcion(string nombre);
		void finalizarsuscripcion();
		void cancelarSuscripcionAnterior();
		void ingresarDatosSuscripcion(EnumMetodoPago metodo_pago, EnumTipoSuscripcion tipo);
		void darDeAltaSuscripcion();
		void cancelarSuscripcionAVideojuego();

		// asignar puntaje a videojuego
		// ICollection* listarVideojuegos();
		void asignarPuntaje(string nombre, int puntaje);

		// Otros
		//DtCostoSuscripcion listarSuscripciones(string);
		ICollection* listarNombreCategorias();

		vector<string> listarNicknames();
		bool datosInicioSesionCorrectos(string email, string contrasenia);

		ICollectible* get_usuario_seleccionado() { return usuario_seleccionado; }
    private:
    	static UsersControllers* instance;
        UsersControllers();

    	// Datos para todos los casos de usos
        IDictionary* usuarios;

        // cuenta actual
		ICollectible* usuario_seleccionado;

		// alta de usuario y iniciar sesion
		string _email, _contrasenia, _nomempresa, _nickname, _descripcion;
		bool inicia_jugador; // controla si inicia jugador o desarrollador

		// suscribirse a videojuego y asignar puntaje a videojuego
		string nombre_videojuego;

};

#endif // USERSCONTROLLERS_H
