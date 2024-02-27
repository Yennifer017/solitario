//
// Created by igriega on 22/02/24.
//

#ifndef SOLITARIO_BARAJA_H
#define SOLITARIO_BARAJA_H

#include "Cola.h"
#include "Card.h"
#include "Node.h"
#include "Util.h"
class Baraja {
private:
    Cola<Card>* leftCola;
    Cola<Card>* rightCola;
    int counterFull;
public:
    //constructor
    Baraja();
    void insert(Node<Card>* carta);
    void insert(Card* card);
    void showNext();
    Node<Card>* getCurrent();
    Node<Card>* removeCurrent();
    bool isEmpty();
    bool isFull();
    bool canShowMore();
    bool hasCurrentCard();
    std::string showCurrent();

    void reinsert(Node<Card>* &card);
    void reinsert(bool recoverCard);
};


#endif //SOLITARIO_BARAJA_H
