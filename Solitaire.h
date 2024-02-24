//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_SOLITAIRE_H
#define SOLITARIO_SOLITAIRE_H
#include "AdmiContainers.h"
#include "AdmiGameSpaces.h"
#include "AdmiMoves.h"
#include "Baraja.h"

class Solitaire {
private:
    AdmiContainers* admiContainers;
    AdmiGameSpaces* admiSpaces;
    AdmiMoves* admiMoves;
    Baraja* baraja;

    void inicializar();
public:
    Solitaire();
    void printGame();
    void play();
};


#endif //SOLITARIO_SOLITAIRE_H
