#include "Fabrica.h"

void alta_de_usuario();

bool iniciar_sesion();

void seguir_jugador();

int main()
{
	bool salir = false;
	while (!salir)
	{
		string opcion;
		cout << "Alta de usuario, Iniciar sesion o salir" << endl;
		cout << "Opcion: ";
		getline(cin, opcion);
		if (opcion == "1")
			alta_de_usuario();
		else if (opcion == "2")
		{
			if (iniciar_sesion())
			{
				IUsers* users = Fabrica::get_instance()->getIUsers();
				Usuario* usuario = dynamic_cast<Usuario*>(users->get_usuario_seleccionado());
				if (usuario != nullptr)
				{
					Jugador* jugador = dynamic_cast<Jugador*>(usuario);
					if (jugador)
					{
						cout << "veo que es un jugador!" << endl;
						while (1)
						{
							cout << "Seguir jugador o salir" << endl;
							cout << "Opcion: ";
							getline(cin, opcion);
							if (opcion == "1")
								seguir_jugador();
							else if (opcion == "2")
								break;
						}
					}
					else
					{
						cout << "veo que es un desarrollador!" << endl;
						while (1)
						{
							cout << "Otras opciones o salir" << endl;
							cout << "Opcion: ";
							getline(cin, opcion);
							if (opcion == "2")
								break;
						}
					}
				}
				else
					cout << "pues no" << endl;
			}
		}
		else
			break;
	}

	delete Fabrica::get_instance();
	return 0;
}

void seguir_jugador()
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	if (users->get_usuario_seleccionado() == nullptr)
	{
		cout << "Ningun usuario ha iniciado sesion" << endl;
		return;
	}

	IDictionary* usuarios = users->listarNicknamesYDescripciones();

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
		for (IIterator* it = usuarios->getIteratorObj(); it->hasNext(); it->next())
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

bool iniciar_sesion()
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
			return true;
		}
		else
		{
			string nuevamente;
			cout << "contrasenia o usuario incorrectos." << endl;
			cout << "desea intentarlo de nuevo? (s/n): ";
			getline(cin, nuevamente);
			if (nuevamente != "s")
				return false;
		}
	}
}

void alta_de_usuario()
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
