#include <iostream>
#include "Stack.h"
#include "Node.h"
#include "Cola.h"
#include "LinkedList.h"

int main() {
    LinkedList<int> list = *new LinkedList<int>();

    list.insertFirst(5);
    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);

    list.insert(1, 2);

    printf("La posicion %d de la lista es %d", 0, list.get(2)->getContent()); //10
}
