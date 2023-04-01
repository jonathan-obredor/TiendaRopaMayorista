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
    Prenda(const std::string &nombre, Calidad calidad, int cantidadEnStock);
    virtual ~Prenda() = default;

    Calidad getCalidad() const;
    void setCalidad(Calidad calidad);
    int getUnidadesEnStock() const;
    void setUnidadesEnStock(int unidadesEnStock);

private:
    //Calidad calidad_;
    std::string nombre;
    Calidad calidad;
    int cantidadEnStock;
};

#endif // PRENDA_H
