#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <memory>
#include <vector>
#include "Cotizacion.h"

class Vendedor
{
public:
    Vendedor(const std::string &nombre, const std::string &apellido, int codigo)
        : nombre_(nombre), apellido_(apellido), codigo_(codigo)
    {
    }
    virtual ~Vendedor() = default;

    void agregarCotizacion(std::shared_ptr<Cotizacion> cotizacion);
    const std::vector<std::shared_ptr<Cotizacion>> &obtenerCotizaciones() const
    {
        return cotizaciones_;
    }

private:
    std::string nombre_;
    std::string apellido_;
    int codigo_;
    std::vector<std::shared_ptr<Cotizacion>> cotizaciones_;
};

#endif // VENDEDOR_H
