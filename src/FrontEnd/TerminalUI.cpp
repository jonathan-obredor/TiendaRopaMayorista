
#include "TerminalUI.h"
#include <iostream>
#include <limits>

int TerminalUI::mostrarPantallaPrincipal()
{
    limpiarPantalla();
    int opcion = 0;
    std::cout << "COTIZADOR EXPRESS MENÚ PRINCIPAL\n";
    std::cout << "--------------------------------------\n";
    // std::cout << tiendaNombre << " | " << tiendaDireccion << "\n";
    std::cout << "--------------------------------------\n";
    // std::cout << vendedorNombre << " | " << vendedorCodigo << "\n";
    std::cout << "--------------------------------------\n";
    std::cout << "SELECCIONE UNA OPCIÓN DEL MENÚ:\n";
    std::cout << "1) Historial de Cotizaciones\n";
    std::cout << "2) Realizar Cotización\n";
    std::cout << "3) Salir\n";
    std::cout << "Ingrese la opción deseada: ";
    std::cin >> opcion;
    std::cout << "\n";
    return opcion;
}

void TerminalUI::limpiarPantalla()
{
    system("clear");
}

void TerminalUI::mostrarHistorialCotizaciones(Vendedor &vendedor)
{
    limpiarPantalla();
    auto cotizaciones = vendedor.obtenerCotizaciones();

    if (cotizaciones.empty())
    {
        std::cout << "No hay cotizaciones registradas.\n";
        // return;
    }

    std::cout << "COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES\n";
    std::cout << "--------------------------------------------\n";

    for (const auto &cotizacion : cotizaciones)
    {
        std::cout << "Número de identificación: " << cotizacion->getId() << "\n";
        std::cout << "Fecha y Hora de la cotización: " + cotizacion->getFecha() + " " + cotizacion->getHora() << "\n";
        std::cout << "Código del vendedor: " << vendedor.getCodigo() << "\n";
        // std::cout << "Prenda cotizada: " << cotizacion->getDescripcionPrenda() << "\n";
        std::cout << "Precio unitario: $" << cotizacion->obtenerPrenda()->getPrecio() << "\n";
        std::cout << "Cantidad de unidades cotizadas: " << cotizacion->getCantidad() << "\n";
        std::cout << "Precio final: $" << cotizacion->getPrecioFinal() << "\n";
        std::cout << "\n";
    }
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Presiona cualquier tecla para continuar.\n";
    std::cout << "-------------------------------------------------------\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
