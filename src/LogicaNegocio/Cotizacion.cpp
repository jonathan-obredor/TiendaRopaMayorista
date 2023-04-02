#include "Cotizacion.h"

const std::shared_ptr<Prenda>& Cotizacion::obtenerPrenda() const {
    return prenda_;
}

int Cotizacion::obtenerCantidad() const {
    return cantidad_;
}
