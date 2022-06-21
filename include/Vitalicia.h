#ifndef VITALICIA_H
#define VITALICIA_H

#include <Suscripcion.h>


class Vitalicia : public Suscripcion
{
    public:
        Vitalicia();
        virtual ~Vitalicia();

        float Getcosto() { return costo; }
        void Setcosto(float val) { costo = val; }

    protected:

    private:
        float costo;
};

#endif // VITALICIA_H
