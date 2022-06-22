#ifndef IVIDEOJUEGOS_H
#define IVIDEOJUEGOS_H


class IVideojuegos
{
	public:
		virtual ~IVideojuegos();
		virtual void asignarPuntajeAVideojuego()=0;
		virtual void verInformacionDeVideojuego()=0;
		virtual void eliminarVideojuego()=0;
		virtual void publicarVideojuego()=0;
		virtual ICollection* listarVideojuegos()=0;
		virtual ICollection* listarCategoriaGeneros()=0;
		virtual ICollection* listarCategoriaPlataformas()=0;
		virtual ICollection* listarRestoCategorias()=0;

	private:
};

#endif // IVIDEOJUEGOS_H
