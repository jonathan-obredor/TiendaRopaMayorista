#ifndef COTIZACION_H
#define COTIZACION_H

#include "Imprimible.h"
#include "Prenda.h"
#include <memory>

class Cotizacion : public Imprimible {
public:
  Cotizacion(int id, const std::string &fecha, const std::string &hora,
             std::string nombreP, int cantidad, float precioUnitario)
      : idCotizacion(id), fecha(fecha), hora(hora), nombrePrenda(nombreP),
        cantidad(cantidad), precioUnitario(precioUnitario) {}

  // Cotizacion(const Cotizacion &other) = default;

  Cotizacion(Cotizacion &&other) noexcept
      : idCotizacion(other.idCotizacion), fecha(std::move(other.fecha)),
        hora(std::move(other.hora)),
        nombrePrenda(std::move(other.nombrePrenda)), cantidad(other.cantidad),
        precioUnitario(other.precioUnitario) {}

  virtual ~Cotizacion() = default;

  std::string imprimir() const override;
  int getId() const { return idCotizacion; }
  const std::string &getFecha() const { return fecha; }
  const std::string &getHora() const { return hora; }
  int getCantidad() const { return cantidad; }
  auto getPrecioFinal() const;

private:
  int idCotizacion;
  std::string fecha;
  std::string hora;
  std::string nombrePrenda;
  int cantidad;
  float precioUnitario;
};

#endif // COTIZACION_H
