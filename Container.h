//
// Created by igriega on 22/02/24.
//

#ifndef SOLITARIO_CONTAINER_H
#define SOLITARIO_CONTAINER_H

#include "Carta.h"
#include "Stack.h"
#include "Node.h"
#include "Util.h"
class Container: public Stack<Carta> {
private:
    int codeSimbol;
    Util* util;
public:
    //constructor
    Container(int codeSimbol);

    //reescritura de metodos
    void push(Node<Carta>* &node);
};


#endif //SOLITARIO_CONTAINER_H
