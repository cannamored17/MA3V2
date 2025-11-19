
#include <string>
#include <random>
#include <algorithm>
#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <ostream>


Deck::Deck() {
    shuffleDeck();
}

void Deck::shuffleDeck() {
    m_cardDeck.clear();

    std::string suits[]= {"Clubs","Diamonds", "Hearts", "Spades"};
    std::string ranks[]= { "2", "3", "4", "5", "6","7",
        "8", "9", "10", "Jack", "Queen", "King","Ace"};
    int values[]= { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10,10,10,11};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card temp(suits[i],ranks[j],values[j]);
            m_cardDeck.push_back(temp);

        }

    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(m_cardDeck.begin(),m_cardDeck.end(),gen);
    // Test Code
    for (auto i: m_cardDeck) {
        std::cout << i.getCard()<< std::endl;

    }
}
Card Deck::dealCard() {
    Card temp= m_cardDeck.back();
    m_cardDeck.pop_back();
    return temp;
}
int Deck::getCount() const {
    return m_cardDeck.size();
}