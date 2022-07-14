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
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	ICollection* videojuegos = games->listarVideojuegos();
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		if (videojuego->Getnombre() == nombre_videojuego)
		{
			Jugador* jugador = dynamic_cast<Jugador*>(usuario_seleccionado);
			ICollection* suscripciones = jugador->Getsuscripciones();
			for (IIterator* jt = suscripciones->iterator(); jt->hasNext(); jt->next())
			{
				Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(jt->getCurrent());
				if (suscripcion->Getvideojuego() == videojuego)
				{
					Temporal* temporal = dynamic_cast<Temporal*>(suscripcion);
					temporal->Setfecha_cancelacion(DtFechaHora().tiempo_actual());
					temporal->Setestado(false);
					break;
				}
			}
			break;
		}
	}
}

void UsersControllers::ingresarDatosSuscripcion(EnumMetodoPago metodo_pago, EnumTipoSuscripcion tipo)
{
	_metodo_pago = metodo_pago;
	_tipo_suscripcion = tipo;
}

void UsersControllers::darDeAltaSuscripcion()
{
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	ICollection* videojuegos = games->listarVideojuegos();
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		if (videojuego->Getnombre() == nombre_videojuego)
		{
			DtCostoSuscripcion costo = videojuego->Getcosto_suscripcion();
			Jugador* jugador = dynamic_cast<Jugador*>(usuario_seleccionado);
			ICollection* suscripciones = jugador->Getsuscripciones();
			switch (_tipo_suscripcion)
			{
			case EnumTipoSuscripcion::Mensual:
				suscripciones->add(new Temporal(costo.Getcosto_mensual(), EnumValidez::UN_MES, _metodo_pago, costo.Getcosto_mensual(), DtFechaHora().tiempo_actual(), videojuego));
				break;
			case EnumTipoSuscripcion::Trimestral:
				suscripciones->add(new Temporal(costo.Getcosto_trimestral(), EnumValidez::TRIMESTRE, _metodo_pago, costo.Getcosto_trimestral(), DtFechaHora().tiempo_actual(), videojuego));
				break;
			case EnumTipoSuscripcion::Anual:
				suscripciones->add(new Temporal(costo.Getcosto_anual(), EnumValidez::ANIO, _metodo_pago, costo.Getcosto_anual(), DtFechaHora().tiempo_actual(), videojuego));
				break;
			case EnumTipoSuscripcion::Vitalicia:
				suscripciones->add(new Vitalicia(costo.Getcosto_vitalicia(), _metodo_pago, costo.Getcosto_vitalicia(), DtFechaHora().tiempo_actual(), videojuego));
				break;
			}
		}
	}
}

void UsersControllers::cancelarSuscripcionAVideojuego()
{
	//
}

// asignar puntaje a videojuego
void UsersControllers::asignarPuntaje(string nombre, int puntaje)
{
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	ICollection* videojuegos = games->listarVideojuegos();
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		if (videojuego->Getnombre() == nombre)
		{
			Jugador* jugador = dynamic_cast<Jugador*>(usuario_seleccionado);
			ICollection* puntajes = jugador->Getpuntajes();
			puntajes->add(new AsignaPuntaje(puntaje, videojuego));
		}
	}
}

// otro datos
IDictionary* UsersControllers::listarUsuarios()
{
	return usuarios;
}

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
