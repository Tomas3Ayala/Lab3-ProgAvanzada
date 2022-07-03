#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "StandardHeaders.h"

class Comentario : ICollectible
{
	public:
		Comentario();

		int GetidComentario() { return idComentario; }
		void SetidComentario(int val) { idComentario = val; }
		string GetnickNameJugador() { return nickNameJugador; }
		void SetnickNameJugador(string val) { nickNameJugador = val; }
		string Gettexto() { return texto; }
		void Settexto(string val) { texto = val; }
		int GetidComentarioResponde() { return idComentarioResponde; }
		void SetidComentarioResponde(int val) { idComentarioResponde = val; }

	private:
		int idComentario;
		string nickNameJugador;
		string texto;
		int idComentarioResponde;
};

#endif // COMENTARIO_H
