//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_UTIL_H
#define SOLITARIO_UTIL_H

#include "Card.h"

class Util {
public:
    int getNumber();
    int getNaturalNumber(int min, int max);
    bool isSecuential(Card* inicial, Card* final);
    bool isAnotherColor(Card* inicial, Card* final);
    bool isSameSimbol(Card* inicial, Card* final);
};


#endif //SOLITARIO_UTIL_H
