#include "Pantalon.h"

float Pantalon::getPrecio() const {
  float precioBase = Prenda::getPrecio();
  if (tipo == TipoPantalon::Chupin) {
    precioBase *= 0.88; // se rebaja 12%
  }
  if (calidad == Calidad::Premium) {
    precioBase *= 1.3; // se aumenta 30%
  }
  return precioBase;
}
std::string Pantalon::imprimir() const {
  std::string res = "Pantalon ";
  switch (tipo) {
  case TipoPantalon::Comun:
    res += "Comun";
    break;
  case TipoPantalon::Chupin:
    res += "Chupin";
    break;
  }
  return res;
}