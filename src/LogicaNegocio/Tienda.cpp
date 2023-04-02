#include "Tienda.h"

Tienda::Tienda(const std::string& nombre, const std::string& direccion)
    : nombre(nombre), direccion(direccion) {}

void Tienda::agregarPrenda(const Prenda& prenda) {
    prendas.push_back(prenda);
}

std::vector<Prenda>& Tienda::obtenerPrendas() {
    return prendas;
}
