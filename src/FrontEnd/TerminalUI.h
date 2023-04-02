#include <string>
#include "Vendedor.h"
#include "Tienda.h"

class TerminalUI
{
public:
    virtual ~TerminalUI() = default;

    int mostrarPantallaPrincipal();
    void mostrarHistorialCotizaciones(Vendedor &vendedor);
    void realizarCotizacion(Vendedor &vendedor, Tienda &tienda);

private:
    void nuevaPantalla();
    void barra();
};
