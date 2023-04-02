#ifndef COTIZACION_H
#define COTIZACION_H

#include <memory>
#include "Prenda.h"

class Cotizacion
{
public:
    Cotizacion(int id, const std::string &fecha, const std::string &hora, int codigoVendedor, std::shared_ptr<Prenda> prenda, int cantidad, float resultado)
        : id_(id), fecha_(fecha), hora_(hora), codigoVendedor_(codigoVendedor), prenda_(prenda), cantidad_(cantidad), resultado_(resultado)
    {
    }
    virtual ~Cotizacion() = default;
    void imprimir();
    const std::shared_ptr<Prenda> &obtenerPrenda() const { return prenda_; }
    int getId() const { return id_; }
    const std::string &getFecha() const { return fecha_; }
    const std::string &getHora() const { return hora_; }
    // const std::string &getDescripcionPrenda() const { return prenda_->getDescripcion(); } //TODO implementar en las 3 clases
    int getCantidad() const { return cantidad_; }
    float getPrecioFinal() const;

private:
    int id_;
    std::string fecha_;
    std::string hora_;
    int codigoVendedor_;
    std::shared_ptr<Prenda> prenda_;
    int cantidad_;
    float resultado_;
};

#endif // COTIZACION_H
