//
// Created by igriega on 22/02/24.
//

#ifndef SOLITARIO_BARAJA_H
#define SOLITARIO_BARAJA_H

#include "Cola.h"
#include "Carta.h"
#include "Node.h"
#include "Util.h"
class Baraja {
private:
    Cola<Carta>* leftCola;
    Cola<Carta>* rightCola;
public:
    //constructor
    Baraja();
    void insert(Node<Carta>* carta);
    void showNext();
    Node<Carta>* getCurrent();
    Node<Carta>* removeCurrent();
    bool isEmpty();
};


#endif //SOLITARIO_BARAJA_H
