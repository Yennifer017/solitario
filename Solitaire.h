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
    Util* util;
    Baraja* baraja;

    void inicializar();
    bool checkWinner();
    void printGame();
    void moveCards();

    void moveFromSpace();
    void moveFromBaraja();
    void moveFromContainer();

    int moveToSpace(Node<Card>* &cardNode);
    CardPosition* tryMoveOneCard(Node<Card>* &cardNode);

public:
    Solitaire();
    void play();
};


#endif //SOLITARIO_SOLITAIRE_H
