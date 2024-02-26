//
// Created by igriega on 23/02/24.
//

#include "AdmiContainers.h"
#include "Card.h"

AdmiContainers::AdmiContainers() {
    this->cHearts = new Container(Card::HEART_SIMBOL);
    this->cDiamonds = new Container(Card::DIAMOND_SIMBOL);
    this->cSwords = new Container(Card::SWORD_SIMBOL);
    this->cTrebol = new Container(Card::TREBOL_SIMBOL);
}
void AdmiContainers::saveCard(Node<Card>*&card) {
    switch (card->getContent()->getCodeSimbol()) {
        case Card::HEART_SIMBOL :
            this->cHearts->push(card);
            break;
        case Card::SWORD_SIMBOL :
            this->cSwords->push(card);
            break;
        case Card::DIAMOND_SIMBOL:
            this->cDiamonds->push(card);
            break;
        case Card::TREBOL_SIMBOL:
            this->cTrebol->push(card);
            break;
        default:
            break;
    }
}

Container *AdmiContainers::getContainer(int type) {
    switch (type) {
        case Card::HEART_SIMBOL :return cHearts;
        case Card::SWORD_SIMBOL :return cSwords;
        case Card::DIAMOND_SIMBOL:return cDiamonds;
        case Card::TREBOL_SIMBOL:return cTrebol;
        default: return nullptr;
    }
}

std::string AdmiContainers::showContent(int type) {
    switch (type) {
        case Card::HEART_SIMBOL :
            return cHearts->peek()!= nullptr ? cHearts->peek()->getContent()->getRealValue(): " ";
        case Card::SWORD_SIMBOL :
            return cSwords->peek()!= nullptr ? cSwords->peek()->getContent()->getRealValue(): " ";
        case Card::DIAMOND_SIMBOL:
            return cDiamonds->peek()!= nullptr ? cDiamonds->peek()->getContent()->getRealValue(): " ";
        case Card::TREBOL_SIMBOL:
            return cTrebol->peek()!= nullptr ? cTrebol->peek()->getContent()->getRealValue() : " ";
        default: return "Error :c";
    }
}

bool AdmiContainers::isFull() {
    return this->cTrebol->getSize() == 13
        && this->cDiamonds->getSize() == 13
        && this->cSwords->getSize() == 13
        && this->cHearts->getSize() == 13;
}

bool AdmiContainers::canSave(Node<Card>* &card) {
    return cHearts->canPush(card)
           || cDiamonds->canPush(card)
           || cTrebol->canPush(card)
           || cSwords->canPush(card);
}



