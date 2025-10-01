#include <iosteam>
#include "game.h"
#include "deck.h"
#include "player.h"

using namespace std;

Game:Game() {
    deck.shuffle();
}

void Game::play() {
    bool keepPlaying = true;

    while (keepPlaying) {
        newRound();
        playerTurn();
        dealerTurn();
        determineWinner();
        keepPlaying = ui.askPlayAgain();
    }
}

void Game::newRound() {
    player.clearHand();
    dealer.clearHand();
    if (deck.isEmpty()) {
        deck = deck();
        deck.shuffle();
    }

    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
}

void Game::playerTurn() {
    bool playerBusted = false;
    while (true) {
        ui.displayHands(player, dealer, false);
        if (player.getHandValue() == 21) {
            cout << "Blackjack! You have 21." << endl;
            break;
        }
        if (player.getHandValue() > 21) {
            cout << "Bust! You exceeded 21." << endl;
            playerBusted = true;
            break;
        }
        if (ui.askHitOrStand()) {
            player.addCard(deck.dealCard());
        } else {
            break;
        }
    }
}

void Game::dealerTurn() {
   ui.showDealerHand(dealer);

   while (dealer.getHandValue() < 17) {
       dealer.addCard(deck.dealCard());
       ui.showDealerHand(dealer);
   }
}

void Game::determineWinner() {
    int playerValue = player.getHandValue();
    int dealerValue = dealer.getHandValue();

    ui.displayHands(player, dealer, true);

    if (playerValue > 21) {
        cout << "You busted! Dealer wins." << endl;
    } else if (dealerValue > 21) {
        cout << "Dealer busted! You win!" << endl;
    } else if (playerValue > dealerValue) {
        cout << "You win!" << endl;
    } else if (playerValue < dealerValue) {
        cout << "Dealer wins." << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}
