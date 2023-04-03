#include "Cotizacion.h"
#include <iostream>

auto Cotizacion::getPrecioFinal() const {
  return static_cast<float>(cantidad_) * prenda_->getPrecio();
}

void Cotizacion::imprimir() {
  std::cout << "Número de identificación: " << getId() << "\n";
  std::cout << "Fecha y Hora de la cotización: " + getFecha() + " " + getHora()
            << "\n";
  // std::cout << "Código del vendedor: " << vendedor.getCodigo() << "\n";
  //  std::cout << "Prenda cotizada: " << getDescripcionPrenda() << "\n";
  std::cout << "Precio unitario: $" << obtenerPrenda()->getPrecio() << "\n";
  std::cout << "Cantidad de unidades cotizadas: " << getCantidad() << "\n";
  std::cout << "Precio final: $" << getPrecioFinal() << "\n";
  std::cout << "\n";
}
