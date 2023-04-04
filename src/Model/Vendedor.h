#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Cotizacion.h"
#include <memory>
#include <string>
#include <vector>

class Vendedor {
public:
  Vendedor(const std::string &nombre, const std::string &apellido, int codigo)
      : nombre_(nombre), apellido_(apellido), codigo_(codigo) {}

  /*
    // Copy constructor
    Vendedor(const Vendedor &other)
        : nombre_(other.nombre_), apellido_(other.apellido_),
          codigo_(other.codigo_) {
      // Copy the vector of unique_ptrs using std::make_unique to create new
    objects for (const auto &cotizacion : other.cotizaciones_) {
        cotizaciones_.push_back(std::make_unique<Cotizacion>(*cotizacion));
      }
    }
    */
  // Move constructor
  Vendedor(Vendedor &&other) noexcept
      : nombre_(std::move(other.nombre_)),
        apellido_(std::move(other.apellido_)), codigo_(other.codigo_),
        cotizaciones_(std::move(other.cotizaciones_)) {}

  virtual ~Vendedor() = default;

  const auto &obtenerCotizaciones() const { return cotizaciones_; }
  auto getNombreCompleto() const { return nombre_ + " " + apellido_; }
  auto getCodigo() const { return codigo_; }
  void nuevaCotizacion(const std::string &nombre, int cantidad,
                       float precioUnitario);

private:
  std::string nombre_;
  std::string apellido_;
  int codigo_;
  std::vector<Cotizacion> cotizaciones_;
};

#endif // VENDEDOR_H
