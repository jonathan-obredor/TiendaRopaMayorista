#include "Camisa.h"
#include "Pantalon.h"
#include "Presenter.h"
#include "TerminalUI.h"
#include "Tienda.h"
#include <iostream>

int main() {
  Tienda tienda("Mi Tienda", "Calle Falsa 123");
  Vendedor vendedor("Juan", "Pérez", 1234);

  Presenter presenter(tienda, vendedor);
  TerminalUI myUI(presenter);

  myUI.runApp();

  tienda.init();

  return 0;
}