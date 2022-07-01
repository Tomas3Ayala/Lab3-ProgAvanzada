#include "Fabrica.h"

void alta_de_usuario_test();

void iniciar_sesion_test();

void seguir_jugador_test();

int main()
{
	while (1)
	{
		string opcion;
		cout << "opcion: ";
		getline(cin, opcion);
		if (opcion == "1")
			alta_de_usuario_test();
		else if (opcion == "2")
			iniciar_sesion_test();
		else
			seguir_jugador_test();

		string salir;
		cout << "salir? (s/n): ";
		getline(cin, salir);
		if (salir == "s")
			break;
	}

	delete Fabrica::get_instance();
	return 0;
}

void seguir_jugador_test()
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	if (users->get_usuario_seleccionado() == nullptr)
	{
		cout << "Ningun usuario ha iniciado sesion" << endl;
		return;
	}

	ICollection* usuarios = users->listarNicknamesYDescripciones();

	// string que contiene el nickname del jugador seleccionado
	string no_puede_ser;
	Jugador* jugador_seleccionado;
	if ((jugador_seleccionado = dynamic_cast<Jugador*>(users->get_usuario_seleccionado())) != nullptr)
		no_puede_ser = jugador_seleccionado->Getnickname();
	else
	{
		cout << "El usuario que inicio sesion tiene que ser un jugador para este caso" << endl;
		return;
	}

	string nickname_a_seguir;
	while (true)
	{
		cout << "Lista de jugadores en el sistema: " << endl;
		bool hubo_jugadores = false;
		Jugador* jugador;
		for (IIterator* it = usuarios->iterator(); it->hasNext(); it->next())
		{
			ICollectible* obj = it->getCurrent();
			if ((jugador = dynamic_cast<Jugador*>(obj)) != nullptr)
			{
				if (no_puede_ser != jugador->Getnickname())
				{
					cout << jugador->Getnickname() << ", " << jugador->Getdescripcion() << endl;
					hubo_jugadores = true;
				}
			}
		}
		if (!hubo_jugadores)
		{
			cout << " Ninguno." << endl;
			return;
		}

		cout << "Escriba el nickname del jugador al que desea seguir: ";
		getline(cin, nickname_a_seguir);

		bool esta = false;
		for (string& nick : users->listarNicknames())
		{
			if (nick == nickname_a_seguir)
			{
				esta = true;
				break;
			}
		}
		if (!esta)
		{
			string desea_cancelar;
			cout << "El nickname que escribio no esta en las opciones, desea cancelar? (s/n): ";
			getline(cin, desea_cancelar);
			if (desea_cancelar == "s")
				break;
			else
				continue;
		}
		users->seleccionarJugador(nickname_a_seguir);
		break;
	}
}

void iniciar_sesion_test()
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	string email, contra;
	while (1)
	{
		cout << "email del usuario: ";
		getline(cin, email);
		cout << "contrasenia del usuario: ";
		getline(cin, contra);
		if (users->datosInicioSesionCorrectos(email, contra))
		{
			users->iniciarSesion(email, contra);
			cout << "iniciado correctamente!" << endl;
			return;
		}
		else
		{
			string nuevamente;
			cout << "contrasenia o usuario incorrectos." << endl;
			cout << "desea intentarlo de nuevo? (s/n): ";
			getline(cin, nuevamente);
			if (nuevamente != "s")
				return;
		}
	}
}

void alta_de_usuario_test()
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	string email, contra;
	cout << "email del usuario: ";
	getline(cin, email);
	cout << "contrasenia del usuario: ";
	getline(cin, contra);
	users->ingresarDatosUsuario(email, contra);

	string es_desarrollador;
	cout << "Sos desarrollador? (s/n): ";
	getline(cin, es_desarrollador);
	if (es_desarrollador == "s")
	{
		string empresa;
		cout << "Nombre de la empresa en la que trabaja: ";
		getline(cin, empresa);
		users->ingresarempresa(empresa);
	}
	else
	{
		bool esta_repetido = false;
		string nickname, descripcion;
		do
		{
			cout << "Nickname: ";
			getline(cin, nickname);
			esta_repetido = false;
			for (string& nick : users->listarNicknames())
			{
				if (nick == nickname)
				{
					esta_repetido = true;
					break;
				}
			}
			if (esta_repetido)
			{
				string cancelo;
				cout << "Nickname ya elegido, desea cancelar? (s/n): ";
				getline(cin, cancelo);
				if (cancelo == "s")
				{
					users->cancelarAltaDeUsuario();
					return;
				}
			}
		} while (esta_repetido);
		cout << "Descripcion: ";
		getline(cin, descripcion);
		users->ingresardatos(nickname, descripcion);
	}
	string confirmo;
	cout << "Desea confirmar alta de usuario? (s/n): ";
	getline(cin, confirmo);
	if (confirmo == "s")
		users->altaUsuario();
	else
		users->cancelarAltaDeUsuario();
}
