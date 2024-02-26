//
// Created by igriega on 23/02/24.
//
#include <iostream>
#include "Util.h"
int Util::getNumber() {
    do{
        try {
            std::string lectura;
            std::cout<<"      >>";
            std::cin >> lectura;
            int number = std::stoi(lectura);
            return number;
        }
        catch (std::invalid_argument const &e) {
            std::cout << "Numero invalido, intentalo otra vez: ";
        }
        catch (std::out_of_range const &e) {
            std::cout << "Integer overflow error, ingresa un numero mas pequeno: ";
        }
    } while (true);
}

int Util::getNaturalNumber(int min, int max) {
    do {
        int number = getNumber();
        if(number>=min && number<=max){
            return number;
        }else{
            printf("Numbero invalido, debe estar entre %d y %d: ", min, max);
        }
    } while (true);
}

bool Util::isSecuential(Card* inicial, Card* final) {
    return final->getValue() == inicial->getValue() + 1;
}

bool Util::isAnotherColor(Card* inicial, Card* final) {
    return inicial->getColor() != final->getColor();
}

bool Util::isSameSimbol(Card* inicial, Card* final) {
    return inicial->getSimbol() == final->getSimbol();
}

void Util::clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        // ANSI Escape Code for clearing the screen
        std::cout << "\033[2J\033[1;1H"<<std::endl;
    #endif
}

void Util::enterContinue() {
    std::cout<<"Ingrese cualquier letra/numero para continuar\n";
    std::string lectura;
    std::cin >> lectura;
    lectura.clear();
}

void Util::printSeparator() {
    std::cout<<"-----------------------------------------------------------------------------------"<<std::endl;
}
