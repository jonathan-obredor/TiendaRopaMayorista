#include "Cotizacion.h"
#include <iostream>

auto Cotizacion::getPrecioFinal() const {
  return static_cast<float>(cantidad) * precioUnitario;
}

std::string Cotizacion::imprimir() const {
  return "Número de identificación: " + std::to_string(getId()) + "\n" +
         "Fecha y Hora de la cotización: " + getFecha() + " " + getHora() +
         "\n"
         // std::cout + "Código del vendedor: " + vendedor.getCodigo() + "\n";
         //  std::cout + "Prenda cotizada: " + getDescripcionPrenda() + "\n";
         + "Precio unitario: $" + std::to_string(precioUnitario) + "\n" +
         "Cantidad de unidades cotizadas: " + std::to_string(getCantidad()) +
         "\n" + "Precio final: $" + std::to_string(getPrecioFinal()) + "\n\n";
}
