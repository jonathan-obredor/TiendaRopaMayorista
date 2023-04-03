#include "Presenter.h"
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
  explicit TerminalUI(Presenter &myPresenter) : presenter(myPresenter) {}

  virtual ~TerminalUI() = default;

  auto mostrarPantallaPrincipal();
  void mostrarHistorialCotizaciones();
  void realizarCotizacion(Vendedor &vendedor, Tienda &tienda);
  void runApp();

private:
  Presenter &presenter;

  void nuevaPantalla();
  void barra();
};
