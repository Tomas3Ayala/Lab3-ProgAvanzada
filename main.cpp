#include "CategoriaGenero.h"
#include "CategoriaPlataforma.h"
#include "NuevaCategoria.h"
#include "Fabrica.h"

void iniciar_partida();

void alta_de_usuario();

bool iniciar_sesion();

void seguir_jugador();

void publicar_videojuego();

void suscribirse_a_un_videojuego();

void agregar_categoria();

void eliminar_videojuego();

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
							cout << "Suscribirse a un videojuego, seguir jugador o salir" << endl;
							cout << "Opcion: ";
							getline(cin, opcion);
							if (opcion == "1")
								suscribirse_a_un_videojuego();
							else if (opcion == "2")
								seguir_jugador();
							else
								break;
						}
					}
					else
					{
						cout << "veo que es un desarrollador!" << endl;
						while (1)
						{
							cout << "Agregar categoria, publicar videojuego, eliminar videojuego, ver informacion de videojuego, o salir" << endl;
							cout << "Opcion: ";
							getline(cin, opcion);
							if (opcion == "1")
								agregar_categoria();
							else if (opcion == "2")
								publicar_videojuego();
							else if (opcion == "3")
								eliminar_videojuego();
							else
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

void eliminar_videojuego()
{
//	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	cout << "AUN NO ESTA HECHO" << endl;
}

void agregar_categoria()
{
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	games->listarNombresCategorias();
	TipoCategoria tipo_categoria;
	string nombre, descripcion, tipo;
	cout << "Nombre de la categoria: ";
	getline(cin, nombre);
	cout << "Descripcion de la categoria: ";
	getline(cin, descripcion);
	cout << "Tipos de categorias:" << endl;
	cout << "\t1. Genero" << endl;
	cout << "\t2. Plataforma" << endl;
	cout << "\t3. Otra" << endl;
	cout << "Tipo de categoria: ";
	getline(cin, tipo);
	if (tipo == "1")
		tipo_categoria = TipoCategoria::Genero;
	else if (tipo == "2")
		tipo_categoria = TipoCategoria::Plataforma;
	else
		tipo_categoria = TipoCategoria::Otro;
	games->agregarNuevaCategoria(nombre, descripcion, tipo_categoria);
	string dar_de_alta;
	cout << "Dar de alta nueva categoria? (s/n): ";
	getline(cin, dar_de_alta);
	if (dar_de_alta == "s")
		games->darDeAltaNuevaCategoria();
	else
		games->cancelarNuevaCategoria();
}

void suscribirse_a_un_videojuego()
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();

	ICollection* videojuegos = games->listarVideojuegos();
	if (videojuegos->isEmpty())
	{
		cout << "No hay videojuegos a los que suscribirse." << endl;
		return;
	}
	cout << "Videojuegos a los que ya esta suscrito:" << endl;
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		bool a_este_videojuego_esta_suscrito = false;
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
		for (IIterator* jt = jugador->Getsuscripciones()->iterator(); jt->hasNext(); jt->next())
		{
			Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(jt->getCurrent());
			if (videojuego == suscripcion->Getvideojuego())
			{
				a_este_videojuego_esta_suscrito = true;
				break;
			}
		}
		if (a_este_videojuego_esta_suscrito)
		{
			DtCostoSuscripcion costo = games->listarSuscripciones(it->getCurrent());
			cout << "Nombre de videojuego: " << dynamic_cast<Videojuego*>(it->getCurrent())->Getnombre() << endl;
			cout << "  Costo mensual: " << costo.Getcosto_mensual() << endl;
			cout << "  Costo trimestral: " << costo.Getcosto_trimestral() << endl;
			cout << "  Costo anual: " << costo.Getcosto_anual() << endl;
			cout << "  Costo vitalicia: " << costo.Getcosto_vitalicia() << endl;
		}
	}
	cout << "Videojuegos a los que no esta suscrito:" << endl;
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		bool a_este_videojuego_esta_suscrito = false;
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
		for (IIterator* jt = jugador->Getsuscripciones()->iterator(); jt->hasNext(); jt->next())
		{
			Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(jt->getCurrent());
			if (videojuego == suscripcion->Getvideojuego())
			{
				a_este_videojuego_esta_suscrito = true;
				break;
			}
		}
		if (!a_este_videojuego_esta_suscrito)
		{
			DtCostoSuscripcion costo = games->listarSuscripciones(it->getCurrent());
			cout << "Nombre de videojuego: " << dynamic_cast<Videojuego*>(it->getCurrent())->Getnombre() << endl;
			cout << "  Costo mensual: " << costo.Getcosto_mensual() << endl;
			cout << "  Costo trimestral: " << costo.Getcosto_trimestral() << endl;
			cout << "  Costo anual: " << costo.Getcosto_anual() << endl;
			cout << "  Costo vitalicia: " << costo.Getcosto_vitalicia() << endl;
		}
	}
	string nombre;
	cout << "Nombre de videojuego a suscribirse: ";
	getline(cin, nombre);
	users->ingresarNombreVideojuegoParaSuscripcion(nombre);
	cout << "AUN NO HECHO" << endl;
}

