//
// Created by igriega on 23/02/24.
//

#include "AdmiGameSpaces.h"
AdmiGameSpaces::AdmiGameSpaces() {
    for (int i = 0; i < TOTAL_GAMESPACES; i++) {
        gameSpaces[i] = new GameSpace();
    }

}
void AdmiGameSpaces::addCard(Node<Card>* card) {
    for (int i = 0; i < TOTAL_GAMESPACES; ++i) {
        if(gameSpaces[i]->getSize()<=i){
            gameSpaces[i]->insertLast(card);
            if(gameSpaces[i]->getSize() == i+1){
                card->getContent()->setReveal(true);
            }
            break;
        }
    }
}

GameSpace *AdmiGameSpaces::getGameSpace(int number) {
    return gameSpaces[number];
}

bool AdmiGameSpaces::isInitialFull() {
    int totalCards = 0;
    for (int i = 0; i < TOTAL_GAMESPACES; ++i) {
        totalCards += gameSpaces[i]->getSize();
    }
    return totalCards >= 28;
}

void AdmiGameSpaces::addCard(Card *card) {
    Node<Card>* nodeCard = new Node<Card>(card);
    this->addCard(nodeCard);
}

std::string AdmiGameSpaces::showAllContent(int gameSpaceNumber, bool withNumbers) {
    std::string content;
    if(!gameSpaces[gameSpaceNumber]->isEmpty()){
        int counter = 1;
        Node<Card>* current = gameSpaces[gameSpaceNumber]->get(0);
        content += withNumbers ? std::to_string(counter) + "=[" : "[";
        content += current->getContent()->showInformation();
        content += "] ";
        while (current->getNext() != nullptr){
            counter++;
            current = current->getNext();
            content += withNumbers ? std::to_string(counter) + "=[" : "[";
            content += current->getContent()->showInformation();
            content += "] ";
        }
    }else{
        content = "__vacio__";
    }

    return content;
}

std::string AdmiGameSpaces::showContent(int gameSpaceNumber, bool withNumbers) {
    std::string content;
    if(!gameSpaces[gameSpaceNumber]->isEmpty()){
        int counter = 1;
        Node<Card>* current = gameSpaces[gameSpaceNumber]->get(0);
        content += withNumbers ? std::to_string(counter) + "=[" : "[";
        content += current->getContent()->isReveal() ?
                current->getContent()->showInformation() : "  X ";
        content += "] ";
        while (current->getNext() != nullptr){
            counter++;
            current = current->getNext();
            content += withNumbers ? std::to_string(counter) + "=[" : "[";
            content += current->getContent()->isReveal() ?
                    current->getContent()->showInformation() : "  X ";
            content += "] ";
        }
    }else{
        content = "__vacio__";
    }

    return content;
}




