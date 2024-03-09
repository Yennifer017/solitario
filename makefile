#variable global de compilador de c++
CPP = g++
#definiendo el programa final
TARGET = compiled_solitaire

#compilar el programa principal, se declaran las dependencias (todos los archivos)
all: .all-post

.all-post: AdmiContainers.o AdmiGameSpaces.o AdmiMoves.o Baraja.o Card.o CardPosition.o CartaOrderException.o Cola.o Container.o GameSpace.o LinkedList.o main.o Node.o Registro.o Solitaire.o Stack.o Util.o
	$(CPP) AdmiContainers.o AdmiGameSpaces.o AdmiMoves.o Baraja.o Card.o CardPosition.o CartaOrderException.o Cola.o Container.o GameSpace.o LinkedList.o main.o Node.o Registro.o Solitaire.o Stack.o Util.o -o $(TARGET)

AdmiContainers.o: AdmiContainers.cpp AdmiContainers.h
	$(CPP) -c AdmiContainers.cpp
	
AdmiGameSpaces.o: AdmiGameSpaces.cpp AdmiGameSpaces.h
	$(CPP) -c AdmiGameSpaces.cpp
	
AdmiMoves.o: AdmiMoves.cpp AdmiMoves.h
	$(CPP) -c AdmiMoves.cpp
	
Baraja.o: Baraja.cpp Baraja.h
	$(CPP) -c Baraja.cpp
	
Card.o: Card.cpp Card.h
	$(CPP) -c Card.cpp
	
CardPosition.o: CardPosition.cpp CardPosition.h
	$(CPP) -c CardPosition.cpp

CartaOrderException.o: CartaOrderException.h 
	touch CartaOrderException.o
Cola.o: Cola.h
	touch Cola.o

Container.o: Container.cpp Container.h
	$(CPP) -c Container.cpp
 
GameSpace.o: GameSpace.cpp GameSpace.h
	$(CPP) -c GameSpace.cpp
 
 
LinkedList.o: LinkedList.h
	touch LinkedList.o

main.o: 
	$(CPP) -c main.cpp
 
 
Node.o: Node.h
	touch Node.o

Registro.o: Registro.cpp Registro.h
	$(CPP) -c Registro.cpp
 
Solitaire.o: Solitaire.cpp Solitaire.h
	$(CPP) -c Solitaire.cpp
 
Stack.o: Stack.h
	touch Stack.o

Util.o: Util.cpp Util.h
	$(CPP) -c Util.cpp


# tener un comando para eliminar todos los archivos .o generados
clean:
	rm -f *.o $(TARGET)
