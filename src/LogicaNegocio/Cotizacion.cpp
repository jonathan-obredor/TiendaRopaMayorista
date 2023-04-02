#include "Cotizacion.h"
#include <iostream>

float Cotizacion::getPrecioFinal() const
{
    float precioPrenda = prenda_->getPrecio();
    return cantidad_ * precioPrenda;
}

void Cotizacion::imprimir()
{
    std::cout << "Número de identificación: " << getId() << "\n";
    std::cout << "Fecha y Hora de la cotización: " + getFecha() + " " + getHora() << "\n";
    //std::cout << "Código del vendedor: " << vendedor.getCodigo() << "\n"; //TODO deberìa mostrarse al principio del historial de cotizaciones, no aca
    // std::cout << "Prenda cotizada: " << getDescripcionPrenda() << "\n";
    std::cout << "Precio unitario: $" << obtenerPrenda()->getPrecio() << "\n";
    std::cout << "Cantidad de unidades cotizadas: " << getCantidad() << "\n";
    std::cout << "Precio final: $" << getPrecioFinal() << "\n";
    std::cout << "\n";
}
