/*
dealCardsEGS.c
Deals 5 cards into the player's hand.

Author: Emily Sandness
History:
03 Mar 2016 - Initial Version.
04 Mar 2016 - Added DEAL_DEBUG output.
*/

#include "pokerHeader.h"

/*
Starts at the top of the deck and draws a card then puts
that card into the hand.

Assumes that there are enough cards in the deck to fill
the hand.
*/
void dealCardsEGS(CARD deck[], CARD hand[]) {
  short i;

  //take the card and put it in the hand
  for (i = 0; i < CARDS_IN_HAND + 1; i++) {
    hand[i] = deck[i];
  }
}
