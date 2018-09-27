#include "deck.hpp"

Deck::Deck() : mt(rd()) {}

Deck::Deck(int suit_count, int min, int max) : Deck() {
    for (int i = 0; i < suit_count; i++)
        for (int j = min; j <= max; j++)
            cards_.push_back(Card{i, j});
}

Deck::Deck(const Deck& o) : cards_(o.cards_) {}

void Deck::shuffle() {
    int j;
    for (int i = cards_.size()-1; i > 0; i-- ) {
        std::uniform_int_distribution<int> dist(0, i);
        j = dist(mt);
        iter_swap(cards_.begin()+j, cards_.begin()+i);
    }
}

int Deck::size() const {
    return cards_.size();
}

Card Deck::get(int i) const {
    return cards_.at(i);
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    out << deck.size() << std::endl;

    for (int i = 0; i < deck.size(); i++)
        out << deck.get(i);

    return out;
}
