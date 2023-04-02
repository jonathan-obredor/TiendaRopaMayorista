#include "LogicaNegocio/Tienda.h"
#include "FrontEnd/TerminalUI.h"
#include <iostream>

enum class MenuOption
{
  HistorialCotizaciones = 1,
  RealizarCotizacion = 2,
  Salir = 3
};

int main()
{
  // Crear objetos de la tienda y el vendedor
  Tienda tienda("Mi Tienda", "Calle Falsa 123");
  Vendedor vendedor("Juan", "Pérez", 1234);

  // Crear objeto de la pantalla principal y mostrarla
  TerminalUI ui;
  int opcion = -1;
  while (static_cast<MenuOption>(opcion) != MenuOption::Salir)
  {
    opcion = ui.mostrarPantallaPrincipal();

    switch (static_cast<MenuOption>(opcion))
    {
    case MenuOption::HistorialCotizaciones:
      ui.mostrarHistorialCotizaciones(vendedor);
      break;
    case MenuOption::RealizarCotizacion:
      // TODO: Implementar la opción "Realizar Cotización"
      std::cout << "Opción no implementada.\n";
      break;
    case MenuOption::Salir:
      std::cout << "Salir.\n";
      break;
    default:
      std::cout << "Opción inválida.\n";
      break;
    }
  }
  return 0;
}