#include <iostream>
#include <string>

class TerminalUI
{
public:
    /*
    TerminalUI(const std::string &tiendaNombre, const std::string &tiendaDireccion, const std::string &vendedorNombre, int vendedorCodigo)
        : tiendaNombre(tiendaNombre), tiendaDireccion(tiendaDireccion), vendedorNombre(vendedorNombre), vendedorCodigo(vendedorCodigo)
    {
    }
    */
    // TerminalUI();
    virtual ~TerminalUI() = default;

    int mostrarPantallaPrincipal() const;

private:
    void limpiarPantalla();

    std::string tiendaNombre;
    std::string tiendaDireccion;
    std::string vendedorNombre;
    int vendedorCodigo;
};
