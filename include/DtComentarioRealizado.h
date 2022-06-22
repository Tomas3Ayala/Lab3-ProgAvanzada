#ifndef DTCOMENTARIOREALIZADO_H
#define DTCOMENTARIOREALIZADO_H


class DtComentarioRealizado
{
	public:
		DtComentarioRealizado();

		int Getidentificador() { return identificador; }
		void Setidentificador(int val) { identificador = val; }
		DtFechaHora Getfecha_hora_envio() { return fecha_hora_envio; }
		void Setfecha_hora_envio(DtFechaHora val) { fecha_hora_envio = val; }
		string Getnickname_jugador() { return nickname_jugador; }
		void Setnickname_jugador(string val) { nickname_jugador = val; }
		string Gettexto() { return texto; }
		void Settexto(string val) { texto = val; }

	protected:

	private:
		int identificador;
		DtFechaHora fecha_hora_envio;
		string nickname_jugador;
		string texto;
};

#endif // DTCOMENTARIOREALIZADO_H
