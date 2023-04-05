#ifndef TIENDA_H
#define TIENDA_H

#include "Imprimible.h"
#include "Prenda.h"
#include "Vendedor.h"
#include <string>
#include <vector>

class Tienda : public Imprimible {
public:
  Tienda(const std::string &nombre, const std::string &direccion)
      : nombre(nombre), direccion(direccion) {}
  virtual ~Tienda() = default;

  void init();
  std::vector<Prenda> &getPrendas() { return prendas; }
  const std::string &getNombre() const { return nombre; }
  const std::string &getDireccion() const { return direccion; }
  auto buscarPrenda(const std::string &nombre);
  int getStockPrenda(const std::string &nombre);
  int getCodigoVendedor() const;
  Vendedor *getVendedorActivo() { return &(vendedores.front()); }

  void mostrarPrendas();

  const Cotizacion *nuevaCotizacion(const std::string &nombreBuscado,
                                    int cantidad, float precioUnitario);

  const std::vector<Cotizacion> &obtenerCotizaciones() const;

  std::string imprimir() const override {
    return "Tienda " + getNombre() + "     Dirección: " + getDireccion();
  }

private:
  void agregarPrenda(Prenda &&prenda);
  void agregarVendedor(Vendedor &&ven);
  std::string nombre;
  std::string direccion;
  std::vector<Prenda> prendas;
  std::vector<Vendedor> vendedores;
};

#endif // TIENDA_H
