//
// Created by igriega on 23/02/24.
//

#include "Solitaire.h"
#include <iostream>
#include <random>

using namespace std;
Solitaire::Solitaire() {
    this->admiMoves = new AdmiMoves;
    this->admiContainers = new  AdmiContainers;
    this->baraja = new Baraja;
    this->admiSpaces = new AdmiGameSpaces;
    this->util = new Util();
    this->inicializar();
}

void Solitaire::inicializar() {
    std::random_device rd; // Obtener una semilla aleatoria del dispositivo
    std::mt19937 gen(rd()); // Inicializar un generador de números aleatorios con la semilla
    std::uniform_int_distribution<int> dist(0, 99); // Crea una distribución uniforme de enteros
    //srand(time(NULL));
    for (int codeSimbol = 0; codeSimbol < 4; ++codeSimbol) {
        char color = codeSimbol%2==0? Card::RED_COLOR : Card::BLACK_COLOR ;
        for (int value = 1; value <= 13; ++value) {
            Card* card = new Card(value, codeSimbol, color, false);
            if(baraja->isFull()){
                admiSpaces->addCard(card);
            }else if(admiSpaces->isInitialFull()){
                baraja->insert(card);
            }else{
                int random = dist(gen);
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
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    printf("Baraja: [ %s ][%s]         Contenedores: <3=[%s]  <>=[%s]  E3=[%s]  !!=[%s] \n\n",
           baraja->canShowMore() ? "X" : " ",
           baraja->showCurrent().c_str(),
           admiContainers->showContent(Card::HEART_SIMBOL).c_str(),
           admiContainers->showContent(Card::DIAMOND_SIMBOL).c_str(),
           admiContainers->showContent(Card::TREBOL_SIMBOL).c_str(),
           admiContainers->showContent(Card::SWORD_SIMBOL).c_str()
           );
    printf("Espacios de juego: \n");
    for (int i = 0; i < AdmiGameSpaces::TOTAL_GAMESPACES ; ++i) {
        printf("%d ---> %s \n", i+1,
               admiSpaces->showContent(i, false).c_str());
    }
    cout<<"-----------------------------------------------------------------------------------"<<endl;
}

void Solitaire::play() {
    bool winner = false;
    bool continueGame = true;
    while (!winner && continueGame){
        this->printGame();
        std::cout<<"Ingresa que hay que hacer\n    1->Mover\n    2->Mostrar siguiente de la baraja";
        std::cout<<"\n    3->Deshacer movimiento\n    4->Rehacer movimiento\n    5->Terminar juego\n";
        int option = util->getNaturalNumber(1, 5);
        switch (option) {
            case 1:
                util->clearConsole();
                this->printGame();
                moveCards();
                break;
            case 2: //TODO: add try catch statement
                baraja->showNext();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                continueGame = false;
                break;
            default:
                break;
        }
        winner = checkWinner();
        util->clearConsole();
    }
}

bool Solitaire::checkWinner() {
    //TODO: finished the method, please
    return false;
}

void Solitaire::moveCards() {
    cout<<"\n De donde desea mover la carta?\n    1->De un espacio\n    2->De la baraja";
    cout<<"\n    3->De un contenedor\n    4->No mover";
    int option = util->getNaturalNumber(1, 4);
    switch (option) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}
