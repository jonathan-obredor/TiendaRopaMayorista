#include "Tienda.h"
#include "Camisa.h"
#include "Pantalon.h"
#include <utility>

void Tienda::agregarPrenda(const Prenda &prenda)
{
  prendas.push_back(std::move(prenda));
}

void Tienda::init() {
  // Agregar prendas a la tienda. esto se deberia leer de una base de datos
  agregarPrenda(Camisa("Camisa de cuello mao de calidad Standard manga corta", Calidad::Standard, 100, 0.0f, TipoCuello::mao, TipoManga::corta));
  agregarPrenda(Camisa("Camisa de cuello mao de calidad Premium manga corta", Calidad::Premium, 100, 0.0f, TipoCuello::mao, TipoManga::corta));

  agregarPrenda(Camisa("Camisa de cuello comun de calidad Standard manga corta", Calidad::Standard, 150, 0.0f, TipoCuello::comun, TipoManga::corta));
  agregarPrenda(Camisa("Camisa de cuello comun de calidad Premium manga corta", Calidad::Premium, 150, 0.0f, TipoCuello::comun, TipoManga::corta));

  agregarPrenda(Camisa("Camisa de cuello mao de calidad Standard manga larga", Calidad::Standard, 75, 0.0f, TipoCuello::mao, TipoManga::corta));
  agregarPrenda(Camisa("Camisa de cuello mao de calidad Premium manga larga", Calidad::Premium, 75, 0.0f, TipoCuello::mao, TipoManga::corta));

  agregarPrenda(Camisa("Camisa de cuello comun de calidad Standard manga larga", Calidad::Standard, 175, 0.0f, TipoCuello::comun, TipoManga::corta));
  agregarPrenda(Camisa("Camisa de cuello comun de calidad Premium manga larga", Calidad::Premium, 175, 0.0f, TipoCuello::comun, TipoManga::corta));

  agregarPrenda(Pantalon("Pantalon chupin de calidad Standard", Calidad::Standard, 750, 0.0f, TipoPantalon::Chupin));
  agregarPrenda(Pantalon("Pantalon chupin de calidad Premium", Calidad::Premium, 750, 0.0f, TipoPantalon::Chupin));

  agregarPrenda(Pantalon("Pantalon comun de calidad Standard", Calidad::Standard, 250, 0.0f, TipoPantalon::Comun));
  agregarPrenda(Pantalon("Pantalon comun de calidad Premium", Calidad::Premium, 250, 0.0f, TipoPantalon::Comun));
}