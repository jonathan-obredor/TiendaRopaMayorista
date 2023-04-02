cmake_minimum_required(VERSION 3.1)

project(ModeloTiendaRopa CXX)

set(CMAKE_CXX_STANDARD 14)

# Archivos fuente del proyecto
set(SOURCES
    src/LogicaNegocio/Camisa.cpp
    src/LogicaNegocio/Cotizacion.cpp
    src/LogicaNegocio/Pantalon.cpp
    src/LogicaNegocio/Prenda.cpp
    src/LogicaNegocio/Tienda.cpp
    src/LogicaNegocio/Vendedor.cpp
)

# Generar la biblioteca estática a partir de los archivos fuente
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

# Establecer el directorio de salida para los archivos generados
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Agregar la carpeta 'include' para los archivos de encabezado
#target_include_directories(${PROJECT_NAME} PUBLIC include)

# Crear un archivo ejecutable para la aplicación
set(EXE_NAME MiTienda)
add_executable(${EXE_NAME} src/main.cpp)
target_include_directories(${EXE_NAME} PRIVATE src/LogicaNegocio)

# Enlazar la aplicación con la biblioteca estática
target_link_libraries(${EXE_NAME} PRIVATE ${PROJECT_NAME})

# Establecer el directorio de salida para la aplicación
set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
