cmake_minimum_required(VERSION 3.1)

project(ModeloTiendaRopa CXX)

set(CMAKE_CXX_STANDARD 14)

# Habilitar el soporte de Clangd para el proyecto
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=*;")
set(CMAKE_CXX_CLANG_TIDY
    clang-tidy;
    -header-filter=.;
    -checks=*;
)

# Archivos fuente del proyecto
set(SRC_LIB
    src/Model/Camisa.cpp
    src/Model/Cotizacion.cpp
    src/Model/Pantalon.cpp
    src/Model/Prenda.cpp
    src/Model/Tienda.cpp
    src/Model/Vendedor.cpp
)

# Generar la biblioteca estática a partir de los archivos fuente
add_library(${PROJECT_NAME} STATIC ${SRC_LIB} ${HEADERS})

# Establecer el directorio de salida para los archivos generados
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Agregar la carpeta 'include' para los archivos de encabezado
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Crear un archivo ejecutable para la aplicación
set(EXE_NAME MiTienda)

set(SRC_EXE
    src/main.cpp
    src/View/TerminalUI.cpp
    src/Presenter/Presenter.cpp
)

add_executable(${EXE_NAME} ${SRC_EXE})

target_include_directories(${EXE_NAME} PRIVATE src/Model src/View src/Presenter)

# Enlazar la aplicación con la biblioteca estática
target_link_libraries(${EXE_NAME} PRIVATE ${PROJECT_NAME})

# Establecer el directorio de salida para la aplicación
set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
