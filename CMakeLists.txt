
# CMakeLists.txt

# Especifica la versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Establece el nombre del proyecto
project(is_proyecto)

# Especifica el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Lista de archivos fuente
set(common_sources
    src/main.cpp
    src/usuarioVisitante.cpp
    src/usuarioRegistrado.cpp
    src/organizador.cpp
    src/director.cpp
    src/mail.cpp
    src/panelActividades.cpp
)

# Lista de archivos de encabezado
set(common_headers
    src/usuarioVisitante.hpp
    src/usuarioRegistrado.hpp
    src/organizador.hpp
    src/director.hpp
    src/mail.hpp
    src/panelActividades.hpp
)

# Genera la lista de archivos objeto
add_executable(programa ${common_sources} ${common_headers})

# Opciones de compilación
target_compile_options(programa PRIVATE -Wall)
