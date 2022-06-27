#include "controllers/UsersControllers.h"

UsersControllers* UsersControllers::instance = nullptr;

UsersControllers* UsersControllers::get_instance()
{
	if (instance == nullptr)
		instance = new UsersControllers;
	return instance;
}

UsersControllers::UsersControllers()
{
	usuarios = new Lista;
	usuario_seleccionado = nullptr;
}

UsersControllers::~UsersControllers()
{
	delete usuarios;
}

// alta de usuario
void UsersControllers::ingresarDatosUsuario(string email, string contrasenia)
{
	_email = email;
	_contrasenia = contrasenia;
}

void UsersControllers::ingresarempresa(string nomempresa)
{
	_nomempresa = nomempresa;
}

void UsersControllers::ingresardatos(string nickname, string descripcion)
{
	_nickname = nickname;
	_descripcion = descripcion;
}

void UsersControllers::cancelarAltaDeUsuario()
{
	// no se hace nada porque no se reservo memoria
}

void UsersControllers::altaUsuario()
{
	usuarios->add(new Jugador(_email, _contrasenia, _nickname, _descripcion));
}

// inicio de sesion
void UsersControllers::iniciarSesion(string email, string contrasenia)
{
	//
}

vector<string> UsersControllers::listarNicknames()
{
	vector<string> nicknames;
	IIterator* it = usuarios->iterator();
	Jugador* jugador;
	for (; it->hasNext(); it->next())
	{
		ICollectible* obj = it->getCurrent();
		if ((jugador = dynamic_cast<Jugador*>(obj)) != nullptr)
			nicknames.push_back(jugador->Getnickname());
	}
	return nicknames;
}

bool UsersControllers::datosInicioSesionCorrectos(string email, string contrasenia)
{
	//
}
