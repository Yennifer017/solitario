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
    this->currentNode = nullptr;
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
    if(posCurrentNode+1 < this->size){
        posCurrentNode++;
        Node<Registro>* registro = this->get(posCurrentNode);
        switch (registro->getContent()->getInitial()->getPrimaryCode()) {
            case CardPosition::SPACES_P_CODE :
                rendoFromSpace(registro->getContent());
                break;
            case CardPosition::BARAJA_P_CODE :
                rendoFromBaraja(registro->getContent());
                break;
            case CardPosition::CONTAINERS_P_CODE :
                rendoFromContainer(registro->getContent());
                break;
            default:
                break;
        }
    }else{
        throw std::out_of_range("No hay movimientos para adelantar");
    }
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

/*UNDO METHODS HERE*/
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
/*RENDO METHODS HERE*/
void AdmiMoves::rendoFromSpace(Registro* reg) {
    GameSpace* originSpace = admiGameSpaces->getGameSpace(reg->getInitial()->getSecondaryCode());
    int startPos = originSpace->searchPos(reg->getCardInformation());
    Node<Card> *cardNode = originSpace->get(startPos);
    if(startPos == originSpace->getSize() -1){ //move one card
        switch (reg->getFinal()->getPrimaryCode()) {
            case CardPosition::CONTAINERS_P_CODE :
                cardNode = originSpace->deleteLast();
                admiContainers->saveCard(cardNode);
                break;
            case CardPosition::SPACES_P_CODE :
                cardNode = originSpace->deleteLast();
                admiGameSpaces->getGameSpace(reg->getFinal()->getSecondaryCode())
                                ->insertLast(cardNode);
                break;
            default:
                break;
        }
    } else { //move more than one card
        LinkedList<Card>* secondList = originSpace->split(startPos);
        GameSpace* destinitySpace = admiGameSpaces->getGameSpace(reg->getFinal()->getSecondaryCode());
        destinitySpace->merge(secondList);
    }
}

void AdmiMoves::rendoFromBaraja(Registro* reg) {
    Node<Card> *cardNode;
    switch (reg->getFinal()->getPrimaryCode()) {
        case CardPosition::BARAJA_P_CODE : //mostrar siguiente de la baraja
            baraja->showNext();
            break;
        case CardPosition::CONTAINERS_P_CODE :
            cardNode = baraja->removeCurrent();
            admiContainers->saveCard(cardNode);
            break;
        case CardPosition::SPACES_P_CODE :
            cardNode = baraja->removeCurrent();
            admiGameSpaces->getGameSpace(reg->getFinal()->getSecondaryCode())
                    ->insertLastConditional(cardNode);
            break;

    }
}

void AdmiMoves::rendoFromContainer(Registro* reg) {
    Container* container = admiContainers->getContainer(reg->getInitial()->getSecondaryCode());
    Node<Card>* cardNode  = container->pop();
    admiGameSpaces->getGameSpace(reg->getFinal()->getSecondaryCode())
            ->insertLast(cardNode);
}




