# --- Configuración ---
CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -DINTERFACE -lsfml-graphics -lsfml-window -lsfml-system
TARGET   = disparos
SRCDIR   = src
INCDIR   = include
OBJDIR   = build

# --- Archivos ---
# Buscamos todos los .cpp
SOURCES  = $(wildcard $(SRCDIR)/*.cpp)
# Excluimos main.cpp de la generación de headers (normalmente no necesita uno)
HEADER_SRCS = $(filter-out $(SRCDIR)/main.cpp, $(SOURCES))
# Mapeamos los headers que deben existir en include/
HEADERS  = $(patsubst $(SRCDIR)/%.cpp, $(INCDIR)/%.hpp, $(HEADER_SRCS))
# Mapeamos los objetos en build/
OBJECTS  = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# --- Reglas Principales ---

all: prepare $(HEADERS) $(TARGET)

# 1. Crear carpetas necesarias
prepare:
	@mkdir -p $(INCDIR) $(OBJDIR)


# 3. Compilar el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(CXXFLAGS)

# 4. Compilar objetos (.o)
# Nota: Cada .o depende de su .cpp y de su .hpp generado
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla especial para main.o (no depende de su propio header)
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all prepare clean
