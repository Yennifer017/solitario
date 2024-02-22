//
// Created by igriega on 22/02/24.
//

#ifndef SOLITARIO_BARAJA_H
#define SOLITARIO_BARAJA_H

#include "Cola.h"
#include "Carta.h"
#include "Node.h"
class Baraja {
private:
    Cola<Carta>* leftContainer;
    Cola<Carta>* rightContainer;
    Carta* currentCarta;
    void restart();
public:
    void showNext();
    Node<Carta>* getCurrent();
    Node<Carta>* removeCurrent();
    bool isEmpty();
    void insert(Node<Carta>* carta);

};


#endif //SOLITARIO_BARAJA_H
