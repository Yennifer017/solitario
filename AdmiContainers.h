//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_ADMICONTAINERS_H
#define SOLITARIO_ADMICONTAINERS_H
#include "Container.h"

class AdmiContainers {
private:
    Container* cHearts;
    Container* cDiamonds;
    Container* cTrebol;
    Container* cSwords;
public:
    AdmiContainers();
    void saveCard(Node<Carta>* card);
    Container* getContainer(int type);
};


#endif //SOLITARIO_ADMICONTAINERS_H
