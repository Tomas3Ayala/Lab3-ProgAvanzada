#ifndef USERSCONTROLLERS_H
#define USERSCONTROLLERS_H

#include <IUsers.h>

enum class EnumMetodoPago
{
	Tarjeta,
	PayPal,
};

enum class EnumTipoSuscripcion
{
	Vitalicia,
	Mensual,
	Trimestral,
	Anual,
};

enum class TipoCategoria
{
	Plataforma,
	Genero,
	Otro,
};

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
		ICollection* listarVideojuegos();
		DtCostoSuscripcion listarSuscripciones(ICollectible* videojuego);
		void ingresarNombreVideojuegoParaSuscripcion(string nombre);
		void finalizarsuscripcion();
		void cancelarSuscripcionAnterior();
		void ingresarDatosSuscripcion(EnumMetodoPago metodo_pago, EnumTipoSuscripcion tipo);
		void darDeAltaSuscripcion();
		void cancelarSuscripcionAVideojuego();

		// agregar categoria
		void listarNombresCategorias();
		void agregarCategoria(string nombre, string descripcion, TipoCategoria tipo_categoria);

		// asignar puntaje a videojuego
		ICollection* listarVideojuegos();
		void asignarPuntaje(string nombre, int puntaje);

		// Otros
		IDictionary* listarNickNameDescripciones();
		DtCostoSuscripcion listarSuscripciones(string);
		ICollection* listarNombreCategorias();
    private:
    	static UsersControllers* instance;
        UsersControllers();

    	// Datos para todos los casos de usos
        IDictionary* usuarios;

		// alta de usuario y iniciar sesion
		string _email, _contrasenia, _nomempresa, _nickname, _descripcion;

		// suscribirse a videojuego y asignar puntaje a videojuego
		string nombre_videojuego;

		// agregar categoria
		string _nombre;
		TipoCategoria _tipo_categoria;

};

#endif // USERSCONTROLLERS_H
