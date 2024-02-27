//
// Created by igriega on 22/02/24.
//

#include "Baraja.h"
Baraja::Baraja() {
    this->leftCola = new Cola<Card>;
    this->rightCola = new Cola<Card>;
    counterFull = 0;
}
void Baraja::insert(Node<Card> *carta) {
    leftCola->insert(carta);
    counterFull++;
}
void Baraja::showNext() {
    if(!leftCola->isEmpty()){
        Node<Card>* newCurrent = leftCola->remove();
        if(!rightCola->isEmpty()){
            Node<Card>* lastCurrent = rightCola->remove();
            lastCurrent->getContent()->setReveal(false);
            leftCola->insert(lastCurrent, true);
        }
        rightCola->insert(newCurrent, true);
        newCurrent->getContent()->setReveal(true);
    }else{
        throw std::out_of_range("Error: No hay mas cartas que mostrar");
    }
}

bool Baraja::isEmpty() {
    return leftCola->isEmpty() && rightCola->isEmpty();
}

Node<Card> *Baraja::removeCurrent() {
    if(!rightCola->isEmpty()){
        return rightCola->remove();
    }else{
        throw std::out_of_range("Error: No hay ninguna carta actual");
    }
}

Node<Card> *Baraja::getCurrent() {
    if(!rightCola->isEmpty()){
        return rightCola->peek();
    }else{
        throw std::out_of_range("Error: No hay ninguna carta actual");
    }
}


bool Baraja::isFull() {
    return counterFull >= 24;
}

void Baraja::insert(Card *card) {
    Node<Card>* nodeCard = new Node<Card>(card);
    this->insert(nodeCard);
}

std::string Baraja::showCurrent() {
    if(!rightCola->isEmpty()){
        return rightCola->peek()->getContent()->showInformation();
    }else{
        return "    ";
    }
}

bool Baraja::canShowMore() {
    return !leftCola->isEmpty();
}

void Baraja::reinsert(Node<Card> *&card) {
    if(rightCola->isEmpty()){
        rightCola->insert(card, true);
    }else{
        throw std::bad_exception();
    }
}

void Baraja::reinsert(bool recoverCard) {
    Node<Card>* node = rightCola->remove();
    leftCola->insertInFront(node, true);
    if(recoverCard){
        Node<Card>* nodeFromLeft = leftCola->removeLast();
        rightCola->insert(nodeFromLeft);
    }
}

bool Baraja::hasCurrentCard() {
    return !rightCola->isEmpty();
}


