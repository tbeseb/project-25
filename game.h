#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"
#include "dealer.h"
#include "UI.h"

class game{
public:
    game();
    void start();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
    void newRound();
private:
    Deck deck;
    Player player;
    Dealer dealer;
    UI ui;
}
#endif
