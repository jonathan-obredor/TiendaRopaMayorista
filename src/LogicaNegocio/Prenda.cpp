#include "Prenda.h"

Calidad Prenda::getCalidad() const
{
    return calidad;
}

void Prenda::setCalidad(Calidad calidad)
{
    this->calidad = calidad;
}

int Prenda::getUnidadesEnStock() const
{
    return cantidadEnStock;
}

void Prenda::setUnidadesEnStock(int cantidad)
{
    cantidadEnStock = cantidad;
}
