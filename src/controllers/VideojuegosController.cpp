#include "controllers/VideojuegosController.h"

VideojuegosController* VideojuegosController::instance = nullptr;

VideojuegosController* VideojuegosController::get_instance()
{
	if (instance == nullptr)
		instance = new VideojuegosController;
	return instance;
}

VideojuegosController::VideojuegosController()
{
	videojuegos = new Lista;
	categorias_de_videojuegos = new Lista;
	videojuego = nullptr;
}

VideojuegosController::~VideojuegosController()
{
	delete dynamic_cast<Lista*>(videojuegos);
	delete dynamic_cast<Lista*>(categorias_de_videojuegos);
}

ICollection* VideojuegosController::listarVideojuegos()
{
	return videojuegos;
}
