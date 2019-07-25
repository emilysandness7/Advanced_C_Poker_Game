/*
moveSingleCard.c
Takes a card in and moves it up or down by repainint over the top and bottom positions and repainting
the card in the new position

Author: Joseph Helland
*/

#include "pokerHeader.h"

/*
should be able to handle redrawing over old card no matter whether it was up or down
call it with how you want the card to move and it will use that as an offset for where
to blank out and then move the card that many rows.
+ to move up
- to move down //not fully compatible. functionality for this feature was removed.
0 to redraw at original location
*/
void moveSingleCard(CARD *cardToMove, int cardNum, int upDown) {
  /*
  take the offset of the incomming card as a multiplier of the cards position
  i.e. hand[0]'s offset is x0 hand[1]'s offset is x1
  offset is width of card + buffer to next card
  currently that offset is 15
  */
  int color = 0;
  int y;
  int x;

  /*
  define the color of the card to draw before passing it to drawCard
  */
  if (cardToMove->cardSuit > 1) {
    color = FORE_BLACK;
  }
  else {
    color = FORE_RED;
  }

  /*
  erase the old cards top and bottom. This makes the repaint act like a complete repaint of the area with less
  painting.
  */
  COLOR_SCHEME;
  //erase the top most position that will not be painted over (2 rows higher than card draws base height)
  for (x = 0; x < 2; x++) {
    for (y = 0; y < CARD_WIDTH; y++) {
      xya(CARD_ROW_OFFSET + x + CARD_MOVE_DOWN, (CARD_COLUMN_OFFSET * cardNum) + CARD_COLUMN_DRAW + y + CARD_OFFSET);
      putc(ALPHA_CHAR, stdout);
    }
    //erase the bottom most position that will not be painted over (2 bottom rows of draw cards base draw area)
    for (y = 0; y < CARD_WIDTH; y++) {
      xya(CARD_ROW_OFFSET + x + CARD_MOVE_DOWN + CARD_HEIGHT, (CARD_COLUMN_OFFSET * cardNum) + CARD_COLUMN_DRAW + y + CARD_OFFSET);
      putc(ALPHA_CHAR, stdout);
    }
  }
  /*
  draw the card in the new position
  */
  drawCard(CARD_ROW_OFFSET - upDown, (CARD_COLUMN_OFFSET * cardNum) + CARD_COLUMN_DRAW + CARD_OFFSET, color, BACK_WHITE, *cardToMove);
  //Reset our color pallete
  COLOR_SCHEME;
}