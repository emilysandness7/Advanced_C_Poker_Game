/*
pokerInitialization.h
Initializes card faces and suits, score values, score messages,
and ASCII values for suit and faces.

Authors: Joseph helland, Mallory Russell, Emily Sandness, Tim Roller
Version .01
*/

#include "wincurs.h"

// faces on cards as constant array of strings
// put an empty string in position 0 so index 
// is the # on the card
const char *face[] =
{ "", "Ace", "Two", "Three", "Four",
  "Five", "Six", "Seven", "Eight", "Nine",
  "Ten", "Jack", "Queen", "King" };

// suit on cards, order is arbitrary H,D,S,C
const char *suit[] =
{ "Hearts", "Diamonds",
  "Spades", "Clubs" };

const char *scoreStrings[] =
{ "You Lost",
  "Jacks or Better",
  "Two Pair",
  "Three of a Kind",
  "Straight", "Flush",
  "Full House",
  "Four of a Kind",
  "Straight Flush",
  "Royal Flush" };

//score amounts for various hands synced with the scoreStrings
const short scoreNums[] =
{ -50, 50, 100, 150, 200,
  250, 400, 500, 1000, 2000 };

//ASCII values for (0,A,2,3,4,5,6,7,8,9,1,J,Q,K)
const int faceASCII[] =
{ 48, 65, 50, 51, 52,
  53, 54, 55, 56, 57,
  49, 74, 81, 75 };

//ASCII values for ("Hearts", "Diamonds", "Spades", "Clubs")
const int suitASCII[] =
{ 3, 4, 6, 5 };