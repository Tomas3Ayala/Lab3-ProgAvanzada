#include "Fabrica.h"

void alta_de_usuario_test();

void iniciar_sesion_test();

int main()
{
	while (1)
	{
		alta_de_usuario_test();
		iniciar_sesion_test();
		string salir;
		cout << "salir? (s/n): ";
		getline(cin, salir);
		if (salir == "s")
			break;
	}

	delete Fabrica::get_instance();
	return 0;
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
