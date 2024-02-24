//
// Created by igriega on 21/02/24.
//

#include <stdexcept>
#include "Card.h"


Card::Card(int _value, int _codeSimbol, char _color, bool _reveal) {
    if(_value < 0 || _value> 13){
        throw std::invalid_argument("Error: la carta no puede tener ese valor");
    }
    if(_codeSimbol <0 || _codeSimbol > 4){
        throw std::invalid_argument("Error: la carta no puede tener ese codigo de simbolo");
    }
    if(_color != Card::RED_COLOR && _color != Card::BLACK_COLOR){
        throw std::invalid_argument("Error: la carta no tiene un color adecuado");
    }
    this->value = _value;
    this->codeSimbol = _codeSimbol;
    this->color = _color;
    this->reveal = _reveal;
}
//setters
int Card::getValue() {
    return this->value;
}

int Card::getCodeSimbol() {
    return this->codeSimbol;
}

char Card::getColor() {
    return this->color;
}

bool Card::isReveal() {
    return this->reveal;
}

std::string Card::getRealValue() {
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

std::string Card::getSimbol() {
    switch (this->codeSimbol) {
        case Card::HEART_SIMBOL :
            return "<3";
        case Card::DIAMOND_SIMBOL :
            return "<>";
        case Card::TREBOL_SIMBOL :
            return "E3";
        case Card::SWORD_SIMBOL :
            return "!!";
        default:
            throw std::bad_exception();
    }
}

void Card::setReveal(bool _reveal) {
    this->reveal = _reveal;
}

std::string Card::showInformation() {
    return this->getRealValue() + this->getSimbol() + this->color;
}



