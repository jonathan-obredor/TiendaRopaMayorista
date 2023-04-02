#ifndef PANTALON_H
#define PANTALON_H

#include <memory>
#include "Prenda.h"

enum class TipoPantalon
{
    Comun,
    Chupin
};

class Pantalon : public Prenda
{
public:
    Pantalon(const std::string &nombre, Calidad calidad, int cantidadEnStock, float precioBase, TipoPantalon tipo)
        : Prenda(nombre, calidad, cantidadEnStock, precioBase), tipo(tipo)
    {
    }

    virtual ~Pantalon() = default;

    TipoPantalon getTipoPantalon() const { return tipo; }
    void setTipoPantalon(TipoPantalon tipoPantalon) { tipo = tipoPantalon; }

    float getPrecio() const;

private:
    TipoPantalon tipo;
};

#endif /* PANTALON_H */
