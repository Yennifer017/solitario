//
// Created by igriega on 22/02/24.
//

#include "Baraja.h"
Baraja::Baraja() {
    this->leftCola = new Cola<Carta>;
    this->rightCola = new Cola<Carta>;
}
void Baraja::insert(Node<Carta> *carta) {
    leftCola->insert(carta);
}
void Baraja::showNext() {
    if(!leftCola->isEmpty()){
        Node<Carta>* newCurrent = leftCola->remove();
        if(!rightCola->isEmpty()){
            Node<Carta>* lastCurrent = rightCola->remove();
            leftCola->insert(lastCurrent, true);
        }
        rightCola->insert(newCurrent, true);
    }else{
        throw std::out_of_range("Error: No hay mas cartas que mostrar");
    }
}

bool Baraja::isEmpty() {
    return leftCola->isEmpty() && rightCola->isEmpty();
}

Node<Carta> *Baraja::removeCurrent() {
    if(!rightCola->isEmpty()){
        return rightCola->remove();
    }else{
        throw std::out_of_range("Error: No hay ninguna carta actual");
    }
}

Node<Carta> *Baraja::getCurrent() {
    if(!rightCola->isEmpty()){
        return rightCola->peek();
    }else{
        throw std::out_of_range("Error: No hay ninguna carta actual");
    }
}


