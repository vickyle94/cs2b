#include <string>
#include <iostream>
#include "p1header.h"
using namespace std;


int main(){
//Test for Card Class--------------------------------------------------------

//Instantiate at least three cards, one of them, passing illegal values
    Card card1, 
         card2('3', Card::hearts),
         card3('0');
//display all three cards
    cout << "Displaying three cards: " << endl;
    cout << card1.toString() << endl;
    cout << card2.toString() << endl;
    cout << card3.toString() << endl;
    
// make good card bad using set() with an illegal value
    cout << "This should be invalid: " << endl;
    card1.set('0', Card::spades);
    cout << card1.toString() << endl;

//turn the bad card "good" by setting a legal value, and re-display
    cout << "This should be 4 of clubs : " << endl;
    card1.set('4', Card::clubs);
    cout << card1.toString() << endl;

    cout << "################################################################" << endl;
    cout << "Beginning Hand Testing" << endl;
    cout <<  "##############################################################" << endl;


//Test for Hand Class--------------------------------------------------------
    //create 3 Card objects
    Card card4('5', Card::hearts),
         card5,
         card6('2', Card::diamonds);

    //display 3 cards
    cout << "Card created: " << card4.toString() << endl;
    cout << "Card created: " << card5.toString() << endl;
    cout << "Card created: " << card6.toString() << endl;

    //create 1 Hand object
    Hand hand1;
    //for loop to fill hand1
    for(int i = 0; i < Hand::MAX_CARDS; i++){
        hand1.takeCard(card4);
    }

    //display hand
    cout << "Hand includes: " << hand1.toString() << endl;
    //play each card until hand empty
    for (int i = 0; i < Hand::MAX_CARDS; i++){
        cout << "Move " << i << ": Playing: " << hand1.playCard().toString() << endl;
        // cout << "Playing " << hand1.toString() << endl; 
    }
    //display empty hand after playing all cards
    cout << "After playing all cards\n";
    cout << "Hand = (" << hand1.toString() << ")" << endl;
}
