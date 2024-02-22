#include <iostream>
#include "Stack.h"
#include "Node.h"
#include "Cola.h"
#include "LinkedList.h"

int main() {
    LinkedList<int> list = *new LinkedList<int>();

    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);
    list.insertLast(40);
    list.deleteLast();
    list.deleteLast();
    list.deleteLast();
    list.deleteLast();

    int position = 1;
    printf("La posicion %d de la lista es %d", position, list.get(position)->getContent()); //20
}
