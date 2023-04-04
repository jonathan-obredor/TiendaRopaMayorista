#ifndef COTIZACION_H
#define COTIZACION_H

#include "Prenda.h"
#include <memory>

class Cotizacion {
public:
  Cotizacion(int id, const std::string &fecha, const std::string &hora,
             std::string nombreP, int cantidad, float precioUnitario)
      : idCotizacion(id), fecha_(fecha), hora_(hora), nombrePrenda(nombreP),
        cantidad_(cantidad), precioUnitario(precioUnitario) {}

  // Cotizacion(const Cotizacion &other) = default;

  Cotizacion(Cotizacion &&other) noexcept
      : idCotizacion(other.idCotizacion), fecha_(std::move(other.fecha_)),
        hora_(std::move(other.hora_)),
        nombrePrenda(std::move(other.nombrePrenda)), cantidad_(other.cantidad_),
        precioUnitario(other.precioUnitario) {}

  virtual ~Cotizacion() = default;

  std::string imprimir() const;
  int getId() const { return idCotizacion; }
  const std::string &getFecha() const { return fecha_; }
  const std::string &getHora() const { return hora_; }
  int getCantidad() const { return cantidad_; }
  auto getPrecioFinal() const;

private:
  int idCotizacion;
  std::string fecha_;
  std::string hora_;
  // int codigoVendedor_; //todo no es necesario, un vendedor sabe cuantas
  // cotizaciones tiene, no viceversa std::shared_ptr<Prenda> prenda_; //TODO no
  // es necesario, solo se usa un contador
  std::string nombrePrenda;
  int cantidad_;
  float precioUnitario;
};

#endif // COTIZACION_H
