@startuml

class Tienda {
  -nombre: string
  -direccion: string
  -prendas: list<Prenda>
}

class Prenda {
    -calidad: string
    -cantidadEnStock: int
    +getCalidad(): string
    +setCalidad(calidad: string): void
    +getCantidadEnStock(): int
    +setCantidadEnStock(cantidad: int): void
}

Tienda "1" --> "0..*" Prenda
Vendedor "1" -- "0..*" Tienda

@enduml
