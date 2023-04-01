#ifndef COTIZACION_H
#define COTIZACION_H

#include <memory>
#include "Prenda.h"

class Cotizacion {
private:
    int id_;
    std::string fecha_;
    std::string hora_;
    int codigoVendedor_;
    std::shared_ptr<Prenda> prenda_;
    int cantidad_;
    float resultado_;

public:
    Cotizacion(int id, const std::string& fecha, const std::string& hora, int codigoVendedor, std::shared_ptr<Prenda> prenda, int cantidad, float resultado);
    const std::shared_ptr<Prenda>& obtenerPrenda() const;
    int obtenerCantidad() const;
};

#endif // COTIZACION_H
