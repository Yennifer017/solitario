//
// Created by igriega on 23/02/24.
//

#include "AdmiContainers.h"
#include "Carta.h"

AdmiContainers::AdmiContainers() {
    this->cHearts = new Container(Carta::HEART_SIMBOL);
    this->cDiamonds = new Container(Carta::DIAMOND_SIMBOL);
    this->cSwords = new Container(Carta::SWORD_SIMBOL);
    this->cTrebol = new Container(Carta::TREBOL_SIMBOL);
}
void AdmiContainers::saveCard(Node<Carta> *card) {
    switch (card->getContent()->getCodeSimbol()) {
        case Carta::HEART_SIMBOL :
            this->cHearts->push(card);
            break;
        case Carta::SWORD_SIMBOL :
            this->cSwords->push(card);
            break;
        case Carta::DIAMOND_SIMBOL:
            this->cDiamonds->push(card);
            break;
        case Carta::TREBOL_SIMBOL:
            this->cTrebol->push(card);
            break;
        default:
            break;
    }
}

Container *AdmiContainers::getContainer(int type) {
    switch (type) {
        case Carta::HEART_SIMBOL :return cHearts;
        case Carta::SWORD_SIMBOL :return cSwords;
        case Carta::DIAMOND_SIMBOL:return cDiamonds;
        case Carta::TREBOL_SIMBOL:return cTrebol;
        default: return nullptr;
    }
}


