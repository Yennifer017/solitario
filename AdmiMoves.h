//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_ADMIMOVES_H
#define SOLITARIO_ADMIMOVES_H
#include "LinkedList.h"
#include "Registro.h"
#include "Node.h"
#include "AdmiContainers.h"
#include "AdmiGameSpaces.h"
#include "Baraja.h"
class AdmiMoves: public LinkedList<Registro> {
private:
    Node<Registro>* currentNode;
    AdmiContainers* admiContainers;
    AdmiGameSpaces* admiGameSpaces;
    Baraja* baraja;
public:
    //CONSTRUCTOR
    AdmiMoves(AdmiContainers* _admiContainers, AdmiGameSpaces* _admiGameSpaces, Baraja* baraja);

    //METHODS
    void undo();
    void rendo();

};


#endif //SOLITARIO_ADMIMOVES_H
