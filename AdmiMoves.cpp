//
// Created by igriega on 23/02/24.
//

#include "AdmiMoves.h"

AdmiMoves::AdmiMoves(AdmiContainers *_admiContainers, AdmiGameSpaces *_admiGameSpaces, Baraja* _baraja) {
    this->admiContainers = _admiContainers;
    this->admiGameSpaces = _admiGameSpaces;
    this->baraja = _baraja;
    posCurrentNode = 0;
}

void AdmiMoves::undo() {

}

void AdmiMoves::rendo() {

}

void AdmiMoves::insertLast(Node<Registro> *&node) {
    if(currentNode != lastElement){
        LinkedList<Registro>* deletedList = this->split(posCurrentNode + 1);
        delete(deletedList);
    }
    LinkedList::insertLast(node);
    this->currentNode = lastElement;
    posCurrentNode = size-1;
}

