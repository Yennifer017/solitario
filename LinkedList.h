//
// Created by igriega on 20/02/24.
//

#ifndef SOLITARIO_LINKEDLIST_H
#define SOLITARIO_LINKEDLIST_H

#include <stdexcept>
#include "Node.h"

template <class T>
class LinkedList {
private:
    /* ATRIBUTES */
    Node<T>* firstElement;
    Node<T>* lastElement;
    int size;

    /* METHODS */
    void insertWhenEmpty(Node<T>* &node){
        firstElement = node;
        lastElement = node;
    }

public:
    /* CONSTRUCTORES*/
    LinkedList(){
        firstElement = nullptr;
        lastElement = nullptr;
        size = 0;
    }

    /* METHODS */
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }

    //OBTENER
    Node<T>* get(int position){
        if(position>=size || position<0){
            throw std::out_of_range("Error: No se puede acceder al elemento de la lista");
        }else if(position == 0){
            return firstElement;
        }else if(position == size - 1){
            return lastElement;
        }else{
            int half = size/2;
            Node<T>* current;
            if(position<=half){
                current = firstElement;
                for (int i = 0; i < position; ++i) {
                    current =  current->getNext();
                }
            }else{
                current = lastElement;
                for (int i = size; i >= position; --i) {
                    current = current->getBefore();
                }
            }
            return current;
        }
    }
    // INSERTS
    void insertLast(Node<T>* &node, bool forceEmptyReferences){
        if(forceEmptyReferences){
            node->emptyReferences();
        }
        if(this->isEmpty()){
            insertWhenEmpty(node);
        }else{
            node->setBefore(lastElement);
            lastElement->setNext(node);
            lastElement = node;
        }
        size++;
    }
    void insertLast(T element){
        Node<T>* newNode =  new Node(element);
        this->insertLast(newNode, false);
    }
    void insertLast(Node<T>* &node){
        this->insertLast(node, true);
    }
    void insertFirst(Node<T>* &node, bool forceEmptyReferences){
        if(forceEmptyReferences){
            node->emptyReferences();
        }
        if(this->isEmpty()){
            insertWhenEmpty(node);
        }else{
            node->setNext(firstElement);
            firstElement->setBefore(node);
            firstElement = node;
        }
        size++;
    }
    void insertFirst(T element){
        Node<T>* newNode =  new Node(element);
        this->insertFirst(newNode, false);
    }
    void insertFirst(Node<T>* &node){
        this->insertFirst(node, true);
    }
    void insert(Node<T>* &node, int position){
        if(position == size){
            this->insertLast(node, true);
        }else if(position == 0){
            this->insertFirst(node, true);
        }else if(position>0 && position<=size){
            Node<T>* left = get(position-1);
            Node<T>* right = left->getNext();
            left->setNext(node);
            node->setBefore(left);
            right->setBefore(node);
            node->setNext(right);
            size++;
        }else{
            throw std::out_of_range("Error: No se puede acceder al elemento de la lista");
        }
    }
    void insert(T element, int position){
        Node<T>* newNode = new Node(element);
        this->insert(newNode, position);
    }



};


#endif //SOLITARIO_LINKEDLIST_H
