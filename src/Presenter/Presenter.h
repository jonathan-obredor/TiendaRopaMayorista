#ifndef PRESENTER_H
#define PRESENTER_H

#include "Tienda.h"

class Presenter {
public:
  Presenter(Tienda &tienda) : tienda(tienda) {}

  std::string obtenerCotizaciones() const;

  // auto getCodigoVendedor() const { return vendedor.getCodigo(); }

  int getStockPrenda(const std::string &nombre) const {
    return tienda.getStockPrenda(nombre);
  }

  std::string nuevaCotizacion(const std::string &nombreBuscado, int cantidad,
                              float precioUnitario);

  int getCodigoVendedor() { return tienda.getCodigoVendedor(); }
  auto imprimirTienda() { return tienda.imprimir(); }
  auto imprimirVendedor(){return tienda.getVendedorActivo()->imprimir();}

private:
  Tienda &tienda;
};

#endif
