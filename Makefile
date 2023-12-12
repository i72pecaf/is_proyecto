# Makefile

# Especifica el compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -Wall

# Lista de archivos fuente
SOURCES = main.cpp

# Genera la lista de archivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Nombre del ejecutable
EXECUTABLE = programa.exe

# Regla por defecto para construir el programa
all: $(EXECUTABLE)

# Regla para construir el ejecutable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Regla para construir archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