void publicar_videojuego()
{
	cout << "Aqui es donde se publica el videojuego" << endl;
	IUsers* users = Fabrica::get_instance()->getIUsers();
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();

	DtCostoSuscripcion costo_suscripcion;
	string nombre, descripcion, costo;
	cout << "Nombre del videojuego: ";
	getline(cin, nombre);
	cout << "Descripcion del videojuego: ";
	getline(cin, descripcion);
	cout << "Costo mensual: ";
	getline(cin, costo);
	costo_suscripcion.Setcosto_mensual(stoi(costo));
	cout << "Costo trimestral: ";
	getline(cin, costo);
	costo_suscripcion.Setcosto_trimestral(stoi(costo));
	cout << "Costo anual: ";
	getline(cin, costo);
	costo_suscripcion.Setcosto_anual(stoi(costo));
	cout << "Costo vitalicia: ";
	getline(cin, costo);
	costo_suscripcion.Setcosto_vitalicia(stoi(costo));
	games->agregarVideojuego(nombre, descripcion, dynamic_cast<Desarrollador*>(users->get_usuario_seleccionado())->Getempresa_donde_trabaja(), costo_suscripcion);

	int cantidad = 0;
	for (int j = 0; j < 3; j++)
	{
		while (1)
		{
			ICollection* categorias;
			if (j == 0)
			{
				cout << "Lista de generos:" << endl;
				categorias = games->listarCategoriaGeneros();
			}
			else if (j == 1)
			{
				cout << "Lista de plataformas:" << endl;
				categorias = games->listarCategoriaPlataforma();
			}
			else
			{
				cout << "Resto de categorias:" << endl;
				categorias = games->listarRestoCategorias();
			}
			if (categorias->isEmpty())
			{
				cout << "No hay categorias de este tipo." << endl;
				break;
			}
			size_t i = 1;
			for (IIterator* it = categorias->iterator(); it->hasNext(); it->next(), i++)
			{
				CategoriaDeVideojuegos* categoria = dynamic_cast<CategoriaDeVideojuegos*>(it->getCurrent());
				cout << i << ".\n  Nombre: " << categoria->Getnombre() << "\n  Descripcion: " << categoria->Getdescripcion() << endl;
			}

			string id;
			cout << "Eliga genero a agregar, o escriba 's' para continuar: ";
			getline(cin, id);
			if (id == "s")
			{
				if (cantidad == 0 && j != 2)
				{
					cout << "Tiene que seleccionar al menos una categoria!" << endl;
					continue;
				}
				cantidad = 0;
				break;
			}
			else if (static_cast<size_t>(stoi(id)) > i || static_cast<size_t>(stoi(id)) < 1)
			{
				cout << "Esa opcion no esta en el rango de categorias que se listaron..." << endl;
				continue;
			}
			else
			{
				cantidad += 1;
				ICollectible* categoria_seleccionada;
				i = 1;
				for (IIterator* it = categorias->iterator(); it->hasNext(); it->next(), i++)
				{
					ICollectible* categoria = it->getCurrent();
					if (i == static_cast<size_t>(stoi(id)))
					{
						categoria_seleccionada = categoria;
						break;
					}
				}
				if (j == 0) games->agregarCategoriaGenero(categoria_seleccionada);
				if (j == 1) games->agregarCategoriaPlataforma(categoria_seleccionada);
				if (j == 2) games->agregarCategoria(categoria_seleccionada);
			}
		}
	}
	games->mostrarInformacionIngresadaDelVideojuego();
	string dar_de_alta;
	cout << "Dar de alta videojuego? (s/n): ";
	getline(cin, dar_de_alta);
	if (dar_de_alta == "s")
		games->darDeAltaVideojuego();
	else
		games->cancelarCreacionDeVideojuego();

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
	IUsers* user = Fabrica::get_instance()->getIUsers();//primero creo una instancia llamada user que va a ser igual a una nueva instancia de user esto nose si es que trae todos los usuarios
	string desa, juga, cancel, confirm;//estas variables las utsaremos para guardar la respuesta del usuario
    string mail, contra; //declaro las variables que voy a pedir en un principio
    string empresa, nic, descr; //variables para cuando sea desarrollador o jugador
    bool existente = false;//esta variable sera usada para confirmar si esta el nick name ya existe en caso que sea jugador
	//pido al usuario que ingrese las variables y las guardo
	cout<<"Por favor, ingrese su email";cout<<endl;
	getline (cin, mail);
	cout<<"Por favor, ingrese una clave para el usuario";cout<<endl;
	getline (cin, contra);
	//una vez consigo los datos llamo a funcion para ingresarlos detallada en el digrama de secuencia
	//debo utilizar la intancia user creada en un principio
	user->ingresarDatosUsuario(mail,contra);//los datos son enviados al controlador que los guarda en memoria
	//continuo con el caso de uso y lo siguiente es preguntar que tipo de usuario sera

	cout<<"Desea crear un usuario desarrollador? s/n";cout<<endl;
	getline(cin,desa);
	if (desa=="s"||desa=="S")
    {
       cout<<"Por favor ingrese el nombre de la empresa para la cual trabaja";cout<<endl;
       getline(cin, empresa);
       user->ingresarempresa(empresa);//envio el nombre d ela empresa al controlador
    }

	else
    {
        do
        {
            cout<<"Por favor ingrese el nick name de jugador con el que desea registrarse ";cout<<endl;
            getline(cin, nic);
            for (string& nick : user->listarNicknames())
            {
                if (nick == nic)
                {
                    existente = true;
                    break;
                }
            }
            if (existente)
            {
                cout<<"El nickname ingresado no esta disponible, desea cancelar? s/n";cout<<endl;
                getline(cin, cancel);
                if (cancel=="s"||cancel == "S")
                {
                    user->cancelarAltaDeUsuario();
                    return;
                }

            }
        }while(existente);
        cout<<"Ingrese descripcion del jugador";cout<<endl;
        getline(cin, descr);
        user->ingresardatos(nic,descr);
    }
        cout<<"Desea confirmar el alta del usuario? s/n";cout<<endl;
        getline(cin, confirm);
        if(confirm=="s"||confirm == "S")
        {
            user->altaUsuario();
        }
        else
        {
            user->cancelarAltaDeUsuario();
        }

}

void iniciar_partida()
{
    IUsers* users = Fabrica::get_instance()->getIUsers();
	if (users->get_usuario_seleccionado() == nullptr)
	{
		cout << "Ningun usuario ha iniciado sesion" << endl;
		return;
	}

    IPartidas* parti = Fabrica::get_instance()->getIPartidas();
    IVideojuegos* game = Fabrica::get_instance()->getIVideojuegos();
    cout<<"videojuegos suscriptos: ";cout<<endl;
    game->listarVideojuegosSuscritos();

}
