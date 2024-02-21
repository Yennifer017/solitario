//
// Created by igriega on 20/02/24.
//

#ifndef SOLITARIO_COLA_H
#define SOLITARIO_COLA_H
#include "Node.h"

template <class T>
class Cola {
private:
    Node<T>* firstElement;
    Node<T>* lastElement;
public:
    Cola(){
        firstElement = nullptr;
        lastElement = nullptr;
    }

    void insert(T element){
        Node<T>* newNode = new Node<T>(element);
        if(firstElement == nullptr){
            firstElement = newNode;
            lastElement = newNode;
        }else{
            lastElement->setBefore(newNode);
            lastElement = newNode;
        }
    }

    void remove(){
        firstElement = firstElement->getBefore();
        if(firstElement== nullptr){
            lastElement == nullptr;
        }
    }

    Node<T>* peek(){
        return this->firstElement;
    }

};


#endif //SOLITARIO_COLA_H
