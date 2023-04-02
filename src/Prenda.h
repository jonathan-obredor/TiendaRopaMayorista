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

    Calidad getCalidad() const;
    void setCalidad(Calidad calidad);

    int getUnidadesEnStock() const;
    void setUnidadesEnStock(int unidadesEnStock);

    virtual float getPrecio() const;
    void setPrecio(float precio); // TODO implementar aca o en camisa y pantalon??

protected:
    Calidad calidad;

private:
    float precio;
    std::string nombre;

    int cantidadEnStock;
};

#endif // PRENDA_H
