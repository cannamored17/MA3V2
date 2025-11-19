//
// Created by canna on 11/17/2025.
//

#ifndef MA3V2_HAND_H
#define MA3V2_HAND_H


#include "Card.h"
#include <vector>
#include <string>

    class Hand {
    private:
        std::vector <Card> m_hand;
    public:
        Hand();
       // Hand(const Hand &);
        void clearHand();
        void operator+=(const Card& card);
        std::string displayCard(int index)const;
        int getPoints()const;
        int cardCount()const;
        void displayAllCards() const;
    };



#endif //MA3V2_HAND_H