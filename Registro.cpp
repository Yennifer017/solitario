//
// Created by igriega on 23/02/24.
//

#include "Registro.h"

Registro::Registro(CardPosition *initial, CardPosition* final, Card* card) {
    this->initial = initial;
    this->final = final;
    this->card = card;
}

CardPosition *Registro::getInitial() {
    return this->initial;
}

CardPosition *Registro::getFinal() {
    return this->final;
}

Card *Registro::getCardInformation() {
    return card;
}
