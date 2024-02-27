//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_CARDPOSITION_H
#define SOLITARIO_CARDPOSITION_H


class CardPosition {
private:
    int primaryCode;
    int secondaryCode;
public:
    CardPosition(int _primaryCode, int _secondaryCode);
    //getters
    int getPrimaryCode();
    int getSecondaryCode();

    //setters
    void setPrimaryCode(int code);
    void setSecondaryCode(int code);

    //constants
    const static int BARAJA_P_CODE = 1;
    const static int CONTAINERS_P_CODE = 2;
    const static int SPACES_P_CODE = 3;
    const static int LEFT_BARAJA_S_CODE = 1;
    const static int RIGHT_BARAJA_S_CODE = 2;
    const static int HEART_CONTAINER = 1;
    const static int DIAMONDS_CONTAINER =2;
    const static int SWORD_CONTAINER = 3;
    const static int TREBOL_CONTAINER = 4;
    const static int FIRST_SPACE = 1;
    const static int SECOND_SPACE = 2;
    const static int THIRD_SPACE = 3;
    const static int FORTH_SPACE = 4;
    const static int FIFTH_SPACE = 5;
    const static int SIXTH_SPACE = 6;
    const static int SEVENTH_SPACE = 7;
};


#endif //SOLITARIO_CARDPOSITION_H
