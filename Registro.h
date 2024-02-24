//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_REGISTRO_H
#define SOLITARIO_REGISTRO_H
#include "CardPosition.h"
#include "Card.h"
class Registro {
private:
    CardPosition* initial;
    CardPosition* final;
    Card* card;
public:
    Registro(CardPosition* initial, CardPosition* final, Card* card);
    //getter
    CardPosition* getInitial();
    CardPosition* getFinal();
    Card* getCardInformation();
};


#endif //SOLITARIO_REGISTRO_H
