#include "CategoriaGenero.h"
#include "CategoriaPlataforma.h"
#include "NuevaCategoria.h"
#include "Jugador.h"
#include "Desarrollador.h"
#include "Vitalicia.h"
#include "Temporal.h"
#include "Partida.h"
#include "Individual.h"
#include "Fabrica.h"

void iniciar_partida();

void alta_de_usuario();

bool iniciar_sesion();

void cargar_datos_de_prueba();

void seguir_jugador();

void publicar_videojuego();

void suscribirse_a_un_videojuego();

void agregar_categoria();

void ver_informacion_de_videojuego();

void asigna_puntaje_a_videojuego();

void eliminar_videojuego();

void abandona_partida_multijugador();

void finalizar_partida();

void limpiar()
{
	system("cls");
}

void preguntar_por_enter()
{
	string a;
	cout << "Presione enter para continuar... " << endl;
	getline(cin, a);
	limpiar();
}

int main()
{
	bool salir = false;
	while (!salir)
	{
		string opcion;
		cout << "Opciones: " << endl;
		cout << "1. Alta de usuario" << endl;
		cout << "2. Iniciar sesion" << endl;
		cout << "3. Cargar datos de prueba" << endl;
		cout << "4. Salir" << endl;
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
						while (1)
						{
							cout << "Opciones del jugador:" << endl;
							cout << "1. Suscribirse a un videojuego" << endl;
							cout << "2. Asignar puntaje a videojuego" << endl;
							cout << "3. Iniciar partida" << endl;
							cout << "4. Abandona partida multijugador" << endl;
							cout << "5. Finalizar partida" << endl;
							cout << "6. Ver informacion de videojuego" << endl;
							cout << "7. Seguir jugador" << endl;
							cout << "8. Salir" << endl;
							cout << "Opcion: ";
							getline(cin, opcion);
							if (opcion == "1")
								suscribirse_a_un_videojuego();
							else if (opcion == "2")
								asigna_puntaje_a_videojuego();
//							else if (opcion == "3")
//								iniciar_partida();
							else if (opcion == "4")
								abandona_partida_multijugador();
							else if (opcion == "5")
								finalizar_partida();
							else if (opcion == "6")
								ver_informacion_de_videojuego();
							else if (opcion == "7")
								seguir_jugador();
							else
							{
								limpiar();
								break;
							}
						}
					}
					else
					{
						while (1)
						{
							cout << "Opciones del desarrollador:" << endl;
							cout << "1. Agregar categoria" << endl;
							cout << "2. Publicar videojuego" << endl;
							cout << "3. Eliminar videojuego" << endl;
							cout << "4. Ver informacion de videojuego" << endl;
							cout << "5. Salir" << endl;
							cout << "Opcion: ";
							getline(cin, opcion);
							if (opcion == "1")
								agregar_categoria();
							else if (opcion == "2")
								publicar_videojuego();
							else if (opcion == "3")
								eliminar_videojuego();
							else if (opcion == "4")
								ver_informacion_de_videojuego();
							else
							{
								limpiar();
								break;
							}
						}
					}
				}
			}
		}
		else if (opcion == "3")
			cargar_datos_de_prueba();
		else
			break;
	}

	delete Fabrica::get_instance();
	return 0;
}

void finalizar_partida()
{
	limpiar();
	IPartidas* matches = Fabrica::get_instance()->getIPartidas();
	ICollection* partidas = matches->obtenerPartidasNoFinalizadasAlInicio();
	cout << "Partidas no finalizadas:" << endl;
	if (partidas->isEmpty())
	{
		cout << "No hay" << endl;
		preguntar_por_enter();
		return;
	}
	for(IIterator* it = partidas->iterator(); it->hasNext(); it->next())
	{
		Partida* partida = dynamic_cast<Partida*>(it->getCurrent());
		DtDatosPartida datos_partida = matches->mostrarDatosPartida(partida);
		cout << "Identificador: " << datos_partida.Getidentificador() << endl;
		cout << "  Nombre de videojuego: " << datos_partida.Getnombre_videojuego() << endl;
		cout << "  Fecha en la que se creo: " << datos_partida.Getfecha_comienzo().as_string() << endl;
		Individual* individual = dynamic_cast<Individual*>(partida);
		if (individual != nullptr)
			cout << "  Es continuacion?: " << matches->mostrarSiEsContinuacion(partida) << endl;
		else
		{
			cout << "  Es transmitida en vivo?: " << matches->mostrarSiSeEstaTransmitiendoEnVivo(partida) << endl;
			cout << "  Nicknames de los participantes: " << endl;
			vector<string> nicknames = matches->mostrarNicknamesParticipantes(partida);
			if (nicknames.size() == 0)
				cout << "    No hay participantes" << endl;
			for (auto& nick : nicknames)
				cout << "    " << nick << endl;
		}
	}
	string identificador;
	cout << "Identificador de partida a finalizar: ";
	getline(cin, identificador);
	matches->confirmarPartidaQueDeseaFinalizar(stoi(identificador));
	limpiar();
}

