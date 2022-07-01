#include<iostream>
#include "Fabrica.h"
#include "IUsers.h"
#include "IVideojuegos.h"
#include "IPartidas.h"
#include "UsersControllers.h"
#include<string>
#include<cmath>
#include<vector>
using namespace std;

int main (int argc, char *argv[]) {
	int opcion;
	char tecla, seguir;
	//////////////////
	int opcionUsuario, puntaje;
	char alta, cancsuscripcion, confsuscripcion, multint,confpartida, mascategorias, masplataforma, otracategoria, confalta, SoN ;
	Fabrica* fabrica;
	int identificador;
	float CantLitros;
	float Precio;
	bool es_transmitida_en_vivo;
	string email;
	string contrasenia;
	string nombreEmpresa;
	string nombreCategoria;
	string nickname;
	string descripcion;
	string nombrevideojuego;
	string descripvideojuego;
	string texto;
	///////////////DT
	EnumMetodoPago metodopago;


	do {
		system("cls");
		cout << "INICIO" << endl;
		cout << "-----------" << endl << endl;
		cout << "\t1 .- Alta de Uusuario" << endl;
		cout << "\t2 .-  Iniciar Sesion" << endl;
		cout << "\t3 .- Suscribirse a videojuego" << endl;
		cout << "\t4 .- Asignar puntaje a videojuego" << endl;
		cout << "\t5 .- Iniciar Partida" << endl;
		cout << "\t6 .- Finalizar Partida" << endl;
		cout << "\t7.- Publicar videojuego" << endl << endl;
		cout << "\t8.- Eliminar videojuego" << endl << endl;
		cout << "\t9.- Ver informacion de videojuego" << endl << endl;
		cout << "\t10.- Seguir Jugador" << endl << endl;
		cout << "\t11.- Realizar Comentario" << endl << endl;
		cout << "\t12.- Abandonar partida" << endl << endl;
		cout << "\t13.- Agregar categoria" << endl << endl;
		cout << "\t14.- Salir" << endl << endl;
		cout << "Elije una opcion: ";

		cin >> tecla;

		switch(tecla)
		{
		case '1':
			system ("cls");
			cout<<"Agregar un nuevo usuario al Sistema";cout<<endl;
			cout<<"Ingrese email:";cout<<endl;
			cin>>email;
			cout<<"ingrese contrasenia:";cout<<endl;
			cin>>contrasenia;
			//ingresarDatosUsuario(string email, string contrasenia);
			do {
		system("cls");
		cout << "El usuario a registrarse será un jugador o desarrollador: Elija un numero segun su opcion" << endl;
		cout << "-----------" << endl << endl;
		cout << "\t1 .-Digite 1 si es Desarrollador" << endl;
		cout << "\t2 .-Digite 2 si es Jugador" << endl;
		cin>>opcionUsuario;
			switch(opcionUsuario)
			{
            case '1':
                system ("cls");
                    cout<<"Opcion desarrollador";cout<<endl;
                    cout<<"ingrese nombre de la empresa para la cual trabaja";cout<<endl;
                    getline(cin, nombreEmpresa);
            //ingresarempresa(string nomempresa);

                break;
            case '2';
                system ("cls");
                    cout<<"Opcion Jugador";cout<<endl;
                    do
                    {
                    cout<<"ingrese Nick name";cout<<endl;
                    cin>>nickname;
                    }
                    while (mientra no exista ese nick name registrado);

            //ingresardatos(string nickname, string descripcion);

                break;

            default:
			system("cls");
			cout << "Opcion no valida.\a\n";
			break;

			}
			while(opcionUsuario < 3);
			return 0;

            }
            cout<<"Desea dar de alta al USUARIO? S/N";<<cout<<endl;
                    cin>>alta;
                    if (alta == "s" || alta == "S")
                    {
            // altaUsuario()
                    }
                    else {
            //cancelarAltaDeUsuario()
                        break;
                    }
			break;

		case '2':
			system ("cls");
			cout<<"Iniciar Sesion";cout<<endl;
			do
			{
			    cout<<"Ingrese email:";cout<<endl;
                cin>>email;
                cout<<"ingrese contrasenia:";cout<<endl;
                cin>>contrasenia;
           //iniciarSesion(string email, string contrasenia);
			} while (!iniciarSesion(string email, string contrasenia));


			break;

		case '3':
			system ("cls");
			cout<<"Suscribirse a videojuego";cout<<endl;
        //El sistema debe recordar jugador que inicio sesion
        //listarVideojuegos();
            do
            {
                //listarSuscripciones(ICollectible* videojuego);
            }while (tenga suscripciones);
            cout<<"Ingrese nombre de videojuego al que desea suscribirse";cout<<endl;
            getline (cin, nombrevideojuego);
            //ingresarNombreVideojuegoParaSuscripcion(string nombre);
            if (si tine suscripcion)
            {
                if(suscripcion es vitalicia)
                {
                    //finalizarsuscripcion();
                }
                else if (si es temporal)
                {
                   cout<<"Desea cancelar la suscripcion anterior? S/N";cout<<endl;
                   cin>>cancsuscripcion;
                 else  if(cancsuscripcion == "N" || cancsuscripcion == "n")
                   {
                       //finalizarsuscripcion();
                   }
                 else  if(cancsuscripcion == "S" || cancsuscripcion == "s" )
                   {
                      //cancelarSuscripcionAnterior();

                   }
                }
            }
            cout<<"Ingrese medodo de pago";cout<<endl;
            cout<<"Ingrese Tipo de suscripcion";cout<<endl;
           // ingresarDatosSuscripcion(EnumMetodoPago metodo_pago, EnumTipoSuscripcion tipo);
           cout<<"Desea confirmar suscripcion? S/N";cout<<endl;
           cin>>confsuscripcion;
           if (confsuscripcion == "S" || confsuscripcion == "s")
           {
               //darDeAltaSuscripcion();
           }
            else if(cancsuscripcion == "N" || cancsuscripcion == "n")
                   {
                       //cancelarSuscripcionAVideojuego();
                   }
           else

			break;
		case '4':
			system ("cls");
			cout<<"Asignar puntaje a videojuego";cout<<endl;
			cout<<"LISTA DE VIDEOJUEGOS PARA ASIGNAR PUNTAJE"<<;cout<<endl;
			 //listarVideojuegos();
			 cout<<"Ingrese nombre videojuego a puntuar";cout<<endl;
			 cin>>nombrevideojuego;
             cout<<"Ingrese puntaje";cout<<endl;
			 cin>>puntaje;
			 if (existe videojuego)
             {
                //asignarPuntaje(string nombre, int puntaje);
             }
            else

			break;

		case '5':
			system ("cls");
			cout<<"Iniciar Partida";cout<<endl;
			//listarVideojuegosSuscritos();
			//seleccionarVideojuego(ICollectible* videojuego);
			cout<<"La partida sera multijugador o individual?";cout<<endl;
			if (es individual)
            {
                if (es continuacion)
                {
                    //listarPartidasEnOrden();
                    //seleccionarPartida(int identificador);
                }

            }
            else if (es multijugador)
            {
                cout<<"SERA TRANSMITIDA EN VIVO? 1/0";cout<<endl;
                cin>>es_transmitida_en_vivo;
                esTransmitidaEnVivo(bool es_transmitida_en_vivo);
                listarDemasJugadoresConSuscripcionActiva();
                do
                {
                  agregarParticipante(string nickname);
                }while (mientras desee agregar participantes);

            }
            cout<<"Desea confirmar parttida? S/N";cout<<endl;
           cin>>confpartida;
           if (confsuscripcion == "S" || confsuscripcion == "s")
           {
               //darDeAltaNuevaPartida();
           }
            else
			break;

		case '6':
			system ("cls");
			cout<<"Finalizar Partida";cout<<endl;
			/*obtenerPartidasNoFinalizadasAlInicio();
			DtDatosPartida mostrarDatosPartida(ICollectible* partida);
			mostrarSiEsContinuacion(ICollectible* partida);
			mostrarSiSeEstaTransmitiendoEnVivo(ICollectible* partida);
			mostrarNicknamesParticipantes(ICollectible* partida);*/
			cout<<"Ingrese el identificador de la partida que desea finalizar";cout<<endl;
			cin>>identificador;
           // confirmarPartidaQueDeseaFinalizar(int identificador);
			break;
        case '7':
			system ("cls");
			cout<<"Publicar videojuego";cout<<endl;
			cout<<"Ingrese nombre de videoguego";cout<<endl;
			getline (cin, nombrevideojuego);
			cout<<"Ingrese descripcion de videoguego";cout<<endl;
			getline (cin, descripvideojuego);
			cout<<"Ingrese costo mensual";cout<<endl;
			cout<<"Ingrese costo trimestral";cout<<endl;
			cout<<"Ingrese costo anual";cout<<endl;
			cout<<"Ingrese costo vitalicia";cout<<endl;
			//agregarVideojuego(string nombrevideojuego, string descripvideojuego, DtCostoSuscripcion costo);
			cout<<"Selecciones categoria de genero";cout<<endl;
			//listarCategoriaGeneros();
			do
            {
                //listarCategoriaGeneros();
                //agregarCategoriaGenero(ICollectible* genero);
                cout<<"seguir seleccionando categoria de genero? S/N";cout<<endl;
                cin>>mascategorias;
            }while (mascategorias == "S" || mascategorias != "s");

            cout<<"Selecciones categoria de plataforma";cout<<endl;
            //listarCategoriaPlataforma();
			do
            {
                //listarCategoriaPlataforma();
                //agregarCategoriaPlataforma(ICollectible* plataforma);
                cout<<"seguir seleccionando categoria de plataforma? S/N";cout<<endl;
                cin>>masplataforma;
            }while (masplataforma == "S" ||masplataforma == "s");
             cout<<"Seleccionar otra categoria? S/N";cout<<endl;
             cin>>otracategoria;
             do
             {
               // listarRestoCategorias();
              // agregarCategoria(ICollectible* categoria);
               cout<<"seguir seleccionando otra categoria? S/N";cout<<endl;
               cin>>otracategoria;
             }while (otracategoria == "S" ||otracategoria == "s");
            // mostrarInformacionIngresadaDelVideojuego();
             cout<<"Desea confirmar Alta videojuego? S/N";cout<<endl;
             cin>>confalta;
             if (confalta == "S" || confalta == "s")
             {
               //darDeAltaVideojuego();
             }
              else
              {
                cancelarCreacionDeVideojuego();
              }

			break;
        case '8':
			system ("cls");
			cout<<"Eliminar videojuego";cout<<endl;
			//listarVideojuegosPublicadosNoFinalizados();
			//seleccionarVideojuego(string nombre);
			cout<<"Ingres nombre videojuego a eliminar";cout<<endl;
			cin>>nombrevideojuego;
			 cout<<"Desea confirmar Eliminacion videojuego? S/N";cout<<endl;
             cin>>SoN;
             if (SoN == "S" || SoN == "s")
             {
               //eliminarVideojuego();
             }
              else
              {
                cancelarCreacionDeVideojuego();
              }

			break;
        case '9':
			system ("cls");
			cout<<"Ver informacion de videojuego";cout<<endl;
			//listarVideojuegos();
			cout<<"Ingrese nombre de videojuego";cout<<endl;
             cin>>nombrevideojuego;
			//seleccionarVideojuego(string nombrevideojuego);
			//muestraDatosVideojuego();
			if(usuario esdesarrollador)
            {
              muestraTotalHorasVideojuego();
            }
			break;

        case '10':
			system ("cls");
			cout<<"Seguir Jugador";cout<<endl;
			//listarNicknamesYDescripciones();
			cout<<"Nickname de jugador a seguir";cout<<endl;
			cin>>nickname;
			//seleccionarJugador(string nickname);
			break;

        case '11':
			system ("cls");
			cout<<"Realizar Comentario";cout<<endl;
			//obtenerPartidas(); DtPartidaInfo
			cout<<"Ingrese id partida  a comentar";cout<<endl;
			cin>>identificador;
			//seleccionarPartida(int identificador);
			cout<<"Desea responder comentario? S/N";cout<<endl;
			cin>>SoN;
			if (SoN == "S" || SoN == "s")
            {
              //listarComentarios(); // DtComentarioRealizado
            cout<<"Ingrese id partida  a comentar";cout<<endl;
			cin>>identificador;
			//seleccionComentario(int identificador);
            }
            cout<<"Escriba texto comentario;cout<<endl;
            getline(cin, texto);
            //agregarTextoMensaje(string texto);
             cout<<"Desea confirmar comentario";cout<<endl;
             cin>>SoN;
             if (SoN == "S" || SoN == "s")
             {
               //darDeAltaComentario(DtFechaHora fecha_hora);
             }
              else
              {
               // cancelarRealizarComentario();
              }

			break;

        case '12':
			system ("cls");
			cout<<"Abandonar partida";cout<<endl;
			//listarPartidasNoFinalizadasMultijugador(); // partidas
			do
            {
                //mostrarDatosPartida(ICollectible* partida);
                //mostrarSiSeEstaTransmitiendoEnVivo(ICollectible* partida);
               //mostrarNicknameDelQueLaInicio(ICollectible* partida);
                //mostrarNicknamesParticipantes(ICollectible* partida);
            }while(mientras halla partidas no finalizadas);
            cout<<"Ingrese identificador de partida a abandonar";cout<<endl;
            cin>>identificador;
            if(existe identificador)
            {
                //confirmarPartidaQueDeseaAbandonar(int identificador);
            }
            else

			break;
        case '13':
			system ("cls");
			cout<<"Agregar categoria";cout<<endl;
			// listarNombresCategorias();
			cout<<"Ingrese Nombre categoria";cout<<endl;
			cin>>nombreCategoria
			do
            {
            cout<<"Ingrese otro Nombre categoria";cout<<endl;
			cin>>nombreCategoria
            }while (mientras exista categoria);

			cout<<"Ingrese Nombre categoria";cout<<endl;
			cin>>nombreCategoria
            cout<<"Ingrese Descripcion de categoria";cout<<endl;
			getline(cin, descripcion);
			//seleccionar tipo categoria
			//agregarCategoria(string nombre, string descripcion, TipoCategoria tipo_categoria);
			 cout<<"Desea confirmar nueva categoria? S/N";cout<<endl;
             cin>>SoN;
             if (SoN == "S" || SoN == "s")
             {
               falta dar de alta nueva categoria
             }
              else
              {
                break;
              }

			break;

		case '14':
			if (opcion=14){
				exit;
			}
			break;

		default:
			system("cls");
			cout << "Opcion no valida.\a\n";

			break;
		}
	}while(opcion != 9);


	return 0;

}
