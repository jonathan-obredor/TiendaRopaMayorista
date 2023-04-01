#include "Cotizacion.h"

Cotizacion::Cotizacion(int id, const std::string& fecha, const std::string& hora, int codigoVendedor, std::shared_ptr<Prenda> prenda, int cantidad, float resultado)
    : id_(id), fecha_(fecha), hora_(hora), codigoVendedor_(codigoVendedor), prenda_(prenda), cantidad_(cantidad), resultado_(resultado) {}

const std::shared_ptr<Prenda>& Cotizacion::obtenerPrenda() const {
    return prenda_;
}

int Cotizacion::obtenerCantidad() const {
    return cantidad_;
}