void abandona_partida_multijugador()
{
	limpiar();
	IPartidas* matches = Fabrica::get_instance()->getIPartidas();
	ICollection* partidas = matches->listarPartidasNoFinalizadasMultijugador();
	cout << "Partidas no finalizadas multijugador: " << endl;
	if (partidas->isEmpty())
	{
		cout << "No hay" << endl;
		preguntar_por_enter();
		return;
	}
	for (IIterator* it = partidas->iterator(); it->hasNext(); it->next())
	{
		Partida* partida = dynamic_cast<Partida*>(it->getCurrent());
		DtDatosPartida datos_partida = matches->mostrarDatosPartida(partida);
		bool en_vivo = matches->mostrarSiSeEstaTransmitiendoEnVivo(partida);
		string nickname = matches->mostrarNicknameDelQueLaInicio(partida);
		vector<string> nicknames = matches->mostrarNicknamesParticipantes(partida);

		cout << "Identificador: " << datos_partida.Getidentificador() << endl;
		cout << "  Nombre de videojuego: " << datos_partida.Getnombre_videojuego() << endl;
		cout << "  Fecha en la que se creo: " << datos_partida.Getfecha_comienzo().as_string() << endl;
		cout << "  Es transmitida en vivo?: ";
		if (en_vivo)
			cout << "Si";
		else
			cout << "No";
		cout << endl;
		cout << "  Nickname del que la inicio: " << nickname << endl;
		cout << "  Nicknames de los participantes: " << endl;
		if (nicknames.size() == 0)
			cout << "    No hay participantes" << endl;
		for (auto& nick : nicknames)
			cout << "    " << nick << endl;
	}
	string identificador;
	cout << "Identificador de partida a abandonar: ";
	getline(cin, identificador);
	matches->confirmarPartidaQueDeseaAbandonar(stoi(identificador));
	limpiar();
}

void eliminar_videojuego()
{
	limpiar();
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	ICollection* no_finalizados = games->listarVideojuegosPublicadosNoFinalizados();
	cout << "Nombres de videojuegos publicados finalizados:" << endl;
	for (IIterator* it = no_finalizados->iterator(); it->hasNext(); it->next())
	{
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		cout << videojuego->Getnombre() << endl;
	}
	if (no_finalizados->isEmpty())
	{
		cout << "No hay" << endl;
		preguntar_por_enter();
		return;
	}
	string nombre;
	cout << "Nombre de videojuego a eliminar: ";
	getline(cin, nombre);
	games->seleccionarVideojuego(nombre);
	cout << "Confirmar eliminacion? (s/n): ";
	string confirmar;
	getline(cin, confirmar);
	if (confirmar == "s")
		games->eliminarVideojuego();
	else
		games->cancelarEliminacionDeVideojuego();
	limpiar();
}

void asigna_puntaje_a_videojuego()
{
	limpiar();
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	cout << "Videojuegos: " << endl;
	ICollection* videojuegos = games->listarVideojuegos();
	if (videojuegos->isEmpty())
	{
		cout << "No hay" << endl;
		preguntar_por_enter();
		return;
	}
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		cout << "Nombre: " << videojuego->Getnombre() << endl;
		cout << "Descripcion: " << videojuego->Getdescripcion() << endl;
	}

	IUsers* users = Fabrica::get_instance()->getIUsers();
	int puntaje = 0;
	string nombre, pun;
	cout << "Nombre del videojuego: ";
	getline(cin, nombre);
	cout << "Puntaje a asignar(del 1 al 5): ";
	getline(cin, pun);
	if (pun == "1") puntaje = 1;
	else if (pun == "2") puntaje = 2;
	else if (pun == "3") puntaje = 3;
	else if (pun == "4") puntaje = 4;
	else if (pun == "5") puntaje = 5;
	else
	{
		cout << "Ese puntaje no existe" << endl;
		preguntar_por_enter();
		return;
	}
	users->asignarPuntaje(nombre, puntaje);
	limpiar();
}

