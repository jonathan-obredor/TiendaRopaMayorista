
#include "TerminalUI.h"
#include <iostream>
#include <limits>

auto TerminalUI::menuPrincipal() {
  nuevaPantalla();
  int opcion = 0;
  std::cout << "-------------MENÚ PRINCIPAL------------------\n";
  barra();
  // std::cout << tiendaNombre << " | " << tiendaDireccion << "\n";
  barra();
  // std::cout << vendedorNombre << " | " << vendedorCodigo << "\n";
  barra();
  std::cout << "SELECCIONE UNA OPCIÓN DEL MENÚ:\n";
  std::cout << "1) Historial de Cotizaciones\n";
  std::cout << "2) Realizar Cotización\n";
  std::cout << "3) Salir\n";
  std::cout << "Ingrese la opción deseada: ";
  std::cin >> opcion;
  std::cout << "\n";
  return opcion;
}

void TerminalUI::runApp() {
  int opcion = -1;
  while (opcion != static_cast<int>(MenuOption::Salir)) {
    opcion = menuPrincipal();
    switch (static_cast<MenuOption>(opcion)) {
    case MenuOption::HistorialCotizaciones:
      mostrarHistorialCotizaciones();
      break;
    case MenuOption::RealizarCotizacion:
      realizarCotizacion();
      break;
    case MenuOption::Salir:
      std::cout << "Salir.\n";
      break;
    default:
      std::cout << "Opción inválida.\n";
      break;
    }
  }
}

void TerminalUI::nuevaPantalla() {
  // system("clear");
  std::cout << "-----------COTIZADOR EXPRESS-----------------\n";
  barra();
  std::cout << "---------Presiona 3 para salir---------------\n";
  barra();
}

void TerminalUI::barra() {
  std::cout << "---------------------------------------------\n";
}

void TerminalUI::mostrarHistorialCotizaciones() {
  nuevaPantalla();
  std::cout << "Código del vendedor: " << presenter.getCodigoVendedor() << "\n";
  barra();
  std::cout << presenter.obtenerCotizaciones();
  enterParaContinuar();
}

auto eleccion() {
  int eleccion = -1;
  std::cin >> eleccion;
  while (eleccion != 1 && eleccion != 2 && eleccion != 3) {
    std::cout << "Opción inválida. Ingrese 1 , 2 , 3 : ";
    std::cin >> eleccion;
  }
  return eleccion;
}

void TerminalUI::cuello() {
  nuevaPantalla();
  std::cout << "PASO 2.b: Selecciona el tipo de cuello:\n\n";
  std::cout << "1. Cuello mao\n";
  std::cout << "2. Cuello comun\n\n";

  switch (eleccion()) {
  case 1: // cuello mao
    nombreBuscado += "cuello mao ";
    nuevaPantalla();

    break;
  case 2: // cuello comun
    nombreBuscado += "cuello comun ";
    nuevaPantalla();
    break;
  case 3:
    return; // TODO como terminar la cotizacion??
    break;
  }
}

void TerminalUI::realizarCotizacion() {
  nuevaPantalla();
  std::cout << "PASO 1: Selecciona la prenda a cotizar:\n\n";
  std::cout << "1. Camisa\n";
  std::cout << "2. Pantalón\n\n";

  nombreBuscado = "";

  switch (eleccion()) {
  case 1: // camisa
    nombreBuscado = "Camisa ";
    nuevaPantalla();
    std::cout << "PASO 2.a: La camisa a cotizar, ¿Es Manga corta?\n";
    std::cout << "1.  Sí\n";
    std::cout << "2.  No\n";
    switch (eleccion()) {
    case 1: // manga corta
      nombreBuscado += "manga corta ";
      cuello();
      break;
    case 2: // manga larga
      nombreBuscado += "manga larga ";
      cuello();
      break;
    case 3:
      return;
      break;
    }
    break;
  case 2: // pantalón
    nombreBuscado = "Pantalon ";
    nuevaPantalla();
    std::cout << "PASO 2: El pantalon es chupin?:\n\n";
    std::cout << "1.  Sí\n";
    std::cout << "2.  No\n";
    switch (eleccion()) {
    case 1: // chupin
      nombreBuscado += "chupin ";
      break;
    case 2: // comun
      nombreBuscado += "comun ";
      break;
    case 3:
      return;
      break;
    }
    break;
  case 3:
    // std::cout << "\nLa cotización ha sido cancelada.\n\n";
    return;
    break;
  }

  nuevaPantalla();
  std::cout << "PASO 3: Seleccione la calidad de la prenda\n\n";
  std::cout << "1. Standard\n";
  std::cout << "2. Premium\n\n";
  switch (eleccion()) {
  case 1: // standard
    nombreBuscado += "calidad Standard";
    break;
  case 2: // premium
    nombreBuscado += "calidad Premium";
    break;
  case 3:
    return;
    break;
  }

  nuevaPantalla();
  std::cout << "Cotizando: " << nombreBuscado << "\n";
  float precioUnitario; // TODO mover a presenter
  std::cout << "Ingrese el precio unitario (usar punto en vez de coma): ";
  // validate user input
  while (!(std::cin >> precioUnitario)) {
    std::cout << "Error: Ingrese un valor numérico válido.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  nuevaPantalla();
  auto stock = presenter.getStockPrenda(nombreBuscado);
  std::cout << "INFORMACIÓN:\n\n";
  std::cout << "EXISTE(N) " << stock
            << " UNIDAD(ES) EN STOCK DE LA PRENDA SELECCIONADA\n\n";
  int cantidad; // todo mover al presenter
  std::cout << "PASO 5: Ingrese la cantidad de unidades a cotizar: ";
  std::cin >> cantidad;

  if (presenter.nuevaCotizacion(nombreBuscado, cantidad, precioUnitario) ==
      -1) {
    barra();
    std::cout << "Error: Esta intentando cotizar un numero mayor al stock "
                 "disponible. Abortando.\n";
    enterParaContinuar();
  }

  if (stock < cantidad) {

    return;
  }

  // mostrar el resultado de la nueva cotizacion
  nuevaPantalla();
  // cotizacion->imprimir();
}

void TerminalUI::enterParaContinuar() {
  barra();
  std::cout << "Presiona Enter para continuar.\n";
  barra();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}
