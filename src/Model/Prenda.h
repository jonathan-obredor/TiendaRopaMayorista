#ifndef PRENDA_H
#define PRENDA_H

#include <string>

enum class Calidad { Standard, Premium };

class Prenda {
public:
  Prenda(const std::string &nombre, Calidad calidad = Calidad::Standard,
         int cantidadEnStock = 0, float precio = 0.0f)
      : nombre(nombre), calidad(calidad), cantidadEnStock(cantidadEnStock),
        precio(precio) {}
/*
  // Copy constructor
  Prenda(const Prenda &other)
      : nombre(other.nombre), calidad(other.calidad),
        cantidadEnStock(other.cantidadEnStock), precio(other.precio) {}
*/
  // Move constructor
  Prenda(Prenda &&other) noexcept
      : nombre(std::move(other.nombre)), calidad(other.calidad),
        cantidadEnStock(other.cantidadEnStock), precio(other.precio) {}

  virtual ~Prenda() = default;

  Calidad getCalidad() const { return calidad; }
  void setCalidad(Calidad calidad) { this->calidad = calidad; }

  int getCantidadEnStock() const { return cantidadEnStock; }
  void setCantidadEnStock(int unidadesEnStock) {
    cantidadEnStock = unidadesEnStock;
  }

  void descontarStock(int cantidad);

  const std::string &getNombre() const { return nombre; }

  const float &getPrecio() const { return precio; }
  // void setPrecio(float precio);

protected:
  Calidad calidad;

private:
  float precio;
  std::string nombre;
  int cantidadEnStock;
};

#endif // PRENDA_H
