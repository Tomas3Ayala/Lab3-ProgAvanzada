#include "controllers/PartidasController.h"

PartidasController* PartidasController::instance = nullptr;

PartidasController* PartidasController::get_instance()
{
	if (instance == nullptr)
		instance = new PartidasController;
	return instance;
}

PartidasController::PartidasController()
{
	//
}
