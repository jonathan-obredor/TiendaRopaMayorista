#include <string>
#include "Vendedor.h"

class TerminalUI
{
public:
    virtual ~TerminalUI() = default;

    int mostrarPantallaPrincipal();
    void mostrarHistorialCotizaciones(Vendedor &vendedor);

private:
    void limpiarPantalla();
};
