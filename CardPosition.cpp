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

void CardPosition::setPrimaryCode(int code) {
    this->primaryCode = code;
}

void CardPosition::setSecondaryCode(int code) {
    this->secondaryCode = code;
}
