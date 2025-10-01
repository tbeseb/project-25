#include <iostream>
#include "game.h"
#include "deck.h"
#include "player.h"

using namespace std;

game::game() {
    deck.shuffle();
}

void game::start() {
    bool keepPlaying = true;

    while (keepPlaying) {
        newRound();
        playerTurn();
        dealerTurn();
        determineWinner();
        
        char choice;
        cout << "Play again? (y/n): ";
        cin >> choice;
        keepPlaying = (choice =='y' || choice == 'Y');
    }
}

void game::newRound() {
    player.clearHand();
    dealer.clearHand();
    if (deck.isEmpty()) {
        deck = Deck();
        deck.shuffle();
    }

    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    cout << "Dealer shows: " << dealer.getHand()[0].getRank() << endl;
    cout << Player hand value: " << player.getHandValue() << endl;"
}

void game::playerTurn() {
    bool hit = true;
    while (hit && player.getHandValue() < 21) {
        cout << "Hit or Stand? (h/s): ";
        char choice;
        cin >> choice;
        if (choice == 'h' || choice == 'H') {
            player.addCard(deck.dealCard());
            cout << "Player hand value: " << player.getHandValue() << endl;
        } else {
            hit = false;
        }
    }
}

void game::dealerTurn() {
   cout << "Dealer turn..." << endl;

    while (dealer.getHandValue() < 17) {
        dealer.addCard(deck.dealCard());
    }
    cout << "Dealer hand value: " << dealer.getHandValue() << endl;
}
void game::determineWinner() {
    int playerScore = player.getHandValue();
    int dealerScore = dealer.getHandValue();

    if (playerScore > 21) {
        cout << "Player busts! Dealer wins." << endl;
    } else if (dealerScore > 21) {
        cout << "Dealer busts! Player wins." << endl;
    } else if (playerScore > dealerScore) {
        cout << "Player wins!" << endl;
    } else if (dealerScore > playerScore) {
        cout << "Dealer wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}
