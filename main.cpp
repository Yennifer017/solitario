#include <iostream>
#include "Solitaire.h"
#include "Util.h"
int main() {
    Util* util = new Util();
    while(true) {
        Solitaire *solitaire = new Solitaire();
        solitaire->play();
        delete(solitaire);
        std::cout<<"\nDeseas jugar otra vez?   1->Si  2->No \n";
        int option = util->getNaturalNumber(1, 2);
        if(option == 2){
            break;
        }
    }
    delete(util);
}
