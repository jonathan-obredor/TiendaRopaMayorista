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
      : nombre(nombre), apellido(apellido), codigo(codigo) {}

  // Move constructor
  Vendedor(Vendedor &&other) noexcept
      : nombre(std::move(other.nombre)), apellido(std::move(other.apellido)),
        codigo(other.codigo), cotizaciones(std::move(other.cotizaciones)) {}

  virtual ~Vendedor() = default;

  const auto &obtenerCotizaciones() const { return cotizaciones; }

  const Cotizacion *nuevaCotizacion(const std::string &nombre, int cantidad,
                                    float precioUnitario);

  auto getNombreCompleto() const { return nombre + " " + apellido; }
  auto getCodigo() const { return codigo; }
  std::string imprimir() const override {
    return "Vendedor: " + getNombreCompleto() +
           ", Codigo: " + std::to_string(getCodigo());
  }

private:
  std::string nombre;
  std::string apellido;
  int codigo;
  std::vector<Cotizacion> cotizaciones;
};

#endif // VENDEDOR_H
