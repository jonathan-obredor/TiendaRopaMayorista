
#include "TerminalUI.h"

int TerminalUI::mostrarPantallaPrincipal() const
{
    // Limpiar la pantalla
    system("clear");

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