#include <string>
#include <random>
#include <algorithm>
#include <iostream>

#include "Deck.h"
#include "Card.h"

Deck::Deck() {
    shuffleDeck();
}

void Deck::shuffleDeck() {
    m_cardDeck.clear();

    static const std::string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    static const std::string ranks[13] = {
        "2","3","4","5","6","7","8","9","10",
        "Jack","Queen","King","Ace"
    };

    for (const std::string& suit : suits) {
        for (int i = 0; i < 13; ++i) {
            std::string rank = ranks[i];
            int value;

            if (i <= 7) {          // 2–9
                value = i + 2;
            } else if (i <= 10) {  // 10, J, Q, K
                value = 10;
            } else {               // Ace
                value = 11;
            }

            m_cardDeck.emplace_back(suit, rank, value);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(m_cardDeck.begin(), m_cardDeck.end(), gen);
}

Card Deck::dealCard() {
    Card temp = m_cardDeck.back();
    m_cardDeck.pop_back();
    return temp;
}

int Deck::getCount() const {
    return static_cast<int>(m_cardDeck.size());
}

