#include "Vendedor.h"

void Vendedor::agregarCotizacion(std::shared_ptr<Cotizacion> cotizacion)
{
    cotizaciones_.push_back(cotizacion);
}
