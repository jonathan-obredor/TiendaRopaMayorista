#include "Pantalon.h"

Pantalon::Pantalon(const std::string& nombre, Calidad calidad, int cantidadEnStock, TipoPantalon tipo) :
    Prenda(nombre, calidad, cantidadEnStock),
    tipoPantalon_(tipo)
{
}