void ver_informacion_de_videojuego()
{
	limpiar();
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	IUsers* users = Fabrica::get_instance()->getIUsers();

	cout << "Videojuegos: " << endl;
	ICollection* videojuegos = games->listarVideojuegos();
	if (videojuegos->isEmpty())
	{
		cout << "No hay" << endl;
		preguntar_por_enter();
		return;
	}
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		cout << videojuego->Getnombre() << endl;
	}
	string nombre;
	cout << "Nombre del videojuego: ";
	getline(cin, nombre);
	games->seleccionarVideojuego(nombre);
	games->muestraDatosVideojuego();
	if (dynamic_cast<Desarrollador*>(users->get_usuario_seleccionado()) != nullptr)
		games->muestraTotalHorasVideojuego();
	preguntar_por_enter();
}

void agregar_categoria()
{
	limpiar();
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
	limpiar();
}

void suscribirse_a_un_videojuego()
{
	limpiar();
	IUsers* users = Fabrica::get_instance()->getIUsers();
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();

	ICollection* videojuegos = games->listarVideojuegos();
	if (videojuegos->isEmpty())
	{
		cout << "No hay videojuegos a los que suscribirse." << endl;
		preguntar_por_enter();
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
				Temporal* temporal = dynamic_cast<Temporal*>(suscripcion);
				if (temporal && !temporal->Getestado())
					break;
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
				Temporal* temporal = dynamic_cast<Temporal*>(suscripcion);
				if (temporal && !temporal->Getestado())
					break;
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
	for (IIterator* it = videojuegos->iterator(); it->hasNext(); it->next())
	{
		Videojuego* videojuego = dynamic_cast<Videojuego*>(it->getCurrent());
		if (videojuego->Getnombre() == nombre)
		{
			Jugador* jugador = dynamic_cast<Jugador*>(users->get_usuario_seleccionado());
			for (IIterator* jt = jugador->Getsuscripciones()->iterator(); jt->hasNext(); jt->next())
			{
				Suscripcion* suscripcion = dynamic_cast<Suscripcion*>(jt->getCurrent());
				if (videojuego == suscripcion->Getvideojuego())
				{
					Temporal* temporal = dynamic_cast<Temporal*>(suscripcion);
					if (temporal && !temporal->Getestado())
						break;
					Vitalicia* vitalicia = dynamic_cast<Vitalicia*>(suscripcion);
					if (vitalicia)
					{
						cout << "Ya esta suscrito a dicho videojuego y la suscripcion es vitalicia" << endl;
						users->finalizarsuscripcion();
						preguntar_por_enter();
						return;
					}
					else
					{
						string cancelar;
						cout << "Ya esta suscrito a dicho videojuego, la suscripcion es temporal" << endl;
						cout << "Desea cancelarla? (s/n): ";
						getline(cin, cancelar);
						if (cancelar == "s")
							users->cancelarSuscripcionAnterior();
						else
						{
							users->finalizarsuscripcion();
							preguntar_por_enter();
							return;
						}
					}
					break;
				}
			}
		}
	}

	EnumMetodoPago metodo_de_pago;
	while(1)
	{
		string metodo;
		cout << "Metodos de pago: " << endl;
		cout << "  1. PayPal" << endl;
		cout << "  2. Tarjeta" << endl;
		cout << "Eliga metodo: ";
		getline(cin, metodo);
		if (metodo == "1")
		{
			metodo_de_pago = EnumMetodoPago::PayPal;
			break;
		}
		else if (metodo == "2")
		{
			metodo_de_pago = EnumMetodoPago::Tarjeta;
			break;
		}
		else
		{
			limpiar();
			continue;
		}
	}
	EnumTipoSuscripcion tipo_suscripcion;
	while(1)
	{
		string tipo;
		cout << "Tipos de suscripcion: " << endl;
		cout << "  1. Vitalicia" << endl;
		cout << "  2. Mensual" << endl;
		cout << "  3. Trimestral" << endl;
		cout << "  4. Anual" << endl;
		cout << "Eliga tipo: ";
		getline(cin, tipo);
		if (tipo == "1")
		{
			tipo_suscripcion = EnumTipoSuscripcion::Vitalicia;
			break;
		}
		else if (tipo == "2")
		{
			tipo_suscripcion = EnumTipoSuscripcion::Mensual;
			break;
		}
		else if (tipo == "3")
		{
			tipo_suscripcion = EnumTipoSuscripcion::Trimestral;
			break;
		}
		else if (tipo == "4")
		{
			tipo_suscripcion = EnumTipoSuscripcion::Anual;
			break;
		}
		else
		{
			limpiar();
			continue;
		}
	}
	users->ingresarDatosSuscripcion(metodo_de_pago, tipo_suscripcion);

	string confirmar;
	cout << "Desea confirmar alta de suscripcion? (s/n): ";
	getline(cin, confirmar);
	if (confirmar == "s")
		users->darDeAltaSuscripcion();
	else
		users->cancelarSuscripcionAVideojuego();
	limpiar();
}

void publicar_videojuego()
{
	limpiar();
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
					preguntar_por_enter();
					continue;
				}
				cantidad = 0;
				limpiar();
				break;
			}
			else if (static_cast<size_t>(stoi(id)) > i || static_cast<size_t>(stoi(id)) < 1)
			{
				cout << "Esa opcion no esta en el rango de categorias que se listaron" << endl;
				preguntar_por_enter();
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
			limpiar();
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
	limpiar();
}

