/*
createDeckEGS.c
Creates a deck of 52 cards (unshuffled).

Author: Emily Sandness
History:
02 Mar 2016 - Initial Version.
03 Mar 2016 - Fixed create bug.
*/

#include "pokerHeader.h"

/*
Creates a deck of 52 cards in order.

Assumes that a deck is not created already.
If a deck passed in aleady has cards then all existing
cards are replaced.
*/
void createDeckEGS(CARD deck[]) {
  short i;

  //create each card in order
  for (i = 0; i < CARDS_IN_DECK; i++) {

    //create the face of the card (1-13)
    deck[i].cardFace = (i % CARDS_IN_SUIT) + 1;
    //create the suit of the card (0-3)
    deck[i].cardSuit = i / CARDS_IN_SUIT;
  }
}