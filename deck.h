#ifndef DECK_H
#define DECK_H

class Card {
    public:
        enum Suit { Hearts, Diamonds, Clubs, Spades };
        enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
        Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}
        Suit getSuit() const { return suit; }
        Rank getRank() const { return rank; } 
    private: 
        Suit suit;
        Rank rank;
};

#endif
