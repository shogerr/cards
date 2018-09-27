#ifndef __CARD_HPP_
#define __CARD_HPP_

#include <iostream>

namespace playing_cards {

class Card {
public:
    enum Suit {
        SPADES,
        CLUBS,
        HEARTS,
        DIAMONDS
    };

    Card(int suit, int value);
    Card(Suit suit, int value);
    Card(const Card& o);

    ~Card();

    Suit suit() const;
    int value() const;

private:
    Suit suit_;
    int value_;
};

} // namespace playing_cards

std::ostream& operator<<(std::ostream& os, const playing_cards::Card& card);

#endif // __CARD_HPP_
