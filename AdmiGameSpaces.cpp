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
    /*if(gSpace0->getSize()<0){
        gSpace0->insertLast(card);
    }else if(gSpace1->getSize()<1){
        gSpace1->insertLast(card);
    }else if(gSpace2->getSize()<2){
        gSpace2->insertLast(card);
    }else if(gSpace3->getSize()<3){
        gSpace3->insertLast(card);
    }else if(gSpace4->getSize()<4){
        gSpace4->insertLast(card);
    }else if(gSpace5->getSize()<5){
        gSpace5->insertLast(card);
    }else if(gSpace6->getSize()<6){
        gSpace6->insertLast(card);
    }else {
        return;
    }*/
}

GameSpace *AdmiGameSpaces::getGameSpace(int number) {
    /*switch (number) {
        case 0: return this->gSpace0;
        case 1: return this->gSpace1;
        case 2: return this->gSpace2;
        case 3: return this->gSpace3;
        case 4: return this->gSpace4;
        case 5: return this->gSpace5;
        case 6: return this->gSpace6;
        default: return nullptr;
    }*/
    return gameSpaces[number];
}

bool AdmiGameSpaces::isInitialFull() {
    int totalCards = 0;
    for (int i = 0; i < TOTAL_GAMESPACES; ++i) {
        totalCards += gameSpaces[i]->getSize();
    }
    return totalCards <= 28;
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




