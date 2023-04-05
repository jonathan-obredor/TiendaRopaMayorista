#ifndef IMPRIMIBLE_H
#define IMPRIMIBLE_H

#include <string>

class Imprimible {
public:
  virtual std::string imprimir() const = 0;
  virtual ~Imprimible() {}
};

#endif // IMPRIMIBLE_H