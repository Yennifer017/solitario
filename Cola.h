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
    int size;

public:
    Cola(){
        firstElement = nullptr;
        lastElement = nullptr;
        size = 0;
    }

    void insert(T element){
        Node<T>* newNode = new Node<T>(element);
        insert(newNode, false);
    }

    void insert(Node<T>* &node){
        node->emptyReferences();
        insert(node, true);
    }
    void insert(Node<T>* &node, bool forceEmptyReferences){
        if(forceEmptyReferences){
            node->emptyReferences();
        }
        if(firstElement == nullptr){
            firstElement = node;
            lastElement = node;
        }else{
            lastElement->setBefore(node);
            lastElement = node;
        }
        size++;
    }

    Node<T>* remove(){
        if(!this->isEmpty()){
            Node<T>* deleted = firstElement;
            firstElement = firstElement->getBefore();
            if(firstElement== nullptr){
                lastElement == nullptr;
            }
            size--;
            return deleted;
        }else{
            throw std::out_of_range("Error: No se puede eliminar desde una pila vacía");
        }
    }

    Node<T>* peek(){
        return this->firstElement;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return this->size == 0 && this->firstElement == nullptr;
    }

};


#endif //SOLITARIO_COLA_H
