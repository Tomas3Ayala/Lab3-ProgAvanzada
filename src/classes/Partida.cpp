#include "classes/Partida.h"

int Partida::ultimo_nro = 0;

Partida::Partida()
{
	comentarios = new Lista;
}

Partida::~Partida()
{
	comentarios = nullptr;
}
