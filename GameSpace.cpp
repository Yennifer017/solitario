//
// Created by igriega on 23/02/24.
//

#include "GameSpace.h"
#include "CartaOrderException.h"
int GameSpace::getFirstCanSelect() {
    int counter=1;
    Node<Card> * current = this->get(this->getSize() - 1);
    while(current->getBefore()!= nullptr && current->getBefore()->getContent()->isReveal()){
        counter++;
        current = current->getBefore();
    }
    return this->getSize() - counter;
}

GameSpace::GameSpace() {
    util = new Util();
}

bool GameSpace::canInsertLast(Node<Card> *&node) {
    if(!isEmpty()) {
        return util->isSecuential(
                this->get(this->getSize() - 1)->getContent(),
                node->getContent()
        )
               && util->isAnotherColor(
                this->get(this->getSize() - 1)->getContent(),
                node->getContent()
        );
    }else{
        return node->getContent()->getValue() == 13;
    }
}

void GameSpace::insertLastConditional(Node<Card> *&node) {
    if(this->canInsertLast(node)){
        LinkedList::insertLast(node);
    }else{
        throw CartaOrderException();
    }
}

Node<Card> *GameSpace::deleteLast() {
    Node<Card>* deleted = LinkedList::deleteLast();
    if(!isEmpty() && !this->lastElement->getContent()->isReveal()){
        this->lastElement->getContent()->setReveal(true);
    }
    return deleted;
}

LinkedList<Card> *GameSpace::split(int position) {
    LinkedList<Card>* deleted = LinkedList::split(position);
    if(!isEmpty() && !this->lastElement->getContent()->isReveal()){
        this->lastElement->getContent()->setReveal(true);
    }
    return deleted;
}
