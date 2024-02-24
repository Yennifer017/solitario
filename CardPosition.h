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
    //setters
    int getPrimaryCode();
    int getSecondaryCode();
};


#endif //SOLITARIO_CARDPOSITION_H
