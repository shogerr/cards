#ifndef __DECK_HPP_
#define __DECK_HPP_

#include "card.hpp"
#include <random>
#include <vector>
#include <iostream>

class Deck {
public:
    Deck();
    Deck(int suit_count, int min, int max);
    Deck(const Deck& cards);

    int size() const;
    Card get(int i) const;
    void shuffle();

private:
    std::random_device rd;
    std::mt19937 mt;

    std::vector<Card> cards_;
};

std::ostream& operator<<(std::ostream& out, const Deck& deck);

#endif // __DECK_HPP_
