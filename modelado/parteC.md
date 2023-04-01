@startuml

abstract class Prenda {
    - Calidad calidad
    - int unidadesEnStock
}

class Pantalon {
    -tipo: string
    +getTipo(): string
    +setTipo(tipo: string): void
}

class Camisa {
    -tipo: string
    -cuello: string
    +getTipo(): string
    +setTipo(tipo: string): void
    +getCuello(): string
    +setCuello(cuello: string): void
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

Prenda <|-- Camisa
Prenda <|-- Pantalon

@enduml
