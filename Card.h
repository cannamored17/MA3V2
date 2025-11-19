//
// Created by canna on 10/15/2025.
//

#ifndef MA3V2_CARD_H
#define MA3V2_CARD_H
#include <string>


class Card {
private:
    std::string m_suit;
    std::string m_rank;
    int m_value;

public:
    Card();
    Card(const std::string &suit, const std::string &rank, const int &value);

    std::string getRank()const;
    int getValue() const;
    void setValue(int value);
    std::string getCard() const;
};


#endif //MA3V2_CARD_H