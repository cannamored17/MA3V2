//
// Created by canna on 10/15/2025.
//

#ifndef MA3V2_DECK_H
#define MA3V2_DECK_H
#include <vector>
#include "Card.h"



class Deck {
private:
    std::vector <Card> m_cardDeck;

public:
    Deck();//builds program, creates or INSTANTIATES the object
    void shuffleDeck();
    Card dealCard();
    int getCount() const;
};


#endif //MA3V2_DECK_H