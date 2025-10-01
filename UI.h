#ifndef UI_h
#define UI_h
#include "deck.h"
using namespace std;


//Displaying the image (user interface)

void displayHand(const std::vector<Card>& hand, const std::string& playerName)
{
    cout << playerHand << " 's hand:" << endl; 

    for (const auto& card : hand)
    {
        cout << card.getRankString() << " of " << card.getSuitString() << ", ";
    }
    cout << endl;
}






#endif
