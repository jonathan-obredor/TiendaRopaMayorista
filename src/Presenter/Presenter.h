#ifndef PRESENTER_H
#define PRESENTER_H

#include "Tienda.h"
#include "Vendedor.h"

class Presenter {
public:
  Presenter(Tienda &tienda, Vendedor &vendedor)
      : tienda(tienda), vendedor(vendedor) {}
  auto obtenerCotizaciones() { return vendedor.obtenerCotizaciones(); }
  auto getCodigoVendedor() const { return vendedor.getCodigo(); }

private:
  Tienda &tienda;
  Vendedor &vendedor;
};

#endif
