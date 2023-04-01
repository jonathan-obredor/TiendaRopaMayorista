#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <memory>
#include <vector>
#include "Cotizacion.h"

class Vendedor {
private:
    std::string nombre_;
    std::string apellido_;
    int codigo_;
    std::vector<std::shared_ptr<Cotizacion>> cotizaciones_;

public:
    Vendedor(const std::string& nombre, const std::string& apellido, int codigo);
    void agregarCotizacion(std::shared_ptr<Cotizacion> cotizacion);
    const std::vector<std::shared_ptr<Cotizacion>>& obtenerCotizaciones() const;
};

#endif // VENDEDOR_H
