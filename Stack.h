//
// Created by igriega on 20/02/24.
//

#ifndef SOLITARIO_STACK_H
#define SOLITARIO_STACK_H

#include "Node.h"
template <class T>
class Stack {
private:
    Node<T>* topElement;

public:
    //constructores
    Stack() {
        topElement = nullptr;
    };

    void pop(){
        if(topElement!= nullptr){
            topElement = topElement->getNext();
        }
    };
    Node<T>* peek(){
        return topElement;
    };
    void push(T content){
        Node<T>* newNode = new Node(content, topElement); //creando un nuevo nodo
        topElement = newNode;
    };
};


#endif //SOLITARIO_STACK_H
