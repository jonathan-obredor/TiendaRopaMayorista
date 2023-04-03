#include "Tienda.h"
#include "Camisa.h"
#include "Pantalon.h"
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
  Tienda tienda("Mi Tienda", "Calle Falsa 123");
  Vendedor vendedor("Juan", "Pérez", 1234);
  TerminalUI ui;

  tienda.agregarPrenda(Camisa("Camisa de cuello mao de calidad Standard manga corta", Calidad::Standard, 100, 0.0f, TipoCuello::mao, TipoManga::corta));
  tienda.agregarPrenda(Camisa("Camisa de cuello mao de calidad Premium manga corta", Calidad::Premium, 100, 0.0f, TipoCuello::mao, TipoManga::corta));

  tienda.agregarPrenda(Camisa("Camisa de cuello comun de calidad Standard manga corta", Calidad::Standard, 150, 0.0f, TipoCuello::comun, TipoManga::corta));
  tienda.agregarPrenda(Camisa("Camisa de cuello comun de calidad Premium manga corta", Calidad::Premium, 150, 0.0f, TipoCuello::comun, TipoManga::corta));

  tienda.agregarPrenda(Camisa("Camisa de cuello mao de calidad Standard manga larga", Calidad::Standard, 75, 0.0f, TipoCuello::mao, TipoManga::corta));
  tienda.agregarPrenda(Camisa("Camisa de cuello mao de calidad Premium manga larga", Calidad::Premium, 75, 0.0f, TipoCuello::mao, TipoManga::corta));

  tienda.agregarPrenda(Camisa("Camisa de cuello comun de calidad Standard manga larga", Calidad::Standard, 175, 0.0f, TipoCuello::comun, TipoManga::corta));
  tienda.agregarPrenda(Camisa("Camisa de cuello comun de calidad Premium manga larga", Calidad::Premium, 175, 0.0f, TipoCuello::comun, TipoManga::corta));

  tienda.agregarPrenda(Pantalon("Pantalon chupin de calidad Standard", Calidad::Standard, 750, 0.0f, TipoPantalon::Chupin));
  tienda.agregarPrenda(Pantalon("Pantalon chupin de calidad Premium", Calidad::Premium, 750, 0.0f, TipoPantalon::Chupin));

  tienda.agregarPrenda(Pantalon("Pantalon comun de calidad Standard", Calidad::Standard, 250, 0.0f, TipoPantalon::Comun));
  tienda.agregarPrenda(Pantalon("Pantalon comun de calidad Premium", Calidad::Premium, 250, 0.0f, TipoPantalon::Comun));

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
      ui.realizarCotizacion(vendedor, tienda);
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