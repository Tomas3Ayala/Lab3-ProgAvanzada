#ifndef DTPARTIDAINFO_H
#define DTPARTIDAINFO_H
#include "StandardHeaders.h"

class DtPartidaInfo : ICollectible
{
	public:
		DtPartidaInfo();
		~DtPartidaInfo();

		int Getidentificador() { return identificador; }
		void Setidentificador(int val) { identificador = val; }
		string Getnombre_videojuego() { return nombre_videojuego; }
		void Setnombre_videojuego(string val) { nombre_videojuego = val; }
		string Getnickname_inicio() { return nickname_inicio; }
		void Setnickname_inicio(string val) { nickname_inicio = val; }
		vector<string> Getnicknames_participan() { return nicknames_participan; }
		void Setnicknames_participan(vector<string> val) { nicknames_participan = val; }

	protected:

	private:
		int identificador;
		string nombre_videojuego;
		string nickname_inicio;
		vector<string> nicknames_participan;
};

#endif // DTPARTIDAINFO_H
