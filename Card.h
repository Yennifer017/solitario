//
// Created by igriega on 21/02/24.
//

#ifndef SOLITARIO_CARD_H
#define SOLITARIO_CARD_H


#include <string>

class Card {
private:
    //miembros de la clase
    int value;
    int codeSimbol;
    char color;
    bool reveal;
public:
    //miembros estaticos
    const static int HEART_SIMBOL = 0;
    const static int TREBOL_SIMBOL = 1;
    const static int DIAMOND_SIMBOL = 2;
    const static int SWORD_SIMBOL = 3;
    const static char RED_COLOR = 'R';
    const static char BLACK_COLOR = 'B';

    //constructor
    Card(int _value, int _codeSimbol, char _color, bool _reveal);

    //getters
    int getValue();
    int getCodeSimbol();
    char getColor();
    bool isReveal();

    std::string getRealValue();
    std::string getSimbol();
    std::string showInformation();

    //setter
    void setReveal(bool _reveal);

};


#endif //SOLITARIO_CARD_H
