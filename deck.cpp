#include "deck.h"
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

Deck::Deck() {
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 2; rank <= 14; ++rank) {
            cards.emplace_back(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
        }
    }
}

void Deck::shuffle() {
    random_device rd;
    mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    ::shuffle(cards.begin(), cards.end(), rng);
}

Card Deck::dealCard() {
    if (cards.empty()) {
        throw out_of_range("No cards left in the deck");
    }
        Card topCard = cards.back();
        cards.pop_back();
        return topCard;
}

bool Deck::isEmpty() const {
    return cards.empty();
}
