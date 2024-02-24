//
// Created by igriega on 23/02/24.
//

#ifndef SOLITARIO_ADMIGAMESPACES_H
#define SOLITARIO_ADMIGAMESPACES_H
#include "GameSpace.h"

class AdmiGameSpaces {
public:
    const static int TOTAL_GAMESPACES = 7;
    AdmiGameSpaces();
    void addCard(Node<Card>* card);
    void addCard(Card* card);
    GameSpace* getGameSpace(int number);
    bool isInitialFull();
    std::string showAllContent(int gameSpaceNumber, bool withNumbers);
    std::string showContent(int gameSpaceNumber, bool withNumbers);
private:
    GameSpace* gameSpaces[TOTAL_GAMESPACES]{};
};


#endif //SOLITARIO_ADMIGAMESPACES_H
