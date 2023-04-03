#include "Tienda.h"
#include <utility>

void Tienda::agregarPrenda(const Prenda &prenda)
{
    prendas.push_back(std::move(prenda));
}
