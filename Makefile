CXX = g++               # El compilador de C++
CXXFLAGS = -I./extensiones   # Incluir directorios de cabecera (archivos .h)
LDFLAGS =  -lportaudio    # Flags para el enlazador (si necesitas)
SRC = portaudio_test.cpp # Archivos fuente .cpp
OBJ = $(SRC:.cpp=.o)     # Archivos objeto generados a partir de los .cpp
OUT = programa           # El nombre del archivo ejecutable

all: $(OUT)
	 rm -f $(OBJ)

$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $(OUT) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)

hola:
	g++ holaMundo.cpp -o holamundo2 -I./extensiones 

portaudio:
	g++ portaudio_test.cpp -o pa_test -lportaudio
