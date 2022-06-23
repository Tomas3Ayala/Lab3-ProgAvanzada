#ifndef FABRICA_H
#define FABRICA_H
#include "UsersControllers.h"
#include "PartidasController.h"
#include "VideojuegosController.h"

class Fabrica
{
	public:
		static Fabrica* get_instance();

		IUsers* getIUsers();
		IPartidas* getIPartidas();
		IVideojuegos* getIVideojuegos();
	private:
		static Fabrica* instance;
		Fabrica() = default;
		~Fabrica();

		IUsers* users_interface;
		IPartidas* partidas_interface;
		IVideojuegos* videojuegos_interface;
};

#endif // FABRICA_H
