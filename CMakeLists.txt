# CMakeLists.txt

# Especifica la versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Establece el nombre del proyecto
project(is_proyecto)

# Especifica el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Lista de archivos fuente
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.hpp")

# Genera la lista de archivos objeto
add_executable(programa.exe ${SOURCES} ${HEADERS})

# Opciones de compilación
target_compile_options(programa.exe PRIVATE -Wall)
