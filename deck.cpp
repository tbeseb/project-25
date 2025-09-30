#include "deck.h"
#include <algorithm>
#include <random>
#include <ctime>

Deck::Deck() {
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 2; rank <= 14; ++rank) {
            cards.emplace_back(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::shuffle(cards.begin(), cards.end(), rng);
}

Card dealCard() {
    if (cards.empty()) {
        throw std::out_of_range("No cards left in the deck");
    }
        Card topCard = cards.back();
        cards.pop_back();
        return topCard;
}

bool isEmpty() const {
    return cards.empty();
}
