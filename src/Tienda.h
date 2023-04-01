#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>
#include "Prenda.h"

class Tienda {
public:
    Tienda(const std::string& nombre, const std::string& direccion);
    void agregarPrenda(const Prenda& prenda);
    std::vector<Prenda>& obtenerPrendas();
private:
    std::string nombre;
    std::string direccion;
    std::vector<Prenda> prendas;
};

#endif // TIENDA_H
