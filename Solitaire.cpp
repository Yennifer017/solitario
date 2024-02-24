//
// Created by igriega on 23/02/24.
//

#include "Solitaire.h"
#include <iostream>
using namespace std;
Solitaire::Solitaire() {
    this->admiMoves = new AdmiMoves;
    this->admiContainers = new  AdmiContainers;
    this->baraja = new Baraja;
    this->admiSpaces = new AdmiGameSpaces;
    this->inicializar();
}

void Solitaire::inicializar() {
    srand(time(NULL));
    for (int codeSimbol = 0; codeSimbol < 4; ++codeSimbol) {
        char color = codeSimbol%2==0? Card::RED_COLOR : Card::BLACK_COLOR ;
        for (int value = 1; value <= 13; ++value) {
            Card* card = new Card(value, codeSimbol, color, false);
            if(baraja->isFull()){
                admiSpaces->addCard(card);
            }else if(admiSpaces->isInitialFull()){
                baraja->insert(card);
            }else{
                int random = rand() % 100;
                if(random>=0  && random<50){
                    baraja->insert(card);
                }else if(random>=50){
                    admiSpaces->addCard(card);
                }
            }
        }
    }
}

void Solitaire::printGame() {
    printf("Baraja: [X][%s]                <3=[%s]  <>=[%s]  E3=[%s]  !!=[%s] \n\n",
           baraja->showCurrent().c_str(),
           admiContainers->showContent(Card::HEART_SIMBOL).c_str(),
           admiContainers->showContent(Card::DIAMOND_SIMBOL).c_str(),
           admiContainers->showContent(Card::TREBOL_SIMBOL).c_str(),
           admiContainers->showContent(Card::SWORD_SIMBOL).c_str()
           );
    printf("Contenedores: \n");
    for (int i = 0; i < AdmiGameSpaces::TOTAL_GAMESPACES ; ++i) {
        printf("%d ---> %s \n", i+1,
               admiSpaces->showContent(i, false).c_str());
    }
}
