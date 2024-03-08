//
// Created by igriega on 23/02/24.
//

#include <iostream>
#include "AdmiMoves.h"
#include "GameSpace.h"

AdmiMoves::AdmiMoves(AdmiContainers *_admiContainers, AdmiGameSpaces *_admiGameSpaces, Baraja* _baraja) {
    this->admiContainers = _admiContainers;
    this->admiGameSpaces = _admiGameSpaces;
    this->baraja = _baraja;
    posCurrentNode = 0;
}

void AdmiMoves::undo() {
    if(posCurrentNode >= 0){
        Node<Registro>* registro = this->get(posCurrentNode);
        switch (registro->getContent()->getFinal()->getPrimaryCode()) {
            case CardPosition::SPACES_P_CODE:
                this->undoFromSpace(registro->getContent());
                break;
            case CardPosition::BARAJA_P_CODE:
                //este escenario ocurre solo cuando la propia baraja mueve las cartas
                baraja->reinsert(
                        registro->getContent()->getInitial()->getSecondaryCode() == 1);
                break;
            case CardPosition::CONTAINERS_P_CODE:
                this->undoFromContainer(registro->getContent());
                break;
        }
        posCurrentNode--;
    }else{
        throw std::out_of_range("No hay movimientos para retroceder");
    }
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

void AdmiMoves::undoFromContainer(Registro* reg) {
    Node<Card>* cardNode = admiContainers->getContainer(reg->getFinal()->getSecondaryCode())->pop();
    switch (reg->getInitial()->getPrimaryCode()) {
        case CardPosition::SPACES_P_CODE:
            GameSpace* initialSpace;
            initialSpace= admiGameSpaces->getGameSpace(reg->getInitial()->getSecondaryCode());
            if(!initialSpace->canInsertLast(cardNode)){
                initialSpace->hiddeLast();
            }
            admiGameSpaces->getGameSpace(reg->getInitial()->getSecondaryCode())
                ->insertLast(cardNode);
            break;
        case CardPosition::BARAJA_P_CODE:
            baraja->reinsert(cardNode);
            break;
    }
}

void AdmiMoves::undoFromSpace(Registro* reg) {
    Node<Card>* cardNode;
    GameSpace* inicialSpace = admiGameSpaces->getGameSpace(reg->getInitial()->getSecondaryCode());
    switch (reg->getFinal()->getPrimaryCode()) {
        case CardPosition::CONTAINERS_P_CODE:
            cardNode = admiContainers->getContainer(reg->getFinal()->getSecondaryCode())->pop();
            if(!inicialSpace->canInsertLast(cardNode)){
                inicialSpace->hiddeLast();
            }
            inicialSpace->insertLast(cardNode);
            break;
        case CardPosition::SPACES_P_CODE:
            GameSpace* finalSpace = admiGameSpaces->getGameSpace(reg->getFinal()->getSecondaryCode());
            int position = finalSpace->searchPos(reg->getCardInformation());
            LinkedList<Card> *list;
            list = position == 0 ? finalSpace : finalSpace->split(position);
            cardNode = list->get(0);
            if(!inicialSpace->canInsertLast(cardNode)){
                inicialSpace->hiddeLast();
            }
            inicialSpace->merge(list);
            if(position == 0 ){
                finalSpace->clear();
            }
            break;
    }
}


