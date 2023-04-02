#include "Vendedor.h"

Vendedor::Vendedor(const std::string& nombre, const std::string& apellido, int codigo)
    : nombre_(nombre), apellido_(apellido), codigo_(codigo) {}

void Vendedor::agregarCotizacion(std::shared_ptr<Cotizacion> cotizacion) {
    cotizaciones_.push_back(cotizacion);
}

const std::vector<std::shared_ptr<Cotizacion>>& Vendedor::obtenerCotizaciones() const {
    return cotizaciones_;
}
