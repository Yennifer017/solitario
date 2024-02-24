//
// Created by igriega on 23/02/24.
//

#include "CardPosition.h"

CardPosition::CardPosition(int _placeCode, int _secondaryCode) {
    this->primaryCode = _placeCode;
    this->secondaryCode = _secondaryCode;
}
int CardPosition::getSecondaryCode() {
    return this->secondaryCode;
}

int CardPosition::getPrimaryCode() {
    return this->primaryCode;
}
