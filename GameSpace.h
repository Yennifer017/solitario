//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_GAMESPACE_H
#define SOLITARIO_GAMESPACE_H
#include "Card.h"
#include "LinkedList.h"
#include "Util.h"

class GameSpace: public LinkedList<Card> {
    //TODO sobreescribir los metodos merge
private:
    Util* util;
public:
    GameSpace();
    int getFirstCanSelect();
    bool canInsertLast(Node<Card>* &node);
    void insertLastConditional(Node<Card>* &node);
    Node<Card>* deleteLast();
    virtual LinkedList<Card>* split(int position);
    LinkedList<Card>* splitSearching(Card* card);

};


#endif //SOLITARIO_GAMESPACE_H
