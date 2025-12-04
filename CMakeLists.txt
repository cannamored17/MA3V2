cmake_minimum_required(VERSION 4.0)
project(MA3V2)

set(CMAKE_CXX_STANDARD 20)

add_executable(MA3V2 main.cpp
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Hand.cpp
        Hand.h
        Game.cpp
        Game.h)
