#include "Prenda.h"

Prenda::Prenda(const std::string& nombre, Calidad calidad, int cantidadEnStock)
    : nombre(nombre), calidad(calidad), cantidadEnStock(cantidadEnStock) {}

Calidad Prenda::getCalidad() const {
    return calidad;
}

void Prenda::setCalidad(Calidad calidad) {
    this->calidad = calidad;
}

int Prenda::getUnidadesEnStock() const {
    return cantidadEnStock;
}

void Prenda::setUnidadesEnStock(int cantidad) {
    cantidadEnStock = cantidad;
}
