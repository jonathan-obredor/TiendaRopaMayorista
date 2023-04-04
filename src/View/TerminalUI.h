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
  explicit TerminalUI(Presenter &myPresenter) : presenter(myPresenter) {
    nombreBuscado = "";
  }

  virtual ~TerminalUI() = default;

  auto menuPrincipal();
  void mostrarHistorialCotizaciones();
  void realizarCotizacion();
  void runApp();

private:
  Presenter &presenter;
  std::string nombreBuscado;
  void cuello();
  void nuevaPantalla();
  void barra();
  void enterParaContinuar();
};
