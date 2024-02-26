//
// Created by igriega on 23/02/24.
//

#include "GameSpace.h"
#include "CartaOrderException.h"
int GameSpace::getFirstCanSelect() {
    int counter=1;
    Node<Card> * current = this->get(this->getSize() - 1);
    while(current->getBefore()->getContent()->isReveal()){
        counter++;
    }
    return this->getSize() - counter;
}

/*void GameSpace::insertLast(Node<Card> *&node, bool forceEmptyReferences) {
    if(this->canInsertLast(node)){
        LinkedList::insertLast(node, forceEmptyReferences);
    }else{
        //throw CartaOrderException();
    }
}


void GameSpace::insertLast(Node<Card> *&node) {
    if(this->canInsertLast(node)){
        LinkedList::insertLast(node);
    }else{
        //throw CartaOrderException();
    }
}*/

GameSpace::GameSpace() {
    util = new Util();
}

bool GameSpace::canInsertLast(Node<Card> *&node) {
    return util->isSecuential(
                this->get(this->getSize()-1)->getContent(),
                node->getContent()
                )
        && util->isAnotherColor(
                this->get(this->getSize()-1)->getContent(),
                node->getContent()
                );
}

void GameSpace::insertLastConditional(Node<Card> *&node) {
    if(this->canInsertLast(node)){
        LinkedList::insertLast(node);
    }else{
        throw CartaOrderException();
    }
}
