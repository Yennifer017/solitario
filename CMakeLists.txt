cmake_minimum_required(VERSION 3.27)
project(solitario)

set(CMAKE_CXX_STANDARD 17)

add_executable(solitario main.cpp
        Stack.h
        Node.h
        Cola.h
        LinkedList.h
        Carta.cpp
        Carta.h
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
)
