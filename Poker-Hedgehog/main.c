/*
main.c
Main function of the program. Runs the poker program.

Authors: Joseph helland, Mallory Russell, Emily Sandness, Tim Roller
Version .01
*/

#include "pokerHeader.h"

int main(void) {
  short i;
  short dealt = DEALT;
  int score = 0;
  short tempScore = 0;
  int playerScore = START_POINTS;
  CARD deck[CARDS_IN_DECK];
  CARD hand[5];//need to swap this to CARDS_IN_HAND when it gets fixed
  bool discard[5] = { false };//need to swap this to CARDS_IN_HAND when it gets fixed
  int keyInput; //stores ASCII decimal values of keyboard input

  //prep the screen then show the title screen
  screenSizer();
  COLOR_SCHEME;
  titleScreenTJR();

  //create deck once
  createDeckEGS(deck);

  //play once then keep playing while they haven't hit the ESC key
  do {

    //reset the discard state
    for (i = 0; i <= CARDS_IN_HAND; i++) {
      discard[i] = false;
    }
    //shuffle then deal 5 cards
    shuffleDeckEGS(deck);
    dealCardsEGS(deck, hand);

    //draw the cards and scoreboard on the screen
    clr();
    drawScoreboard(playerScore);
    help(DIR_ROW, DIR_COL, FORE_WHITE, BACKGROUND_GREEN);
    paintHandMER(hand, discard, 1);

    for (i = 0; i < CARDS_IN_HAND + 1; i++) {
      if (discard[i])
      {
        hand[i] = deck[i + 5];
      }

    }
    clr();
    drawScoreboard(playerScore);
    help(DIR_ROW, DIR_COL, FORE_WHITE, BACKGROUND_GREEN);
    paintHandMER(hand, discard, 0);
    bon();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FORE_BLUE | BACK_GREEN);
    for (i = 0; i <= SCREEN_COL_COUNT; i++) {
      xya(BORDER_BOTTOM, i);
      putc(SOLID_CHAR, stdout);
    }
    COLOR_SCHEME;

    //get the score of the hand
    score = scoreHandJNH(hand);

    //update thier score by the value of the hands score
    tempScore = scoreNums[score];
    playerScore = playerScore + tempScore;//needs to be dispayed on the screen!
    COLOR_SCORE_LIST;
    bon();

    //print the current score to the score board
    xya(CUR_SCORE_ROW, CUR_SCORE_COL);
    printf("Your Current Score: %d", playerScore);
    bon();

    //print the message at the bottom letting them know what they got and how much its worth
    xya(36, 50);
    COLOR_SCHEME;
    bon();
    printf("%s!  %d", scoreStrings[score], tempScore);
    keyInput = _getch();

    //Exit if esc is pressed
    if (keyInput == KEY_ESC) {
      exit(0);
    }
  } while (true); //keep playing
}
