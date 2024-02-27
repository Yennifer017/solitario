//
// Created by igriega on 23/02/24.
//

#include "Solitaire.h"
#include <iostream>
#include <random>
#include "Card.h"
#include "CartaOrderException.h"

using namespace std;
Solitaire::Solitaire() {
    this->admiContainers = new  AdmiContainers;
    this->baraja = new Baraja;
    this->admiSpaces = new AdmiGameSpaces;
    this->util = new Util();
    this->admiMoves = new AdmiMoves(admiContainers, admiSpaces, baraja);
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
    util->printSeparator();
    printf("Baraja: [ %s ][%s]         Contenedores: <3R=[%s]  <>R=[%s]  E3B=[%s]  !!B=[%s] \n\n",
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
    util->printSeparator();
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
                moveCards();
                break;
            case 2:
                moveDisplayBaraja();
                break;
            case 3:
                try {
                    admiMoves->undo();
                } catch(const std::out_of_range& e) {
                    cout<<"No hay movimientos para retroceder"<<endl;
                    util->enterContinue();
                }
                break;
            case 4:
                try {
                    admiMoves->rendo();
                    cout<<"No implementado aun, espere la actualizacion 1.2";
                    util->enterContinue();
                } catch(const std::out_of_range& e) {
                    cout<<"No hay movimientos para recuperar"<<endl;
                    util->enterContinue();
                }
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
    if(winner){
        cout<<"FELICIDADES, HAS GANADO"<<endl;
    }else{
        cout<<"HAS PERDIDO, MAS SUERTE PARA LA PROXIMA"<<endl;
    }
}

bool Solitaire::checkWinner() {
    return admiContainers->isFull();
}

void Solitaire::moveDisplayBaraja() {
    try {
        int codeWasEmpty = baraja->hasCurrentCard() ? 1: 0;
        baraja->showNext();
        this->saveRegistro(CardPosition::BARAJA_P_CODE, codeWasEmpty,
                           CardPosition::BARAJA_P_CODE, 0,
                           baraja->getCurrent()->getContent());
    } catch(const std::out_of_range& e) {
        cout<<"--La baraja esta vacia--";
        util->enterContinue();
    }
}

void Solitaire::moveCards() {
    util->clearConsole();
    this->printGame();
    cout<<"\n De donde desea mover la carta?\n    1->De un espacio\n    2->De la baraja";
    cout<<"\n    3->De un contenedor\n    4->No mover\n";
    int option = util->getNaturalNumber(1, 4);
    switch (option) {
        case 1:
            this->moveFromSpace();
            break;
        case 2:
            this->moveFromBaraja();
            break;
        case 3:
            this->moveFromContainer();
            break;
        default:
            break;
    }
}

void Solitaire::moveFromSpace() {
    cout<<"Ingrese el numero de espacio de origen: "<<endl;
    int numberSpace = util->getNaturalNumber(1, 7);
    numberSpace--;
    GameSpace* space = admiSpaces->getGameSpace(numberSpace);
    if(!space->isEmpty()){
        util->printSeparator();
        cout<<"Espacio seleccionado:"<<endl;
        cout<<admiSpaces->showContent(numberSpace, true)<<endl;
        util->printSeparator();
        cout<<"Ingrese desde donde seran seleccionadas las cartas a mover: "<<endl;
        int start = util->getNaturalNumber(space->getFirstCanSelect()+1, space->getSize());
        start--;
        try {
            Node<Card> *cardNode = space->get(start);
            if (start == space->getSize() - 1) {  //mover solo una carta
                CardPosition* pos = this->tryMoveOneCard(cardNode);
                switch (pos->getPrimaryCode()) {
                    case CardPosition::CONTAINERS_P_CODE :
                        cardNode = space->deleteLast();
                        admiContainers->saveCard(cardNode);
                        break;
                    case CardPosition::SPACES_P_CODE :
                        cardNode = space->deleteLast();
                        admiSpaces->getGameSpace(pos->getSecondaryCode())->insertLastConditional(cardNode);
                        break;
                    default:
                        break;
                }
                delete(pos);
            } else { //mover varias cartas
                int end = this->moveToSpace(cardNode);
                LinkedList<Card>* secondSpace = space->split(start);
                GameSpace* destinitySpace = admiSpaces->getGameSpace(end);
                destinitySpace->merge(secondSpace);
            }
            //TODO: save registro here
        }catch (const CartaOrderException& e){
            cout<<"No se puede mover la(s) carta(s) a ese lugar"<<endl;
            util->enterContinue();
        }
    }else{
        cout<<"--No hay elementos en ese espacio de juego--"<<endl;
        util->enterContinue();
    }
}

void Solitaire::moveFromBaraja() {
    try {
        Node<Card> *cardNode = baraja->getCurrent();
        CardPosition* pos = this->tryMoveOneCard(cardNode);
        bool saveRegistro = true;
        switch (pos->getPrimaryCode()) {
            case CardPosition::CONTAINERS_P_CODE :
                cardNode = baraja->removeCurrent();
                pos->setSecondaryCode(admiContainers->saveCard(cardNode));
                break;
            case CardPosition::SPACES_P_CODE :
                cardNode = baraja->removeCurrent();
                admiSpaces->getGameSpace(pos->getSecondaryCode())->insertLastConditional(cardNode);
                break;
            default:
                saveRegistro = false;
                break;
        }
        if(saveRegistro){
            this->saveRegistro(CardPosition::BARAJA_P_CODE, CardPosition::RIGHT_BARAJA_S_CODE,
                               pos->getPrimaryCode(), pos->getSecondaryCode(),
                               cardNode->getContent());
        }
    }catch (const std::out_of_range& e){
        cout<<e.what()<<endl;
        util->enterContinue();
    }catch (const CartaOrderException& e){
        cout<<"No se puede mover la carta a ese lugar"<<endl;
        util->enterContinue();
    }

}

void Solitaire::moveFromContainer() {
    cout<<"Que carta deseas mover?\n    1->De corazones\n    2->De diamantes"<<endl;
    cout<<"    3->De Espadas\n    4->De treboles"<<endl;
    int option = util->getNaturalNumber(1, 4);
    Container* container = admiContainers->getContainer(option);
    try {
        Node<Card>* cardNode = container->peek();
        int numberSpace = this->moveToSpace(cardNode);
        cardNode = container->pop();
        admiSpaces->getGameSpace(numberSpace)->insertLastConditional(cardNode);
        this->saveRegistro(CardPosition::CONTAINERS_P_CODE, option,
                           CardPosition::SPACES_P_CODE, numberSpace,
                           cardNode->getContent());
    }catch (const std::out_of_range& e){
        cout<<"El contenedor seleccionado esta vacio"<<endl;
        util->enterContinue();
    }catch(const CartaOrderException& e){
        cout<<"No se puede mover la carta hacia ese lugar"<<endl;
        util->enterContinue();
    }
}

int Solitaire::moveToSpace(Node<Card>* &cardNode) {
    cout<<"Ingrese el espacio a donde lo movera:"<<endl;
    int spaceNumber = util->getNaturalNumber(1,7);
    spaceNumber--;
    GameSpace* space = this->admiSpaces->getGameSpace(spaceNumber);
    if(space->canInsertLast(cardNode)){
        return spaceNumber;
    }else{
        throw CartaOrderException();
    }
}


CardPosition* Solitaire::tryMoveOneCard(Node<Card>* &cardNode) {
    cout << "A donde moveras la carta? \n    1->A un contenedor\n    2->A un espacio\n";
    cout << "    3->No mover\n";
    CardPosition* cardPosition = new CardPosition(-1,-1);
    int option = util->getNaturalNumber(1, 3);
    switch (option) {
        case 1: //contenedor
            if(admiContainers->canSave(cardNode)){
                cardPosition->setPrimaryCode(CardPosition::CONTAINERS_P_CODE);
            }else{
                throw CartaOrderException();
            }
            break;
        case 2: //espacio
            cardPosition->setPrimaryCode(CardPosition::SPACES_P_CODE);
            cardPosition->setSecondaryCode(this->moveToSpace(cardNode));
            break;
        default: //a ninguno
            break;
    }
    return cardPosition;
}

void Solitaire::saveRegistro(int pCodeFrom, int sCodeFrom, int pCodeTo, int sCodeTo, Card *card) {
    Registro* registro = new Registro(
            new CardPosition(pCodeFrom, sCodeFrom),
            new CardPosition(pCodeTo, sCodeTo),
            card
    );
    Node<Registro>* regNode = new Node<Registro>(registro);
    admiMoves->insertLast(regNode);
}
