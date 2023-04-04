#include "Camisa.h"
#include "Pantalon.h"
#include "Presenter.h"
#include "TerminalUI.h"
#include "Tienda.h"
#include <iostream>

int main() {
  Tienda tienda("Mi Tienda", "Calle Falsa 123");
  tienda.init();
  Presenter presenter(tienda);
  TerminalUI myUI(presenter);
  myUI.runApp();
  return 0;
}