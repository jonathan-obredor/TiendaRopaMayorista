#ifndef CAMISA_H
#define CAMISA_H

#include "Prenda.h"

enum class TipoCuello
{
    mao,
    comun
};

enum class TipoManga
{
    larga,
    corta
};

class Camisa : public Prenda
{
public:
    // Camisa(const std::string& nombre, const std::string& calidad, int stock, TipoCuello cuello, TipoManga manga);

    Camisa(const std::string &nombre, Calidad calidad, int stock, TipoCuello cuello, TipoManga manga);

    TipoCuello getCuello() const;
    void setCuello(TipoCuello cuello);

    TipoManga getManga() const;
    void setManga(TipoManga manga);

private:
    TipoCuello m_cuello;
    TipoManga m_manga;
};

#endif // CAMISA_H
