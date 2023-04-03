#include "Tienda.h"
#include "Vendedor.h"
#include <string>

enum class MenuOption {
  HistorialCotizaciones = 1,
  RealizarCotizacion = 2,
  Salir = 3
};
class TerminalUI {
public:
  virtual ~TerminalUI() = default;

  int mostrarPantallaPrincipal();
  void mostrarHistorialCotizaciones(Vendedor &vendedor);
  void realizarCotizacion(Vendedor &vendedor, Tienda &tienda);
  void runApp();

private:
  void nuevaPantalla();
  void barra();
};
