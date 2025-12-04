#include "Game.h"
#include <iostream>
#include <cctype>

Game::Game() = default;

bool Game::isBlackjack(const Hand& hand) const {
    return (hand.cardCount() == 2 && hand.getPoints() == 21);
}

Hand Game::getPlayerHand(Deck& deck, Hand& hand) {
    hand.clearHand();
    hand += deck.dealCard();
    hand += deck.dealCard();
    return hand;
}

Hand Game::getDealerHand(Deck& deck, Hand& hand) {
    hand.clearHand();
    hand += deck.dealCard();
    hand += deck.dealCard();
    return hand;
}

void Game::displayCards(const Hand& hand, const std::string& owner) const {
    std::cout << owner << " Cards:\n";
    hand.displayAllCards();
    std::cout << '\n';
}

void Game::displayRound() const {
    std::cout << "\nYour Points:\t"     << m_playerHand.getPoints()  << '\n';
    std::cout << "Dealer's Points:\t"   << m_dealerHand.getPoints() << '\n';
}

void Game::playGame() {
    // Title block – matching the screen capture
    std::cout << "###########################\n";
    std::cout << "#  The Game of Blackjack  #\n";
    std::cout << "###########################\n\n";

    char again = 'y';

    while (again == 'y' || again == 'Y') {


        if (m_deck.getCount() < 15) {
            m_deck = Deck();
        }

        getPlayerHand(m_deck, m_playerHand);
        getDealerHand(m_deck, m_dealerHand);

        std::cout << "Dealer's Show Card:\n";
        std::cout << m_dealerHand.displayCard(0) << "\n\n";


        std::cout << "Your Cards:\n";
        m_playerHand.displayAllCards();
        std::cout << '\n';

        bool playerBlackjack = isBlackjack(m_playerHand);
        bool dealerBlackjack = isBlackjack(m_dealerHand);
        bool playerBusted = false;


        if (playerBlackjack || dealerBlackjack) {
            displayRound();

            if (playerBlackjack && dealerBlackjack) {
                std::cout << "Dang, dealer has blackjack too. You push.\n";
            } else if (playerBlackjack && !dealerBlackjack) {
                std::cout << "Blackjack! You win!\n";
            } else if (!playerBlackjack && dealerBlackjack) {
                std::cout << "Dealer has Blackjack. You lose.\n";
            } else {

            }
        } else {


            char choice;
            while (true) {
                std::cout << "hit or stand? (h/s): ";
                std::cin >> choice;
                choice = static_cast<char>(std::tolower(choice));

                if (choice == 'h') {
                    m_playerHand += m_deck.dealCard();
                    std::cout << "\nYour Cards:\n";
                    m_playerHand.displayAllCards();
                    std::cout << '\n';

                    if (m_playerHand.getPoints() > 21) {
                        playerBusted = true;
                        break;
                    }
                } else if (choice == 's') {
                    break;
                } else {

                }
            }


            if (playerBusted) {
                displayRound();
                std::cout << "Sorry. You busted. You lose.\n";
            } else {

                std::cout << "\nDealer's Cards:\n";

                while (m_dealerHand.getPoints() < 17) {
                    m_dealerHand += m_deck.dealCard();
                }

                m_dealerHand.displayAllCards();
                std::cout << '\n';

                int playerPoints = m_playerHand.getPoints();
                int dealerPoints = m_dealerHand.getPoints();
                bool dealerBusted = (dealerPoints > 21);

                std::cout << "Your Points:\t"     << playerPoints << '\n';
                std::cout << "Dealer's Points:\t" << dealerPoints << '\n';

                if (dealerBusted) {
                    std::cout << "Yay! The dealer busted. You win!\n";
                } else if (playerPoints > dealerPoints) {
                    std::cout << "Hooray! You win!\n";
                } else if (playerPoints < dealerPoints) {
                    std::cout << "Sorry. You lose.\n";
                } else {
                    std::cout << "It's a tie! You push.\n";
                }
            }
        }

        std::cout << "\nplay another round? (y/n): ";
        std::cin >> again;
        again = static_cast<char>(std::tolower(again));
        std::cout << "\n";
    }

    std::cout << "Thanks for playing!\n";
}


