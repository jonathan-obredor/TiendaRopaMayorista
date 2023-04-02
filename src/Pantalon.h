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
    Pantalon() = default;
    Pantalon(const std::string &nombre, Calidad calidad, int cantidadEnStock, TipoPantalon tipo);
    virtual ~Pantalon() = default;

    TipoPantalon getTipoPantalon() const { return tipo; }
    void setTipoPantalon(TipoPantalon tipoPantalon) { tipo = tipoPantalon; }

    float getPrecio() const override;

private:
    TipoPantalon tipo;
};

#endif /* PANTALON_H */
