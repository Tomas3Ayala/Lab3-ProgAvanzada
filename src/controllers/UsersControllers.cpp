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
	inicia_jugador = true;
}

void UsersControllers::ingresarempresa(string nomempresa)
{
	_nomempresa = nomempresa;
	inicia_jugador = false;
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
	if (inicia_jugador)
		usuarios->add(new Jugador(_email, _contrasenia, _nickname, _descripcion));
	else
		usuarios->add(new Desarrollador(_email, _contrasenia, _nomempresa));
}

// inicio de sesion
void UsersControllers::iniciarSesion(string email, string contrasenia)
{
	IIterator* it = usuarios->iterator();
	Usuario* usuario;
	for (; it->hasNext(); it->next())
	{
		ICollectible* obj = it->getCurrent();
		if ((usuario = dynamic_cast<Usuario*>(obj)) != nullptr)
		{
			if (usuario->Getemail() == email && usuario->Getcontrasenia() == contrasenia)
			{
				usuario_seleccionado = obj;

				cout << "se seleccione el usuario, el cual es un ";
				Jugador* jugador;
				Desarrollador* desarrollador;
				if ((jugador = dynamic_cast<Jugador*>(obj)) != nullptr)
				{
					cout << "jugador, tiene el siguiente nickname y descripcion: " << endl;
					cout << "nickname: " << jugador->Getnickname() << endl;
					cout << "descripcion: " << jugador->Getdescripcion() << endl;
				}
				if ((desarrollador = dynamic_cast<Desarrollador*>(obj)) != nullptr)
					cout << "desarrollador, trabaja para la siguiente empresa: " << desarrollador->Getempresa_donde_trabaja() << endl;
				return;
			}
		}
	}
}

// seguir jugador
ICollection* UsersControllers::listarNicknamesYDescripciones()
{
	return usuarios;
}

void UsersControllers::seleccionarJugador(string nickname) // tambien sigue al jugador
{
	IIterator* it = usuarios->iterator();
	Jugador* jugador;
	for (; it->hasNext(); it->next())
	{
		ICollectible* obj = it->getCurrent();
		if ((jugador = dynamic_cast<Jugador*>(obj)) != nullptr)
		{
			if (jugador->Getnickname() == nickname)
				break;
		}
	}
	Usuario* usuario = dynamic_cast<Usuario*>(usuario_seleccionado);
	usuario->Getsigue_a()->add(jugador);
}

// otro datos

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
	IIterator* it = usuarios->iterator();
	Usuario* usuario;
	for (; it->hasNext(); it->next())
	{
		ICollectible* obj = it->getCurrent();
		if ((usuario = dynamic_cast<Usuario*>(obj)) != nullptr)
		{
			if (usuario->Getemail() == email && usuario->Getcontrasenia() == contrasenia)
				return true;
		}
	}
	return false;
}
