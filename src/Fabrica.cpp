#include "Fabrica.h"
#include "controllers/UsersControllers.h"
#include "controllers/PartidasController.h"
#include "controllers/VideojuegosController.h"
Fabrica* Fabrica::instance = nullptr;

Fabrica* Fabrica::get_instance()
{
	if (instance == nullptr)
		instance = new Fabrica;
	return instance;
}

Fabrica::~Fabrica()
{
	delete UsersControllers::get_instance();
	delete PartidasController::get_instance();
	delete VideojuegosController::get_instance();
}

IUsers* Fabrica::getIUsers()
{
	return UsersControllers::get_instance();
}

IPartidas* Fabrica::getIPartidas()
{
	return PartidasController::get_instance();
}

IVideojuegos* Fabrica::getIVideojuegos()
{
	return VideojuegosController::get_instance();
}

