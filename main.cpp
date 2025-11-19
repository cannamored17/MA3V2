#include <iostream>
#include "Deck.h"
#include "Hand.h"

int main() {
    Deck deck;
    Hand playerHand;
    Hand dealerHand;


    int initialDeckCount = deck.getCount();

    // Deal cards
    playerHand += deck.dealCard();
    playerHand += deck.dealCard();
    dealerHand += deck.dealCard();  // up
    dealerHand += deck.dealCard();  // down



    std::cout << "-\n";
    std::cout << "-\n";
    std::cout << "-\n";
    std::cout << playerHand.displayCard(0) << "\n";
    std::cout << playerHand.displayCard(1) << "\n";
    std::cout << dealerHand.displayCard(0) << "\n";
    std::cout << dealerHand.displayCard(1) << "\n";


    std::cout << "----------------------------\n";


    std::cout << "Number of cards in deck: " << initialDeckCount << "\n";
    std::cout << "Cards in player hand " << playerHand.cardCount() << "\n";
    std::cout << "Cards in dealer hand " << dealerHand.cardCount() << "\n";
    std::cout << "Number of cards in deck: " << deck.getCount() << "\n";

    // Dealer's up card
    std::cout << "\nDealer's Up Card:\n"
              << dealerHand.displayCard(0) << "\n";

    // Player's cards
    std::cout << "\nPlayer's Cards:\n";
    playerHand.displayAllCards();

    // Dealer's down card
    std::cout << "\nDealer's Down Card:\n"
              << dealerHand.displayCard(1) << "\n";

    // Points
    std::cout << "\nPlayer Points: " << playerHand.getPoints() << "\n";
    std::cout << "Dealer Points: " << dealerHand.getPoints() << "\n";

    return 0;
}

