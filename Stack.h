//
// Created by igriega on 20/02/24.
//

#ifndef SOLITARIO_STACK_H
#define SOLITARIO_STACK_H

#include <stdexcept>
#include "Node.h"
template <class T>
class Stack {
private:
    Node<T>* topElement;
    int size;
public:
    //constructores
    Stack() {
        topElement = nullptr;
        size = 0;
    };
    //metodos
    Node<T>* pop(){
        if(topElement!= nullptr){
            Node deletedNode = topElement;
            topElement = topElement->getNext();
            size--;
            return deletedNode;
        }else{
            throw std::out_of_range("Error: No se puede hacer eliminar en una lista vacía");
        }
    };
    Node<T>* peek(){
        return topElement;
    };
    void push(T content){
        Node<T>* newNode = new Node(content, topElement); //creando un nuevo nodo
        topElement = newNode;
        size++;
    };
    void push(Node<T>* &node){
        node->setBefore(nullptr);
        node->setNext(topElement);
        node->setBefore(nullptr);
        topElement =  node;
        size++;
    }
    bool isEmpty(){
        return size == 0;
    }
    int getSize(){
        return size;
    }
};


#endif //SOLITARIO_STACK_H
