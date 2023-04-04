#include "Tienda.h"
#include "Camisa.h"
#include "Pantalon.h"
#include "Vendedor.h"
#include <algorithm>
#include <iostream>
#include <utility>

void Tienda::agregarPrenda(Prenda &&pren) {
  prendas.emplace_back(std::move(pren));
}

void Tienda::agregarVendedor(Vendedor &&ven) {
  vendedores.emplace_back(std::move(ven));
}

void Tienda::init() {
  // Agregar prendas a la tienda. esto se deberia leer de una base de datos
  agregarPrenda(Camisa("Camisa manga corta cuello mao calidad Standard",
                       Calidad::Standard, 100, 0.0f, TipoCuello::mao,
                       TipoManga::corta));
  agregarPrenda(Camisa("Camisa manga corta cuello mao calidad Premium",
                       Calidad::Premium, 100, 0.0f, TipoCuello::mao,
                       TipoManga::corta));

  agregarPrenda(Camisa("Camisa manga corta cuello comun calidad Standard",
                       Calidad::Standard, 150, 0.0f, TipoCuello::comun,
                       TipoManga::corta));
  agregarPrenda(Camisa("Camisa manga corta cuello comun calidad Premium",
                       Calidad::Premium, 150, 0.0f, TipoCuello::comun,
                       TipoManga::corta));

  agregarPrenda(Camisa("Camisa manga larga cuello mao calidad Standard",
                       Calidad::Standard, 75, 0.0f, TipoCuello::mao,
                       TipoManga::corta));
  agregarPrenda(Camisa("Camisa manga larga cuello mao calidad Premium",
                       Calidad::Premium, 75, 0.0f, TipoCuello::mao,
                       TipoManga::corta));

  agregarPrenda(Camisa("Camisa manga larga cuello comun calidad Standard",
                       Calidad::Standard, 175, 0.0f, TipoCuello::comun,
                       TipoManga::corta));
  agregarPrenda(Camisa("Camisa manga larga cuello comun calidad Premium",
                       Calidad::Premium, 175, 0.0f, TipoCuello::comun,
                       TipoManga::corta));

  agregarPrenda(Pantalon("Pantalon chupin calidad Standard", Calidad::Standard,
                         750, 0.0f, TipoPantalon::Chupin));
  agregarPrenda(Pantalon("Pantalon chupin calidad Premium", Calidad::Premium,
                         750, 0.0f, TipoPantalon::Chupin));

  agregarPrenda(Pantalon("Pantalon comun calidad Standard", Calidad::Standard,
                         250, 0.0f, TipoPantalon::Comun));
  agregarPrenda(Pantalon("Pantalon comun calidad Premium", Calidad::Premium,
                         250, 0.0f, TipoPantalon::Comun));

  agregarVendedor(Vendedor("Juan", "Pérez", 1234));

  // debug
  // mostrarPrendas();
}

void Tienda::mostrarPrendas() {
  for (const auto &prenda : prendas) {
    std::cout << prenda.getCantidadEnStock() << " - " << prenda.getNombre()
              << std::endl;
  }
}

auto Tienda::buscarPrenda(const std::string &nombre) {
  auto iter = std::find_if(
      prendas.begin(), prendas.end(),
      [&nombre](const Prenda &prenda) { return prenda.getNombre() == nombre; });
  return (iter != prendas.end()) ? &(*iter) : nullptr;
}

int Tienda::getStockPrenda(const std::string &nombre) {
  auto prenda = buscarPrenda(nombre);
  if (prenda != nullptr) {
    return prenda->getCantidadEnStock();
  }
  return 0;
}

int Tienda::nuevaCotizacion(const std::string &nombreBuscado, int cantidad,
                            float precioUnitario) {
  if (getStockPrenda(nombreBuscado) < cantidad) {
    return -1;
  }

  // TODO seleccionar al vendedor activo!
  vendedores.front().nuevaCotizacion(nombreBuscado, cantidad, precioUnitario);

  auto prenda = buscarPrenda(nombreBuscado);
  prenda->descontarStock(cantidad);
  // std::cout << "Cotización agregada exitosamente" << std::endl;
  return 0;
}

const std::vector<Cotizacion> &Tienda::obtenerCotizaciones() const {
  return vendedores.front().obtenerCotizaciones();
}

int Tienda::getCodigoVendedor() const { return vendedores.front().getCodigo(); }
