#ifndef USUARIO_H
#define USUARIO_H


class Usuario
{
    public:
        Usuario();
        virtual ~Usuario();

        string Getemail() { return email; }
        void Setemail(string val) { email = val; }
        string Getcontrasenia() { return contrasenia; }
        void Setcontrasenia(string val) { contrasenia = val; }

    protected:

    private:
        string email;
        string contrasenia;
};

#endif // USUARIO_H
