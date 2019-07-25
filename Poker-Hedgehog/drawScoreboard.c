/*
drawScoreboard.c
Takes in cards and paints them onto screen.

Author: Tim Roller, Mallory Russell, Joseph Helland
History:
Tim did original scoreboard
Mallory reorganized
Joseph Added the constants and the current score listing
*/

#include "pokerHeader.h"

/*
Draws the score listings and current score.
*/
void drawScoreboard(int playerScore)
{
  short x = SCORE_LIST_ROW_OFFSET;
  short y = SCORE_LIST_COL_OFFSET;
  short i = 1;

  //draws hedgie
  drawHedgehog();
  //draws a bright blue background box before drawing the scoreboard.
  bon();
  COLOR_SCORE_LIST;
  for (y = SCORE_LIST_COL_OFFSET; y < SCORE_LIST_MAX_COL + SCORE_LIST_COL_OFFSET; y++) {
    for (x = SCORE_LIST_ROW_OFFSET; x < SCORE_LIST_MAX_ROW + SCORE_LIST_ROW_OFFSET; x++) {
      xya(i + x, SCORE_LIST_ROW_TWO - 1 + y);
      putc(ALPHA_CHAR, stdout);
    }
  }
  bon();
  //Draw the border of the score list and current score section
  boxEX(i + SCORE_LIST_ROW_OFFSET, SCORE_LIST_ROW_TWO - 1 + SCORE_LIST_COL_OFFSET, SCORE_LIST_HORIZONTAL_BAR, SCORE_LIST_MAX_COL, COLOR_SCORE_LIST_BORDER);
  boxEX(i + SCORE_LIST_ROW_OFFSET, SCORE_LIST_ROW_TWO - 1 + SCORE_LIST_COL_OFFSET, SCORE_LIST_MAX_ROW, SCORE_LIST_MAX_COL, COLOR_SCORE_LIST_BORDER);
  //draw the current score on the box
  xya(CUR_SCORE_ROW, CUR_SCORE_COL);
  printf("Your Current Score: %d", playerScore);
  //draw the score listings
  xya(++i + SCORE_LIST_ROW_OFFSET, SCORE_LIST_ROW_TWO + SCORE_LIST_COL_OFFSET);
  printf("Royal Flush      2000 * ");
  printf("Straight          200");
  xya(++i + SCORE_LIST_ROW_OFFSET, SCORE_LIST_ROW_TWO + SCORE_LIST_COL_OFFSET);
  printf("Straight Flush   1000 * ");
  printf("Three of a Kind   150");
  xya(++i + SCORE_LIST_ROW_OFFSET, SCORE_LIST_ROW_TWO + SCORE_LIST_COL_OFFSET);
  printf("Four of a Kind   500  * ");
  printf("Two Pair          100");
  xya(++i + SCORE_LIST_ROW_OFFSET, SCORE_LIST_ROW_TWO + SCORE_LIST_COL_OFFSET);
  printf("Full House       400  * ");
  printf("Jacks or Better   50");
  xya(++i + SCORE_LIST_ROW_OFFSET, SCORE_LIST_ROW_TWO + SCORE_LIST_COL_OFFSET);
  printf("Flush            250  * ");
  printf("Loser            -50");
  COLOR_SCHEME;
  bof();
}