#include <iostream>
#include "Deck.h"

int main() {
    Deck myDeck;
    std::cout << std::endl << myDeck.getCount() << std::endl;
    std::cout << std::endl << myDeck.dealCard().getCard() << std::endl;
    std::cout << std::endl << myDeck.getCount() << std::endl;
    std::cout << std::endl << myDeck.dealCard().getCard() << std::endl;
    std::cout << std::endl << myDeck.getCount() << std::endl;
    return 0;
}