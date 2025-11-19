//
// Created by canna on 11/17/2025.
//

#include "Hand.h"
#include <iostream>

Hand::Hand() = default;

void Hand::clearHand() {
    m_hand.clear();
}

void Hand::operator+=(const Card& card) {
    m_hand.push_back(card);
}

std::string Hand::displayCard(int index) const {
    if (index >= 0 && index < m_hand.size()) {
        return m_hand[index].getCard();
    }
    return "-";
}

int Hand::getPoints() const {
    int total = 0;
    int aceCount = 0;

    for (const Card& card : m_hand) {
        total += card.getValue();
        if (card.getRank() == "Ace") {
            aceCount++;
        }
    }

    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }

    return total;
}

int Hand::cardCount() const {
    return m_hand.size();
}

void Hand::displayAllCards() const {
    for (const Card& card : m_hand) {
        std::cout << card.getCard() << std::endl;
    }
}