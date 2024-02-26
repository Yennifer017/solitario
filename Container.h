//
// Created by igriega on 22/02/24.
//

#ifndef SOLITARIO_CONTAINER_H
#define SOLITARIO_CONTAINER_H

#include "Card.h"
#include "Stack.h"
#include "Node.h"
#include "Util.h"
class Container: public Stack<Card> {
private:
    int codeSimbol;
    Util* util;
public:
    //constructor
    Container(int codeSimbol);

    //reescritura de metodos
    void push(Node<Card>* &node);
    bool canPush(Node<Card>* &node);
};


#endif //SOLITARIO_CONTAINER_H
