//
// Created by igriega on 21/02/24.
//

#ifndef SOLITARIO_CARTA_H
#define SOLITARIO_CARTA_H


#include <string>

class Carta {
private:
    //miembros de la clase
    int value;
    int codeSimbol;
    char color;
    bool reveal;
public:
    //miembros estaticos
    static int HEART_SIMBOL;
    static int TREBOL_SIMBOL;
    static int DIAMOND_SIMBOL;
    static int SWORD_SIMBOL;
    static char RED_COLOR;
    static char BLACK_COLOR;

    //constructor
    Carta(int _value, int _codeSimbol, char _color, bool _reveal);

    //getters
    int getValue();
    int getCodeSimbol();
    char getColor();
    bool isReveal();

    std::string getRealValue();
    std::string getSimbol();

    //setter
    void setReveal(bool _reveal);

};


#endif //SOLITARIO_CARTA_H
