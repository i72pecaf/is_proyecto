# CMakeLists.txt

# Especifica la versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Establece el nombre del proyecto
project(is_proyecto)

# Especifica el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Lista de archivos fuente comunes
set(common_sources
    src/main.cpp
    src/usuarioVisitante.cpp
    src/usuarioRegistrado.cpp
    src/organizador.cpp
    src/director.cpp
    src/mail.cpp
    src/panelActividades.cpp
)

# Lista de archivos de encabezado comunes
set(common_headers
    src/usuarioVisitante.hpp
    src/usuarioRegistrado.hpp
    src/organizador.hpp
    src/director.hpp
    src/mail.hpp
    src/panelActividades.hpp
)

# Genera la lista de archivos objeto para el ejecutable principal
add_executable(programa ${common_sources} ${common_headers})

# Opciones de compilación para el ejecutable principal
target_compile_options(programa PRIVATE -Wall)

# Configuración de Google Test
# Asume que ya configuraste Google Test en lib/googletest/
include_directories(lib/googletest/include)
add_subdirectory(lib/googletest)

# Lista de archivos fuente para las pruebas
# Cuidado de no incluir el main o se lanzara el programa principal
set(test_sources
    tests/test_historia_1.cpp
    tests/test_historia_2.cpp
    tests/test_historia_3.cpp

    src/usuarioVisitante.cpp
    src/usuarioRegistrado.cpp
    src/organizador.cpp
    src/director.cpp
    src/mail.cpp
    src/panelActividades.cpp
)

# Genera el ejecutable de pruebas
add_executable(test_ejecutable ${test_sources} ${common_headers})

# Enlaza con Google Test y otras bibliotecas necesarias
target_link_libraries(test_ejecutable gtest_main)

# Opciones de compilación para el ejecutable de pruebas
target_compile_options(test_ejecutable PRIVATE -Wall)
