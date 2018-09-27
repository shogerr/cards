#include "card.hpp"

namespace playing_cards {

Card::Card(int suit, int value) : suit_((Card::Suit)suit), value_(value) {}

Card::Card(Card::Suit suit, int value) : suit_(suit), value_(value) {}

Card::Card(const Card& o) : suit_(o.suit_), value_(o.value_) {}

Card::~Card() {}

Card::Suit Card::suit() const {
    return suit_;
}

int Card::value() const {
    return value_;
}

} // namespace playing_cards

std::ostream& operator<<(std::ostream& os, const playing_cards::Card& card) {
    os << card.suit() << " " << card.value();
    return os;
}
