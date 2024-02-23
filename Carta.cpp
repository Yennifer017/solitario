//
// Created by igriega on 21/02/24.
//

#include <stdexcept>
#include "Carta.h"


Carta::Carta(int _value, int _codeSimbol, char _color, bool _reveal) {
    if(_value < 0 || _value> 13){
        throw std::invalid_argument("Error: la carta no puede tener ese valor");
    }
    if(_codeSimbol <0 || _codeSimbol > 4){
        throw std::invalid_argument("Error: la carta no puede tener ese codigo de simbolo");
    }
    if(_color != Carta::RED_COLOR && _color != Carta::BLACK_COLOR){
        throw std::invalid_argument("Error: la carta no tiene un color adecuado");
    }
    this->value = _value;
    this->codeSimbol = _codeSimbol;
    this->color = _color;
    this->reveal = _reveal;
}
//setters
int Carta::getValue() {
    return this->value;
}

int Carta::getCodeSimbol() {
    return this->codeSimbol;
}

char Carta::getColor() {
    return this->color;
}

bool Carta::isReveal() {
    return this->reveal;
}

std::string Carta::getRealValue() {
    if(this->value >1 && this->value<11){
        return std::to_string(this->value);
    }else{
        switch (value) {
            case 1:
                return "A";
            case 11:
                return "J";
            case 12:
                return "Q";
            case 13:
                return "K";
            default:
                throw std::bad_exception();
        }
    }
}

std::string Carta::getSimbol() {
    switch (this->codeSimbol) {
        case Carta::HEART_SIMBOL :
            return "<3";
        case Carta::DIAMOND_SIMBOL :
            return "<>";
        case Carta::TREBOL_SIMBOL :
            return "E3";
        case Carta::SWORD_SIMBOL :
            return "!!";
        default:
            throw std::bad_exception();
    }
}

void Carta::setReveal(bool _reveal) {
    this->reveal = _reveal;
}



