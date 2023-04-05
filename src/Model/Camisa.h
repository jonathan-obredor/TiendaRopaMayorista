#ifndef CAMISA_H
#define CAMISA_H

#include "Prenda.h"
#include <string>

enum class TipoCuello { mao, comun };
enum class TipoManga { larga, corta };

class Camisa : public Prenda {
public:
  Camisa(const std::string &nombre, Calidad calidad = Calidad::Standard,
         int cantidadEnStock = 0, float precio = 0.0f,
         TipoCuello cuello = TipoCuello::comun,
         TipoManga manga = TipoManga::corta)
      : Prenda(nombre, calidad, cantidadEnStock, precio), m_cuello(cuello),
        m_manga(manga) {}

  virtual ~Camisa() = default;

  TipoCuello getCuello() const;
  void setCuello(TipoCuello cuello);

  TipoManga getManga() const;
  void setManga(TipoManga manga);

  float getPrecio() const;

  std::string imprimir() const override {
    std::string out = Prenda::imprimir();
    out += "Camisa: , Cuello: ";
    out += (getCuello() == TipoCuello::mao ? "Mao" : "Comun");
    out += ", Manga: ";
    out += (getManga() == TipoManga::larga ? "Larga" : "Corta");
    return out;
  }

private:
  TipoCuello m_cuello;
  TipoManga m_manga;
};

#endif // CAMISA_H
