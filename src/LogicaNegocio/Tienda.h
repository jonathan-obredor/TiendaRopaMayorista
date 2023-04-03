#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>
#include "Prenda.h"

class Tienda
{
public:
    Tienda(const std::string &nombre, const std::string &direccion)
        : nombre(nombre), direccion(direccion) {}
    virtual ~Tienda() = default;

    void agregarPrenda(const Prenda &prenda);
    std::vector<Prenda> &getPrendas()
    {
        return prendas;
    }

    const std::string &getNombre() const
    {
        return nombre;
    }

    const std::string &getDireccion() const
    {
        return direccion;
    }

private:
    std::string nombre;
    std::string direccion;
    std::vector<Prenda> prendas;
};

#endif // TIENDA_H
