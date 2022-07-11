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
	usuarios = new ListDicc;
	usuario_seleccionado = nullptr;
}

UsersControllers::~UsersControllers()
{
	delete dynamic_cast<ListDicc*>(usuarios);
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
		usuarios->add(new Jugador(_email, _contrasenia, _nickname, _descripcion), new KeyString(_email));
	else
		usuarios->add(new Desarrollador(_email, _contrasenia, _nomempresa), new KeyString(_email));
}

// inicio de sesion
void UsersControllers::iniciarSesion(string email, string contrasenia)
{
	KeyString* str = new KeyString(email);
	Usuario* usuario = dynamic_cast<Usuario*>(usuarios->find(str));
	delete str;
	if (usuario != nullptr)
	{
		usuario_seleccionado = usuario;

		cout << "se seleccione el usuario, el cual es un ";
		Jugador* jugador;
		Desarrollador* desarrollador;
		if ((jugador = dynamic_cast<Jugador*>(usuario)) != nullptr)
		{
			cout << "jugador, tiene el siguiente nickname y descripcion: " << endl;
			cout << "nickname: " << jugador->Getnickname() << endl;
			cout << "descripcion: " << jugador->Getdescripcion() << endl;
		}
		if ((desarrollador = dynamic_cast<Desarrollador*>(usuario)) != nullptr)
			cout << "desarrollador, trabaja para la siguiente empresa: " << desarrollador->Getempresa_donde_trabaja() << endl;
	}
}

// seguir jugador
IDictionary* UsersControllers::listarNicknamesYDescripciones()
{
	return usuarios;
}

void UsersControllers::seleccionarJugador(string nickname) // tambien sigue al jugador
{
	IIterator* it = usuarios->getIteratorObj();
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

// suscribirse a videojuego
void UsersControllers::ingresarNombreVideojuegoParaSuscripcion(string nombre)
{
	nombre_videojuego = nombre;
}

void UsersControllers::finalizarsuscripcion()
{
	//
}

void UsersControllers::cancelarSuscripcionAnterior()
{
	//
}

void UsersControllers::ingresarDatosSuscripcion(EnumMetodoPago metodo_pago, EnumTipoSuscripcion tipo)
{
	//
}

void UsersControllers::darDeAltaSuscripcion()
{
	//
}

void UsersControllers::cancelarSuscripcionAVideojuego()
{
	//
}

// otro datos

vector<string> UsersControllers::listarNicknames()
{
	vector<string> nicknames;
	IIterator* it = usuarios->getIteratorObj();
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
	IIterator* it = usuarios->getIteratorObj();
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
