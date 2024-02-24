cmake_minimum_required(VERSION 3.27)
project(solitario)

set(CMAKE_CXX_STANDARD 17)

add_executable(solitario main.cpp
        Stack.h
        Node.h
        Cola.h
        LinkedList.h
        Card.cpp
        Card.h
        Baraja.cpp
        Baraja.h
        Container.cpp
        Container.h
        Util.cpp
        Util.h
        CartaOrderException.h
        AdmiContainers.cpp
        AdmiContainers.h
        GameSpace.cpp
        GameSpace.h
        AdmiGameSpaces.cpp
        AdmiGameSpaces.h
        CardPosition.cpp
        CardPosition.h
        Registro.cpp
        Registro.h
        AdmiMoves.cpp
        AdmiMoves.h
        Solitaire.cpp
        Solitaire.h
)
