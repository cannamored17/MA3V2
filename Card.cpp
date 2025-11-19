//
// Created by canna on 10/13/2025.
//
#include<string>

#include "Card.h"


Card::Card() {
    m_rank = "";
    m_value = 0;
    m_suit = "";
}

Card::Card(const std::string &suit, const std::string &rank, const int &value) {
    m_suit = suit;
    m_rank = rank;
    m_value = value;
}

std::string Card::getRank() const{
    return m_rank;
}
int Card::getValue() const {
    return m_value;
}
void Card::setValue(const int value) {
    m_value = value;
}
std::string Card::getCard() const {
    return m_rank + " of " + m_suit;
}