void seguir_jugador()
{
	limpiar();
	IUsers* users = Fabrica::get_instance()->getIUsers();
	if (users->get_usuario_seleccionado() == nullptr)
	{
		cout << "Ningun usuario ha iniciado sesion" << endl;
		preguntar_por_enter();
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
		preguntar_por_enter();
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
			cout << "Ninguno." << endl;
			preguntar_por_enter();
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
			{
				limpiar();
				continue;
			}
		}
		users->seleccionarJugador(nickname_a_seguir);
		break;
	}
	limpiar();
}

ICollectible* get_cat(string cat)
{
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	ICollection* categorias = nullptr;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			categorias = games->listarCategoriaGeneros();
		else if (i == 1)
			categorias = games->listarCategoriaPlataforma();
		else
			categorias = games->listarRestoCategorias();
		for (IIterator* it = categorias->iterator(); it->hasNext(); it->next())
		{
			CategoriaDeVideojuegos* categoria = dynamic_cast<CategoriaDeVideojuegos*>(it->getCurrent());
			if (categoria->Getnombre() == cat)
				return it->getCurrent();
		}
	}
	cout << "esto no deberia pasar" << endl;
	return nullptr;
}

void cargar_datos_de_prueba()
{
	IUsers* users = Fabrica::get_instance()->getIUsers();
	IVideojuegos* games = Fabrica::get_instance()->getIVideojuegos();
	// alta de desarrolladores
	users->ingresarDatosUsuario("ironhide@mail.com", "123"); // D1
	users->ingresarempresa("Ironhide Game Studio");
	users->altaUsuario();
	users->ingresarDatosUsuario("epic@mail.com", "123"); // D2
	users->ingresarempresa("Epic Games");
	users->altaUsuario();
	users->ingresarDatosUsuario("mojang@mail.com", "123"); // D3
	users->ingresarempresa("Mojang Studios");
	users->altaUsuario();
	users->ingresarDatosUsuario("ea@mail.com", "123"); // D4
	users->ingresarempresa("EA Sports");
	users->altaUsuario();
	// alta de jugadores
	users->ingresarDatosUsuario("gamer@mail.com", "123"); // J1
	users->ingresardatos("gamer", "");
	users->altaUsuario();
	users->ingresarDatosUsuario("ari@mail.com", "123"); // J2
	users->ingresardatos("ari", "");
	users->altaUsuario();
	users->ingresarDatosUsuario("ibai@mail.com", "123"); // J3
	users->ingresardatos("ibai", "");
	users->altaUsuario();
	users->ingresarDatosUsuario("camila@mail.com", "123"); // J4
	users->ingresardatos("camila", "");
	users->altaUsuario();

	// agregando categorias
	games->agregarNuevaCategoria("PC", "Computadora personal", TipoCategoria::Plataforma);
	games->darDeAltaNuevaCategoria(); // C1
	games->agregarNuevaCategoria("PS4", "Play Station 4", TipoCategoria::Plataforma);
	games->darDeAltaNuevaCategoria(); // C2
	games->agregarNuevaCategoria("Xbox One", "", TipoCategoria::Plataforma);
	games->darDeAltaNuevaCategoria(); // C3
	games->agregarNuevaCategoria("Deporte", "Juegos de deporte", TipoCategoria::Genero);
	games->darDeAltaNuevaCategoria(); // C4
	games->agregarNuevaCategoria("Supervivencia", "Juegos de supervivencia", TipoCategoria::Genero);
	games->darDeAltaNuevaCategoria(); // C5
	games->agregarNuevaCategoria("Estrategia", "Juegos de estrategia", TipoCategoria::Genero);
	games->darDeAltaNuevaCategoria(); // C6
	games->agregarNuevaCategoria("Teen", "Su contenido está dirigido a jóvenes de 13 años en adelante", TipoCategoria::Otro);
	games->darDeAltaNuevaCategoria(); // C7
	games->agregarNuevaCategoria("E", "Su contenido está dirigido para todo público", TipoCategoria::Otro);
	games->darDeAltaNuevaCategoria(); // C8
	games->agregarNuevaCategoria("Accion", "Juegos de accion", TipoCategoria::Genero);
	games->darDeAltaNuevaCategoria(); // C9
	games->agregarNuevaCategoria("Aventura", "Juegos de aventura", TipoCategoria::Genero);
	games->darDeAltaNuevaCategoria(); // C10
	games->agregarNuevaCategoria("Switch", "Nintendo Switch", TipoCategoria::Plataforma);
	games->darDeAltaNuevaCategoria(); // C11
	games->agregarNuevaCategoria("Xbox X", "", TipoCategoria::Plataforma);
	games->darDeAltaNuevaCategoria(); // C12
	games->agregarNuevaCategoria("PS5", "Play Station 5", TipoCategoria::Plataforma);
	games->darDeAltaNuevaCategoria(); // C13

	// agregando videojuegos
	users->iniciarSesion("ironhide@mail.com", "123"); // D1
	DtCostoSuscripcion costo_suscripcion;
	costo_suscripcion.Setcosto_mensual(1);
	costo_suscripcion.Setcosto_trimestral(2);
	costo_suscripcion.Setcosto_anual(7);
	costo_suscripcion.Setcosto_vitalicia(14);
	games->agregarVideojuego("KingdomRush", "", dynamic_cast<Desarrollador*>(users->get_usuario_seleccionado())->Getempresa_donde_trabaja(), costo_suscripcion);
	games->agregarCategoriaPlataforma(get_cat("PC"));
	games->agregarCategoriaPlataforma(get_cat("PS4"));
	games->agregarCategoriaGenero(get_cat("Estrategia"));
	games->agregarCategoria(get_cat("E"));
	games->darDeAltaVideojuego(); // V1

	users->iniciarSesion("epic@mail.com", "123"); // D2
	costo_suscripcion.Setcosto_mensual(3);
	costo_suscripcion.Setcosto_trimestral(8);
	costo_suscripcion.Setcosto_anual(30);
	costo_suscripcion.Setcosto_vitalicia(60);
	games->agregarVideojuego("Fortnite", "", dynamic_cast<Desarrollador*>(users->get_usuario_seleccionado())->Getempresa_donde_trabaja(), costo_suscripcion);
	games->agregarCategoriaPlataforma(get_cat("PC"));
	games->agregarCategoriaPlataforma(get_cat("PS4"));
	games->agregarCategoriaPlataforma(get_cat("Xbox One"));
	games->agregarCategoriaGenero(get_cat("Supervivencia"));
	games->agregarCategoria(get_cat("Teen"));
	games->darDeAltaVideojuego(); // V2

	users->iniciarSesion("mojang@mail.com", "123"); // D3
	costo_suscripcion.Setcosto_mensual(2);
	costo_suscripcion.Setcosto_trimestral(5);
	costo_suscripcion.Setcosto_anual(20);
	costo_suscripcion.Setcosto_vitalicia(40);
	games->agregarVideojuego("Minecraft", "", dynamic_cast<Desarrollador*>(users->get_usuario_seleccionado())->Getempresa_donde_trabaja(), costo_suscripcion);
	games->agregarCategoriaPlataforma(get_cat("PC"));
	games->agregarCategoriaGenero(get_cat("Supervivencia"));
	games->agregarCategoria(get_cat("E"));
	games->darDeAltaVideojuego(); // V3

	users->iniciarSesion("ea@mail.com", "123"); // D4
	costo_suscripcion.Setcosto_mensual(3);
	costo_suscripcion.Setcosto_trimestral(8);
	costo_suscripcion.Setcosto_anual(28);
	costo_suscripcion.Setcosto_vitalicia(50);
	games->agregarVideojuego("FIFA 21", "", dynamic_cast<Desarrollador*>(users->get_usuario_seleccionado())->Getempresa_donde_trabaja(), costo_suscripcion);
	games->agregarCategoriaPlataforma(get_cat("PC"));
	games->agregarCategoriaPlataforma(get_cat("PS4"));
	games->agregarCategoriaPlataforma(get_cat("Xbox One"));
	games->agregarCategoriaGenero(get_cat("Deporte"));
	games->agregarCategoria(get_cat("E"));
	games->darDeAltaVideojuego(); // V4

	// suscripciones a videojuegos
	users->iniciarSesion("gamer@mail.com", "123");
	users->ingresarNombreVideojuegoParaSuscripcion("KingdomRush");
	users->ingresarDatosSuscripcion(EnumMetodoPago::PayPal, EnumTipoSuscripcion::Trimestral);
	users->darDeAltaSuscripcion(DtFechaHora(1, 6, 2021, 9, 0, 0));

	users->ingresarNombreVideojuegoParaSuscripcion("Fortnite");
	users->ingresarDatosSuscripcion(EnumMetodoPago::Tarjeta, EnumTipoSuscripcion::Trimestral);
	users->darDeAltaSuscripcion(DtFechaHora(2, 6, 2021, 11, 0, 0));

	users->iniciarSesion("ari@mail.com", "123");
	users->ingresarNombreVideojuegoParaSuscripcion("Fortnite");
	users->ingresarDatosSuscripcion(EnumMetodoPago::PayPal, EnumTipoSuscripcion::Mensual);
	users->darDeAltaSuscripcion(DtFechaHora(4, 6, 2021, 9, 0, 0));

	users->ingresarNombreVideojuegoParaSuscripcion("Minecraft");
	users->ingresarDatosSuscripcion(EnumMetodoPago::Tarjeta, EnumTipoSuscripcion::Anual);
	users->darDeAltaSuscripcion(DtFechaHora(11, 6, 2021, 9, 0, 0));

	users->iniciarSesion("ibai@mail.com", "123");
	users->ingresarNombreVideojuegoParaSuscripcion("Fortnite");
	users->ingresarDatosSuscripcion(EnumMetodoPago::Tarjeta, EnumTipoSuscripcion::Mensual);
	users->darDeAltaSuscripcion(DtFechaHora(3, 6, 2021, 7, 0, 0));

	users->ingresarNombreVideojuegoParaSuscripcion("Minecraft");
	users->ingresarDatosSuscripcion(EnumMetodoPago::Tarjeta, EnumTipoSuscripcion::Vitalicia);
	users->darDeAltaSuscripcion(DtFechaHora(21, 12, 2020, 15, 0, 0));

	// puntajes a videojuegos
	users->iniciarSesion("gamer@mail.com", "123");
	users->asignarPuntaje("KingdomRush", 4);
	users->asignarPuntaje("Fortnite", 5);
	users->iniciarSesion("ari@mail.com", "123");
	users->asignarPuntaje("Fortnite", 5);
	users->asignarPuntaje("Minecraft", 3);

	// partidas individuales
	// partidas multijugador
	// abandona partida multijugador

	limpiar();
}

bool iniciar_sesion()
{
	limpiar();
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
			preguntar_por_enter();
			return true;
		}
		else
		{
			string nuevamente;
			cout << "contrasenia o usuario incorrectos." << endl;
			cout << "desea intentarlo de nuevo? (s/n): ";
			getline(cin, nuevamente);
			if (nuevamente != "s")
			{
				limpiar();
				return false;
			}
		}
	}
	limpiar();
	return false;
}

void alta_de_usuario()
{
	limpiar();
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
