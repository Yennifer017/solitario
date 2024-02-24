//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_ADMIMOVES_H
#define SOLITARIO_ADMIMOVES_H
#include "LinkedList.h"
#include "Registro.h"
#include "Node.h"
class AdmiMoves: public LinkedList<Registro> {
private:
    Node<Registro>* currentNode;

};


#endif //SOLITARIO_ADMIMOVES_H
