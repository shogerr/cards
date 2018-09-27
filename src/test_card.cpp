#include "card.hpp"
#include <cassert>
#include <vector>

using namespace playing_cards;

void test_card() {
    Card::Suit suit = Card::SPADES;
    int value = 9;

    Card* card = new Card(suit, value);

    assert(card->value() == value);
    assert(card->suit() == suit);

    std::vector<Card> cards;

    std::vector<Card::Suit> suits = { 
        Card::SPADES,
        Card::CLUBS,
        Card::HEARTS,
        Card::DIAMONDS
    };

    int card_min = 1;
    int card_max = 13;

    for (auto s : suits)
        for (int i = card_min; i <= card_max; i++)
            cards.push_back(Card{s, i});

    for (auto c : cards)
        std::cout << c << std::endl;
}

int main(void) {
    test_card();
}
