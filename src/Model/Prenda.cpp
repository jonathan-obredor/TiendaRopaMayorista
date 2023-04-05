#include "Prenda.h"

void Prenda::descontarStock(int cantidad) {
  if (cantidadEnStock >= cantidad) {
    cantidadEnStock -= cantidad;
  }
}

std::string Prenda::imprimir() const {
  std::string output = "Nombre: " + getNombre() + "\n"; //TODO ahora nombre tiene la calidad !!
  output += "Calidad: " + calidadToString(calidad) + "\n";
  output += "Cantidad en Stock: " + std::to_string(cantidadEnStock) + "\n";
  output += "Precio: $" + std::to_string(precio) + "\n";
  return output;
}
std::string Prenda::calidadToString(Calidad c) const {
  switch (c) {
  case Calidad::Standard:
    return "Standard";
  case Calidad::Premium:
    return "Premium";
  default:
    return "";
  }
}