#ifndef PANTALON_H
#define PANTALON_H

#include <memory>
#include "Prenda.h"

enum class TipoPantalon
{
    comunes,
    chupines
};

class Pantalon : public Prenda
{
public:
    Pantalon() = default;
    Pantalon(const std::string& nombre, Calidad calidad, int cantidadEnStock, TipoPantalon tipo);
    virtual ~Pantalon() = default;

    TipoPantalon getTipoPantalon() const { return tipoPantalon_; }
    void setTipoPantalon(TipoPantalon tipoPantalon) { tipoPantalon_ = tipoPantalon; }

private:
    TipoPantalon tipoPantalon_;
};

#endif /* PANTALON_H */
