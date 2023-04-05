#include "Presenter.h"
#include "Tienda.h"
#include <iostream>

std::string Presenter::nuevaCotizacion(const std::string &nombreBuscado,
                                        int cantidad, float precioUnitario) {
  auto retVal = tienda.nuevaCotizacion(nombreBuscado, cantidad, precioUnitario);
  if (retVal == nullptr) {
    return "";
  } else {
    return std::move(retVal->imprimir());
  }
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