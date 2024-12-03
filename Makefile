CC=g++
INCLUDE_FLAGS=-I. -lglut -lGLU -lGLEW -lGL -lSOIL
DEBUG_FLAGS=-g

OUTPUT_NAME=game

all:  src/main.cpp 
	$(CC) -o ${OUTPUT_NAME} src/*.cpp $(INCLUDE_FLAGS) ${DEBUG_FLAGS}

run: all
	./${OUTPUT_NAME}

clean:
	rm ./${OUTPUT_NAME}	
