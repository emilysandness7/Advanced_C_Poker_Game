/*
selectDiscardsTJR.c
Takes in cards and paints them onto screen.

Authors: Timothy Roller, Joseph Helland
History:
05 Mar 2016 - Initial design.
*/

#include "pokerHeader.h"

#define PLACE_BENEATH_CARDS 12

void selectDiscardsTJR(bool * cardOneTest, CARD hand[])
{
  //int x = 10;
  int choice = 1;
  int i;
  int keyPressed = 0;
  bool up = false;
  bool down = false;

  while (true) {
    //go left
    if (keyPressed == KEY_A) {
      if (choice == 1) {
        choice = CARDS_IN_HAND + 1;
      }
      else {
        choice--;
      }
    }
    //go right
    else if (keyPressed == KEY_D) {
      if (choice == CARDS_IN_HAND + 1) {
        choice = 1;
      }
      else {
        choice++;
      }
    }
    //erase all positions for the arrow then redraw it in the right spot
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FORE_WHITE | BACK_GREEN);
    bon();
    for (i = 1; i < 6; i++) {
      xya(PLACE_BENEATH_CARDS + CARD_ROW_OFFSET, (CARD_COLUMN_DRAW)+(CARD_COLUMN_OFFSET * i) - CARD_OFFSET);
      putc(ALPHA_CHAR, stdout);
    }
    // ASCII for arrow
    xya(PLACE_BENEATH_CARDS + CARD_ROW_OFFSET, (CARD_COLUMN_DRAW)+(CARD_COLUMN_OFFSET * choice) - CARD_OFFSET);
    putc(CARD_SELECTOR, stdout);
    COLOR_SCHEME;
    if (up) {
      if (cardOneTest[choice - 1] == false) {
        cardOneTest[choice - 1] = true;
        moveSingleCard(&hand[choice - 1], choice - 1, CARD_MOVE_UP);
      }
    }
    else if (down) {
      if (cardOneTest[choice - 1] == true) {
        cardOneTest[choice - 1] = false;
        moveSingleCard(&hand[choice - 1], choice - 1, 0);
      }
    }
    up = false;
    down = false;
    //what key was pressed?
    keyPressed = _getch();
    if (keyPressed == KEY_ENTER) {
      return;
    }
    else if (keyPressed == KEY_ESC) {
      exit(0);
    }
    else if (keyPressed == KEY_W) {
      up = true;
    }
    else if (keyPressed == KEY_S) {
      down = true;
    }
  }
}
