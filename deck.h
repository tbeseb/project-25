#ifndef DECK_H
#define DECK_H

#include <vector>
#include <stdexcept>

class Card {
    public:
        enum Suit { Hearts, Diamonds, Clubs, Spades };
        enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
        explicit Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}
        Suit getSuit() const { return suit; }
        Rank getRank() const { return rank; } 
    private: 
        Suit suit;
        Rank rank;
};

class Deck {
public:
    Deck();
    void shuffle();
    Card dealCard();
    bool isEmpty() const;
private:
    std::vector<Card> cards;
};

#endif
