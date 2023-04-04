#include "Presenter.h"
#include "Tienda.h"
#include <iostream>

int Presenter::nuevaCotizacion(const std::string &nombreBuscado, int cantidad,
                               float precioUnitario) {
  return tienda.nuevaCotizacion(nombreBuscado, cantidad, precioUnitario);
}

std::string Presenter::obtenerCotizaciones() const {
  const std::vector<Cotizacion> &cotizaciones = tienda.obtenerCotizaciones();
  std::string out = "";
  if (cotizaciones.empty()) {
    out = "No hay cotizaciones registradas.\n";
  } else {
    for (const Cotizacion &cotizacion : cotizaciones) {
      out += cotizacion.imprimir();
    }
  }
  return out;
}