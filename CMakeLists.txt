cmake_minimum_required(VERSION 3.1)

project(mi_proyecto CXX)

set(CMAKE_CXX_STANDARD 14)

# Archivos fuente del proyecto
set(SOURCES
    src/Camisa.cpp
    src/Cotizacion.cpp
    src/Pantalon.cpp
    src/Prenda.cpp
    src/Vendedor.cpp
    src/Tienda.cpp
)

# Archivos de encabezado del proyecto
set(HEADERS
    src/Camisa.h
    src/Cotizacion.h
    src/Pantalon.h
    src/Prenda.h
    src/Vendedor.h
    src/Tienda.h
)

# Generar la biblioteca estática a partir de los archivos fuente
add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

# Establecer el directorio de salida para los archivos generados
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Agregar la carpeta 'include' para los archivos de encabezado
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Crear un archivo ejecutable para la aplicación
add_executable(mi_aplicacion src/main.cpp)

# Enlazar la aplicación con la biblioteca estática
target_link_libraries(mi_aplicacion PRIVATE ${PROJECT_NAME})

# Establecer el directorio de salida para la aplicación
set_target_properties(mi_aplicacion PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
