#include "deck.hpp"
#include <vector>
#include <tuple>
#include <cassert>
#include <typeinfo>

std::ostream& operator<<(std::ostream& out, const std::pair<int, int> v) {
    out << v.first << " " << v.second << std::endl;
    return out;
}

std::vector<std::pair<int, int>> create_deck() {
    std::vector<std::pair<int, int>> cards;

    for (int j = 0; j < 4; j++)
        for (int i = 1; i <= 13; i++)
            cards.push_back(std::make_pair(j,i));

    return cards;
}

void test_deck() {
    int suit_count = 4;
    int min = 1;
    int max = 13;

    Deck* deck = new Deck(suit_count, min, max);
    std::cout << *deck;

    assert((suit_count * (max-min+1)) == deck->size());

    std::vector<std::pair<int, int>> _deck = create_deck();

    for (int i = 0; i < 52; i++) {
        assert(_deck.at(i).first == deck->get(i).suit());
        assert(_deck.at(i).second == deck->get(i).value());
    }

    deck->shuffle();

    std::cout << *deck;
}

int main(void) {
    test_deck();
    std::cout << create_deck()[0];
}
