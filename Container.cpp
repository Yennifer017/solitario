//
// Created by igriega on 22/02/24.
//

#include <stdexcept>
#include "Container.h"
#include "CartaOrderException.h"
Container::Container(int codeSimbol) {
    if(this->codeSimbol<0 || this->codeSimbol>4){
        throw std::invalid_argument("Error: el contenedor no puede tener ese codigo de simbolo");
    }
    this->codeSimbol = codeSimbol;
    util = new Util();
}

void Container::push(Node<Carta> *&node) {
    if(this->isEmpty() && node->getContent()->getValue() == 1
        ||
        (!this->isEmpty()
        && util->isSameSimbol(this->peek()->getContent(), node->getContent())
        && util->isSecuential(this->peek()->getContent(), node->getContent()))
    ){
        Stack::push(node);
    }else{
        throw CartaOrderException();
    }
}





