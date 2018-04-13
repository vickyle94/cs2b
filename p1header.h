#ifndef P1HEADER_H
#define P1HEADER_H
#include <string>
using namespace std;

class Card{
//public functions
public:
    //create Suit enum with variables:clubs, diamonds, hearts, spades inside class prototype
    enum Suit { clubs, diamonds, hearts, spades };
    //static constants for default variables
    static const char DFLT_VAL;
    static const Suit DFLT_SUIT;
    static const string LEGAL_VALS;
    //contructor
    Card(char value = 'A', Suit suit = spades);
    //contructor call setter functions, don't need individual mutators for value or suit
    bool set(char value, Suit suit);
            //if input value invalid -  bool errorFlag = true
    //display card
    string toString();
            //if errorFlag == true, print out "invalid card"
    //Getters
    char getVal();
    Suit getSuit();
    bool getErrorFlag();
            
    //bool equals(Card card): will return true if all fields are FALSE (valid)
//private functions:
private:
    //helper function that returns true or false: static bool isValid(char value, Suit suit)
    static bool isValid (char value, Suit suit);
        //only need to test value 
//define three private data members: char value, Suit suit, bool errorFlag
    char value;
    Suit suit;
    bool errorFlag;
};

//hand prototypes
class Hand{
public:
    static const int MAX_CARDS = 30;  //max number of cards in hand
    void resetHand(); //remove all cards in hand
    bool takeCard(Card card); //add valid card to next position in myCards array if there is space
    Card playCard(); //returns and removes the top card (the card in last position)from the hand
    string toString(); //stringizer to display entire hand
    int getNumCards();  //getter for numCards
    Card inspectCard(int k);    //getters for individual card. if k is invalid, will return card with errorFlag = true

private:
    Card myCards[MAX_CARDS];
    int numCards;






};
#endif
