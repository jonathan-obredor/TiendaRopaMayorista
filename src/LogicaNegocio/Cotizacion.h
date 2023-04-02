#ifndef COTIZACION_H
#define COTIZACION_H

#include <memory>
#include "Prenda.h"

class Cotizacion
{
public:
    Cotizacion(int id, const std::string &fecha, const std::string &hora, int codigoVendedor, std::shared_ptr<Prenda> prenda, int cantidad, float resultado)
        : id_(id), fecha_(fecha), hora_(hora), codigoVendedor_(codigoVendedor), prenda_(prenda), cantidad_(cantidad), resultado_(resultado)
    {
    }
    virtual ~Cotizacion() = default;

    const std::shared_ptr<Prenda> &obtenerPrenda() const;
    int obtenerCantidad() const;

private:
    int id_;
    std::string fecha_;
    std::string hora_;
    int codigoVendedor_;
    std::shared_ptr<Prenda> prenda_;
    int cantidad_;
    float resultado_;
};

#endif // COTIZACION_H
