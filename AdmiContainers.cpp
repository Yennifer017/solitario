//
// Created by igriega on 23/02/24.
//

#include "AdmiContainers.h"
#include "Card.h"
#include "CardPosition.h"

AdmiContainers::AdmiContainers() {
    this->cHearts = new Container(Card::HEART_SIMBOL);
    this->cDiamonds = new Container(Card::DIAMOND_SIMBOL);
    this->cSwords = new Container(Card::SWORD_SIMBOL);
    this->cTrebol = new Container(Card::TREBOL_SIMBOL);
}
int AdmiContainers::saveCard(Node<Card>*&card) {
    switch (card->getContent()->getCodeSimbol()) {
        case Card::HEART_SIMBOL :
            this->cHearts->push(card);
            return CardPosition::HEART_CONTAINER;
        case Card::SWORD_SIMBOL :
            this->cSwords->push(card);
            return CardPosition::SWORD_CONTAINER;
        case Card::DIAMOND_SIMBOL:
            this->cDiamonds->push(card);
            return CardPosition::DIAMONDS_CONTAINER;
        case Card::TREBOL_SIMBOL:
            this->cTrebol->push(card);
            return CardPosition::TREBOL_CONTAINER;
        default:
            return -1;
    }
}

/*Container *AdmiContainers::getContainer(int type) {
    switch (type) {
        case Card::HEART_SIMBOL :return cHearts;
        case Card::SWORD_SIMBOL :return cSwords;
        case Card::DIAMOND_SIMBOL:return cDiamonds;
        case Card::TREBOL_SIMBOL:return cTrebol;
        default: return nullptr;
    }
}*/

Container *AdmiContainers::getContainer(int type) {
    switch (type) {
        case CardPosition::HEART_CONTAINER :return cHearts;
        case CardPosition::SWORD_CONTAINER :return cSwords;
        case CardPosition::DIAMONDS_CONTAINER:return cDiamonds;
        case CardPosition::TREBOL_CONTAINER:return cTrebol;
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



