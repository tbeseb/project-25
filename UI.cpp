#include "UI.h"  

#include <iostream>
using namespace std; 

int main()
{
    std::vector<Card> playerHand = {Card(Card::Ace, Card::Spades), Card(Card::King, Card::Hearts)};
    displayHand(playerHand, "Player 1");

    std::cout << "Enter your action (bet, call, fold): ";
    std::string action;
    std::cin >> action;
    return 0;
}
