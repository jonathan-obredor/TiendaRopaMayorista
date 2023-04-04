#include "Vendedor.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

void Vendedor::nuevaCotizacion(const std::string &nombre, int cantidad,
                               float precioUnitario) {
  // Obtenemos el tiempo actual
  std::time_t t = std::time(nullptr);

  // Obtenemos la estructura tm local
  std::tm tm = *std::localtime(&t);

  // Creamos un buffer para guardar la hora formateada
  char buffer[80];

  // Formateamos la hora usando strftime
  std::strftime(buffer, sizeof(buffer), "%H:%M:%S", &tm);

  // Convertimos el buffer en una std::string
  std::string horaActual(buffer);

  // Creamos un stringstream para guardar la fecha formateada
  std::stringstream fecha_stream;

  // Formateamos la fecha usando el stringstream
  fecha_stream << (tm.tm_year + 1900) << "-" << std::setfill('0')
               << std::setw(2) << (tm.tm_mon + 1) << "-" << std::setfill('0')
               << std::setw(2) << tm.tm_mday;

  // Convertimos el stringstream en una std::string
  std::string fechaActual = fecha_stream.str();

  cotizaciones_.emplace_back(
      std::move(Cotizacion(cotizaciones_.size(), horaActual, fechaActual,
                           nombre, cantidad, precioUnitario)));
}
