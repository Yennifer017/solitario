//
// Created by igriega on 23/02/24.
//

#include "AdmiGameSpaces.h"

void AdmiGameSpaces::addCard(Node<Carta>* card) {
    if(gSpace0->getSize()<0){
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
    }
}

GameSpace *AdmiGameSpaces::getGameSpace(int number) {
    switch (number) {
        case 0: return this->gSpace0;
        case 1: return this->gSpace1;
        case 2: return this->gSpace2;
        case 3: return this->gSpace3;
        case 4: return this->gSpace4;
        case 5: return this->gSpace5;
        case 6: return this->gSpace6;
        default: return nullptr;
    }
}

int AdmiGameSpaces::getCounterInitialCards() {
    return this->counterInitialCards;
}
