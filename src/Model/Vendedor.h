#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Cotizacion.h"
#include <memory>
#include <vector>

class Vendedor {
public:
  Vendedor(const std::string &nombre, const std::string &apellido, int codigo)
      : nombre_(nombre), apellido_(apellido), codigo_(codigo) {}
  virtual ~Vendedor() = default;

  void agregarCotizacion(std::shared_ptr<Cotizacion> cotizacion);
  const std::vector<std::shared_ptr<Cotizacion>> &obtenerCotizaciones() const {
    return cotizaciones_;
  }
  auto getNombreCompleto() const { return nombre_ + " " + apellido_; }
  auto getCodigo() const { return codigo_; }

private:
  std::string nombre_;
  std::string apellido_;
  int codigo_;
  std::vector<std::shared_ptr<Cotizacion>> cotizaciones_; //TODO poblar este vector!
};

#endif // VENDEDOR_H
