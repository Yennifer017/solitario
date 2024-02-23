//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_UTIL_H
#define SOLITARIO_UTIL_H

#include "Carta.h"

class Util {
public:
    int getNumber();
    int getNaturalNumber(int min, int max);
    bool isSecuential(Carta* inicial, Carta* final);
    bool isAnotherColor(Carta* inicial, Carta* final);
    bool isSameSimbol(Carta* inicial, Carta* final);
};


#endif //SOLITARIO_UTIL_H
