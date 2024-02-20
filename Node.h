//
// Created by igriega on 20/02/24.
//

#ifndef SOLITARIO_NODE_H
#define SOLITARIO_NODE_H

template <class T>
class Node {
private:
    T content;
    Node *next;
    Node *before;
public:
    Node(T content){
        this->content = content;
        this->next = nullptr;
        this->before = nullptr;
    };
    Node(T content, Node* next){
        this->content = content;
        this->next = next;
        this->before = nullptr;
    };
    Node(T content, Node* next, Node* before){
        this->content = content;
        this->next = next;
        this->before = before;
    }

    T getContent(){
        return this->content;
    };
    Node* getNext(){
        return this->next;
    };
    Node* getBefore(){
        return this->before;
    }
};


#endif //SOLITARIO_NODE_H
