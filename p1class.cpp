//Card class definitions
#include <string>
#include <iostream>
#include "p1header.h"
using namespace std;

const char Card::DFLT_VAL = 'A';
const Card::Suit Card::DFLT_SUIT = spades;
const string Card::LEGAL_VALS = "A23456789TJQK";

//contructor
Card::Card(char value, Suit suit)
{
    set(value, suit);
   
}

//setter for card
bool Card::set(char value, Suit suit)
{
   // accept lowercase or uppercase
   value = toupper((int)value);
   // check for validity
   if (isValid(value, suit))
   {
    //variable hiding
      this->suit = suit;
      this->value = value;
      this->errorFlag = false;
      return true;
   }
   else
      this->errorFlag = true;
      return false;
}
            //if input value invalid -  bool errorFlag = true
            //if no input arguments passed - set to default parameter (A, spades)
//getters
char Card::getVal()
{
   return value;
}

Card::Suit Card::getSuit()
{
   return suit;
}

bool Card::getErrorFlag()
{
    return errorFlag;
}

//stringizer to display card
string Card::toString()
{
    string retVal; // return value
    //check errorFlag
    if (getErrorFlag()){
        return "Error:Invalid Card";
    }
    char strVal[2]; // create c-string of size 2
    // convert char to a CString
    strVal[0] = value; 
    strVal[1] = '\0'; // add null terminator
    // convert from CString to s-c string
    retVal = string(strVal);
    if (suit == DFLT_SUIT)
        retVal += " of Spades";
    else if (suit == hearts)
        retVal += " of Hearts";
    else if (suit == diamonds)
        retVal += " of Diamonds";
    else if (suit == clubs)
        retVal += " of Clubs";

    return retVal;
}

// //isValid helper function
// a static helper method that returns true or false, depending on the legality of the parameters. 
//  Note that, although it may be impossible for suit to be illegal (due to its enum-ness), we pass it, 
//  anyway, in anticipation of possible changes to the type from enum to, say, char or int, someday.  
//  We only need to test value, at this time.
bool Card::isValid(char value, Suit suit){
    //check if value is legal
    if (LEGAL_VALS.find(value) == string::npos) {
        return false;
    }
    return true;
}

//end of Card implementation------------------

//start Hand implementation-------------------
//default constructor that does what?


//remove all cards from hand
void Hand::resetHand()
{
    //set numCards to 0
    this->numCards = 0;

}


bool Hand::takeCard(Card card)
{
    //if Card is valid and if MAX_CARDS is not met
    if (card.getErrorFlag() == false && getNumCards() < MAX_CARDS){
         //add card to next index in array
        myCards[numCards] = card;
        numCards++;
    } else if (getNumCards() >= MAX_CARDS){
        return false;
    }
        //return true even if card is invalid (will not add card
    return true;
}

Card Hand::playCard()
{
    //return and remove last filled element in Hand array
    this->numCards--;
    return myCards[numCards];

}

string Hand::toString()
{
    string listOfCards;
    for (int i = 0; i < numCards; i++){
        listOfCards = listOfCards + myCards[i].toString() + "\n";

    }
    return listOfCards;
}

//Getters
int Hand::getNumCards()
{
    return numCards;
}

Card Hand::inspectCard(int k)
{
    return myCards[k];
}