#include "Pantalon.h"

Pantalon::Pantalon(const std::string &nombre, Calidad calidad, int cantidadEnStock, TipoPantalon tipo) : Prenda(nombre, calidad, cantidadEnStock),
                                                                                                         tipo(tipo)
{
}

float Pantalon::getPrecio() const
{
    float precioBase = Prenda::getPrecio();
    if (tipo == TipoPantalon::Chupin)
    {
        precioBase *= 0.88; // se rebaja 12%
    }
    if (calidad == Calidad::Premium)
    {
        precioBase *= 1.3; // se aumenta 30%
    }
    return precioBase;
}