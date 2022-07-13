#ifndef FABRICA_H
#define FABRICA_H
#include "interfaces/IUsers.h"
#include "interfaces/IPartidas.h"
#include "interfaces/IVideojuegos.h"

class Fabrica
{
	public:
		static Fabrica* get_instance();
		~Fabrica();

		IUsers* getIUsers();
		IPartidas* getIPartidas();
		IVideojuegos* getIVideojuegos();
	private:
		static Fabrica* instance;
		Fabrica() = default;

		IUsers* users_interface;
		IPartidas* partidas_interface;
		IVideojuegos* videojuegos_interface;
};

#endif // FABRICA_H
