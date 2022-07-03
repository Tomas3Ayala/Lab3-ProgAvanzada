#ifndef IUSERS_H
#define IUSERS_H
#include "datatypes/DtCostoSuscripcion.h"

class IUsers
{
    public:
        virtual ~IUsers()=default;


		// alta de usuario
		virtual void ingresarDatosUsuario(string email, string contrasenia)=0;
		virtual void ingresarempresa(string nomempresa)=0;
		virtual void ingresardatos(string nickname, string descripcion)=0;
		virtual void cancelarAltaDeUsuario()=0;
		virtual void altaUsuario()=0;

		// iniciar sesion
		virtual void iniciarSesion(string email, string contrasenia)=0;

		// seguir jugador
		virtual IDictionary* listarNicknamesYDescripciones()=0;
		void seleccionarJugador(string nickname); // tambien sigue al jugador

		// suscribirse a videojuego
		virtual ICollection* listarVideojuegos()=0;
		virtual DtCostoSuscripcion listarSuscripciones(ICollectible* videojuego)=0;
		virtual void ingresarNombreVideojuegoParaSuscripcion(string nombre)=0;
		virtual void finalizarsuscripcion()=0;
		virtual void cancelarSuscripcionAnterior()=0;
		virtual void ingresarDatosSuscripcion(EnumMetodoPago metodo_pago, EnumTipoSuscripcion tipo)=0;
		virtual void darDeAltaSuscripcion()=0;
		virtual void cancelarSuscripcionAVideojuego()=0;

		// agregar categoria
		virtual void listarNombresCategorias()=0;
		virtual void agregarCategoria(string nombre, string descripcion, TipoCategoria tipo_categoria)=0;

		// asignar puntaje a videojuego
		// virtual ICollection* listarVideojuegos()=0;
		virtual void asignarPuntaje(string nombre, int puntaje)=0;

		// Otros
		virtual IDictionary* listarNickNameDescripciones()=0;
		virtual DtCostoSuscripcion listarSuscripciones(string)=0;
		virtual ICollection* listarNombreCategorias()=0;

		//*/

		// Nueva
		virtual vector<string> listarNicknames()=0;
		virtual bool datosInicioSesionCorrectos(string email, string contrasenia)=0;

};

#endif // IUSERS_H
