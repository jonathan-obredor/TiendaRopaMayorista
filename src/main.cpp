#include <iostream>
#include "Vendedor.h"
#include "Cotizacion.h"
#include "Prenda.h"
#include "Pantalon.h"
#include "Camisa.h"
#include "Tienda.h"

int main() {
/*  
  // Crear un objeto Tienda
  Tienda tienda("Mi Tienda", "Calle Falsa 123");

  // Crear algunos objetos Prenda y agregarlos a la Tienda
  Pantalon pantalon("chupines");
  pantalon.setCalidad("premium");
  pantalon.setCantidadEnStock(10);
  tienda.agregarPrenda(pantalon);

  Camisa camisa("manga larga", "comun");
  camisa.setCalidad("standard");
  camisa.setCantidadEnStock(20);
  tienda.agregarPrenda(camisa);

  // Crear un objeto Vendedor
  Vendedor vendedor("Juan", "Perez", 123);

  // Crear una Cotizacion usando una de las prendas de la Tienda
  Prenda* prenda = tienda.getPrendas()[0];
  Cotizacion cotizacion(1, "2023-03-31", "14:30", vendedor.getCodigo(), *prenda, 2);
  cotizacion.calcularResultado();

  // Agregar la Cotizacion al Vendedor y mostrar todas las Cotizaciones del Vendedor
  vendedor.agregarCotizacion(cotizacion);
  for (Cotizacion cotizacion : vendedor.obtenerCotizaciones()) {
    std::cout << "Cotizacion #" << cotizacion.getId() << " - " << cotizacion.getFecha() << " " << cotizacion.getHora() << std::endl;
  }
*/
  return 0;
}
