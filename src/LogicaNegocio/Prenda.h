#ifndef PRENDA_H
#define PRENDA_H

#include <string>

enum class Calidad
{
    Standard,
    Premium
};

class Prenda
{
public:
    Prenda(const std::string &nombre, Calidad calidad = Calidad::Standard, int cantidadEnStock = 0, float precio = 0.0f)
        : nombre(nombre), calidad(calidad), cantidadEnStock(cantidadEnStock), precio(precio)
    {
    }
    virtual ~Prenda() = default;
    Calidad getCalidad() const
    {
        return calidad;
    }
    void setCalidad(Calidad calidad)
    {
        this->calidad = calidad;
    }
    int getCantidadEnStock() const
    {
        return cantidadEnStock;
    }
    void setCantidadEnStock(int unidadesEnStock)
    {
        cantidadEnStock = unidadesEnStock;
    }

    const float& getPrecio() const
    {
        return precio;
    }
    // void setPrecio(float precio);

protected:
    Calidad calidad;

private:
    float precio;
    std::string nombre;
    int cantidadEnStock;
};

#endif // PRENDA_H
