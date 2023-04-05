#ifndef PANTALON_H
#define PANTALON_H

#include "Prenda.h"
#include <memory>

enum class TipoPantalon { Comun, Chupin };

class Pantalon : public Prenda {

public:
  Pantalon(const std::string &nombre, Calidad calidad, int cantidadEnStock,
           float precioBase, TipoPantalon tipo)
      : Prenda(nombre, calidad, cantidadEnStock, precioBase), tipo(tipo) {}

  virtual ~Pantalon() = default;

  TipoPantalon getTipoPantalon() const { return tipo; }
  void setTipoPantalon(TipoPantalon tipoPantalon) { tipo = tipoPantalon; }

  float getPrecio() const;

  std::string imprimir() const override; 

private:
  TipoPantalon tipo;
};

#endif /* PANTALON_H */
