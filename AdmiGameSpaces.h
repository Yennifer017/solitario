//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_ADMIGAMESPACES_H
#define SOLITARIO_ADMIGAMESPACES_H
#include "GameSpace.h"

class AdmiGameSpaces {
private:
    GameSpace* gSpace0,* gSpace1,* gSpace2,* gSpace3,* gSpace4,* gSpace5,* gSpace6;
    int counterInitialCards;
public:
    void addCard(Node<Carta>* card);
    GameSpace* getGameSpace(int number);
    int getCounterInitialCards();
};


#endif //SOLITARIO_ADMIGAMESPACES_H
