//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_ADMICONTAINERS_H
#define SOLITARIO_ADMICONTAINERS_H
#include "Container.h"

class AdmiContainers {
private:
    Container cHearts;
    Container cDiamonds;
    Container cTrebol;
    Container cSwords;
public:
    void saveCard(Node<Carta>* card);
    Node<Carta>* getCard(int type);
    Node<Carta>* deleteCard(int type);
};


#endif //SOLITARIO_ADMICONTAINERS_H
