#ifndef MA3V2_GAME_H
#define MA3V2_GAME_H

#include "Deck.h"
#include "Hand.h"
#include <string>

class Game {
private:
    Deck m_deck;
    Hand m_dealerHand;
    Hand m_playerHand;

    bool isBlackjack(const Hand& hand) const;
    void displayCards(const Hand& hand, const std::string& owner) const;
    void displayRound() const;

public:
    Game();


    Hand getPlayerHand(Deck& deck, Hand& hand);
    Hand getDealerHand(Deck& deck, Hand& hand);
    void playGame();
};

#endif // MA3V2_GAME_H
