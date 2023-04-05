#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Cotizacion.h"
#include "Imprimible.h"
#include <memory>
#include <string>
#include <vector>

class Vendedor : public Imprimible {
public:
  Vendedor(const std::string &nombre, const std::string &apellido, int codigo)
      : nombre_(nombre), apellido_(apellido), codigo_(codigo) {}

  // Move constructor
  Vendedor(Vendedor &&other) noexcept
      : nombre_(std::move(other.nombre_)),
        apellido_(std::move(other.apellido_)), codigo_(other.codigo_),
        cotizaciones_(std::move(other.cotizaciones_)) {}

  virtual ~Vendedor() = default;

  const auto &obtenerCotizaciones() const { return cotizaciones_; }
  auto getNombreCompleto() const { return nombre_ + " " + apellido_; } //TODO deprecated, usar imprimir()
  auto getCodigo() const { return codigo_; }
  void nuevaCotizacion(const std::string &nombre, int cantidad,
                       float precioUnitario);

  std::string imprimir() const override {
    return "Vendedor: " + getNombreCompleto() +
           ", Codigo: " + std::to_string(getCodigo());
  }

private:
  std::string nombre_;
  std::string apellido_;
  int codigo_;
  std::vector<Cotizacion> cotizaciones_;
};

#endif // VENDEDOR_H
