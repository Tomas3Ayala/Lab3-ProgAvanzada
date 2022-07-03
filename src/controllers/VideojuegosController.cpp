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
	//
}
