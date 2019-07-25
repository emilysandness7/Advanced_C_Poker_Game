/*
paintHandMER.c
Takes in cards and paints them onto screen.

Author: Mallory Russell
History:
03 Mar 2016 - Initial design.
*/

#include "pokerHeader.h"

void paintHandMER(CARD hand[], bool * discard, int runcount)
{
  int i = 0; // Used to flip through cards in hand
  int x = CARD_OFFSET; // Used for

  for (i = 0; i < 5; i++)
  {
    if (hand[i].cardSuit == 0 || hand[i].cardSuit == 1) // Is it a red card?
    {
      drawCard(CARD_ROW_OFFSET, x + CARD_COLUMN_DRAW, FORE_RED, BACK_WHITE, hand[i]);
    }
    else // It's not red, it's a black card.
    {
      drawCard(CARD_ROW_OFFSET, x + CARD_COLUMN_DRAW, FORE_BLACK, BACK_WHITE, hand[i]);
    }
    x = x + CARD_COLUMN_OFFSET; // We contine pushing the cards to the right
  }
  //bottom border banner under cards
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FORE_BLUE | BACK_GREEN);
  for (i = 0; i <= SCREEN_COL_COUNT; i++) {
    xya(BORDER_BOTTOM, i);
    putc(SOLID_CHAR, stdout);
  }
  COLOR_SCHEME;
  if (runcount == 1)
  {
    selectDiscardsTJR(discard, hand);
  }

  xya(SCREEN_ROW_COUNT, SCREEN_ROW_COUNT);
  return;
}
