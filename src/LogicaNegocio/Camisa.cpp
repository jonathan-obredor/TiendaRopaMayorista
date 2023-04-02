#include "Camisa.h"

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

float Camisa::getPrecio() const
{
    float precioBase = Prenda::getPrecio();

    if (m_manga == TipoManga::corta)
    {
        precioBase *= 0.9f;
    }

    if (m_cuello == TipoCuello::mao)
    {
        precioBase *= 1.03f;
    }
    if (calidad == Calidad::Premium)
    {
        precioBase *= 1.3; // se aumenta 30%
    }

    return precioBase;
}
