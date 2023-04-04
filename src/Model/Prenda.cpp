#include "Prenda.h"

void Prenda::descontarStock(int cantidad) {
  if (cantidadEnStock >= cantidad) {
    cantidadEnStock -= cantidad;
  }
}