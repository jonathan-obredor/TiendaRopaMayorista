
#include "TerminalUI.h"
#include <iostream>
#include <limits>

int TerminalUI::mostrarPantallaPrincipal()
{
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

void TerminalUI::nuevaPantalla()
{
    system("clear");
    std::cout << "-----------COTIZADOR EXPRESS-----------------\n";
    barra();
    std::cout << "---------Presiona 3 para salir---------------\n";
    barra();
}

void TerminalUI::barra()
{
    std::cout << "---------------------------------------------\n";
}

void TerminalUI::mostrarHistorialCotizaciones(Vendedor &vendedor)
{
    nuevaPantalla();

    auto cotizaciones = vendedor.obtenerCotizaciones();

    if (cotizaciones.empty())
    {
        std::cout << "No hay cotizaciones registradas.\n";
        // return;
    }
    else
    {
        std::cout << "Código del vendedor: " << vendedor.getCodigo() << "\n";
        for (const auto &cotizacion : cotizaciones)
        {
            cotizacion->imprimir();
        }
    }

    barra();
    std::cout << "Presiona Enter para continuar.\n";
    barra();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

auto eleccion()
{
    int eleccion = -1;
    std::cin >> eleccion;
    while (eleccion != 1 && eleccion != 2 && eleccion != 3)
    {
        std::cout << "Opción inválida. Ingrese 1 , 2 , 3 : ";
        std::cin >> eleccion;
    }
    return eleccion;
}

void TerminalUI::realizarCotizacion(Vendedor &vendedor, Tienda &tienda)
{
    nuevaPantalla();
    std::cout << "PASO 1: Selecciona la prenda a cotizar:\n\n";
    std::cout << "1. Camisa\n";
    std::cout << "2. Pantalón\n\n";

    switch (eleccion())
    {
    case 1: // camisa
        nuevaPantalla();
        std::cout << "PASO 2.a: La camisa a cotizar, ¿Es Manga corta?\n";
        std::cout << "1.  Sí\n";
        std::cout << "2.  No\n";
        switch (eleccion())
        {
        case 1: // manga corta
            nuevaPantalla();
            std::cout << "PASO 2.b: Selecciona el tipo de cuello:\n\n";
            std::cout << "1. Cuello mao\n";
            std::cout << "2. Cuello clasico\n\n";
            switch (eleccion())
            {
            case 1: // cuello mao
                nuevaPantalla();
                break;
            case 2: // cuello clasico
                nuevaPantalla();
                break;
            case 3:
                return;
                break;
            }
        case 2: // manga larga
            nuevaPantalla();
            break;
        case 3:
            return;
            break;
        }
        break;
    case 2: // pantalón
        nuevaPantalla();
        std::cout << "PASO 2: El pantalon es chupin?:\n\n";
        std::cout << "1.  Sí\n";
        std::cout << "2.  No\n";
        switch (eleccion())
        {
        case 1: // chupin
            break;
        case 2: // clasico
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
    switch (eleccion())
    {
    case 1: // standard
        break;
    case 2: // premium
        break;
    case 3:
        return;
        break;
    }

    nuevaPantalla();
    float precio_unitario;
    std::cout << "Ingrese el precio unitario: ";
    std::cin >> precio_unitario;

    nuevaPantalla();
    std::cout << "INFORMACIÓN:\n\n";
    // std::cout << "EXISTE " << stock << " CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA\n\n"; //TODO implementar clase que controla el stock
    int cantidad;
    std::cout << "PASO 5: Ingrese la cantidad de unidades a cotizar: ";
    std::cin >> cantidad;

    // mostrar el resultado de la nueva cotizacion
    nuevaPantalla();
    // cotizacion->imprimir();
}
