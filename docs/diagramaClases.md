@startuml

title Business Model

class Vendedor implements Imprimible {
  -nombre_: std::string
  -apellido_: std::string
  -codigo_: int
  -cotizaciones_: std::vector<Cotizacion>
  +nuevaCotizacion(nombre: std::string, cantidad: int, precioUnitario: float): void
  +obtenerCotizaciones() const: const std::vector<Cotizacion>&
  +getNombreCompleto() const: std::string
  +getCodigo() const: int

  + imprimir(): string
}

class Cotizacion implements Imprimible {
  - idCotizacion: int
  - fecha_: string
  - hora_: string
  - nombrePrenda: string
  - cantidad_: int
  - precioUnitario: float
  + Cotizacion(id: int, fecha: string, hora: string, nombreP: string, cantidad: int, precioUnitario: float)
  + Cotizacion(other: Cotizacion&&) noexcept
  
  + getId(): int
  + getFecha(): string
  + getHora(): string
  + getCantidad(): int
  + getPrecioFinal(): float

  + imprimir(): string
}

class Tienda implements Imprimible {
  -nombre: std::string
  -direccion: std::string
  -prendas: std::vector<Prenda>
  -vendedores: std::vector<Vendedor>

  +Tienda(nombre: const std::string&, direccion: const std::string&)
  +init(): void
  +getPrendas(): std::vector<Prenda>&
  +getNombre(): const std::string&
  +getDireccion(): const std::string&
  +buscarPrenda(nombre: const std::string&): auto
  +getStockPrenda(nombre: const std::string&): int
  +getCodigoVendedor(): int
  +mostrarPrendas(): void
  +nuevaCotizacion(nombreBuscado: const std::string&, cantidad: int, precioUnitario: float): int
  +obtenerCotizaciones(): const std::vector<Cotizacion>&

  + imprimir(): string
}

interface Imprimible {
  +imprimir() const: string
}

class Prenda implements Imprimible {
  - nombre: string
  - calidad: Calidad
  - cantidadEnStock: int
  - precio: float

  + Prenda(nombre: string, calidad: Calidad = Calidad.Standard, cantidadEnStock: int = 0, precio: float = 0.0f)
  ~ Prenda()
  + Prenda(other: Prenda)
  + getCalidad(): Calidad
  + setCalidad(calidad: Calidad): void
  + getCantidadEnStock(): int
  + setCantidadEnStock(cantidadEnStock: int): void
  + descontarStock(cantidad: int): void
  + getNombre(): string
  + getPrecio(): float

  + imprimir(): string
}

class Pantalon extends Prenda {
    -tipo: TipoPantalon
    +getTipoPantalon(): TipoPantalon
    +setTipoPantalon(tipoPantalon: TipoPantalon): void
    +getPrecio(): float
}

class Camisa extends Prenda {
    -cuello: TipoCuello
    -manga: TipoManga
    +getCuello(): TipoCuello
    +setCuello(cuello: TipoCuello): void
    +getManga(): TipoManga
    +setManga(manga: TipoManga): void
}

enum Calidad {
    standard
    premium
}

enum TipoPantalon {
    comunes
    chupines
}

enum TipoCamisa {
    mangaLarga
    mangaCorta
}

enum TipoCuello {
    mao
    comun
}

enum TipoManga {
    larga
    corta
}

Vendedor "1" *-- "*" Cotizacion
Cotizacion "1" *-- "1.." Prenda

Tienda "1" *-- "0..*" Prenda
Tienda "1" *-- "1" Vendedor

@enduml
