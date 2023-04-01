#include "Camisa.h"

Camisa::Camisa(const std::string& nombre, Calidad calidad, int stock, TipoCuello cuello, TipoManga manga)
    : Prenda(nombre, calidad, stock), m_cuello(cuello), m_manga(manga)
{}

TipoCuello Camisa::getCuello() const
{
    return m_cuello;
}

void Camisa::setCuello(TipoCuello cuello)
{
    m_cuello = cuello;
}

TipoManga Camisa::getManga() const
{
    return m_manga;
}

void Camisa::setManga(TipoManga manga)
{
    m_manga = manga;
}
