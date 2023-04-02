#include "Cotizacion.h"

float Cotizacion::getPrecioFinal() const
{
    float precioPrenda = prenda_->getPrecio();
    return cantidad_ * precioPrenda;
}