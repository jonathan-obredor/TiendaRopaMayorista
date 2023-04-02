@startuml

class Vendedor {
  -nombre: string
  -apellido: string
  -codigo: int
  -cotizaciones: list<Cotizacion>
  +agregarCotizacion(cotizacion: Cotizacion): void
  +obtenerCotizaciones(): list<Cotizacion>
}

class Cotizacion {
  -id: int
  -fecha: string
  -hora: string
  -codigoVendedor: int
  -prenda: Prenda
  -cantidad: int
  -resultado: float
}

class Prenda {
  -nombre: string
  -calidad: string
  -stock: int
}

Vendedor "1" *-- "*" Cotizacion
Cotizacion "1" *-- "1.." Prenda

@enduml
