/*
pokerHeader.h
Contains header files, constants, macros, and function prototypes
for the poker program.

Authors: Joseph helland, Mallory Russell, Emily Sandness, Tim Roller
Version .01

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "pokerInitializations.h"

//define macros
#define PAUSE printf("\npress any key to continue..."); getchar()
#define FLUSH {int c; while (( c = getchar()) != '\n' && c != EOF);}
#define CLEAR system("cls")

#define CARDS_IN_DECK 52
#define CARDS_IN_SUIT 13
#define CARDS_IN_HAND 4 
#define DEALT 4 //number of cards dealt
#define COLOR_SCHEME SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FORE_WHITE | BACK_GREEN) //default color scheme
#define COLOR_SCORE_LIST SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FORE_WHITE | BACK_BLUE) //score board color
#define COLOR_SCORE_LIST_BORDER (FORE_WHITE|BACK_BLUE)
#define COLOR_HEDGIE (FORE_WHITE|BACK_BRIGHT)
#define SCORE_LIST_COL_OFFSET 60 //score list col offsetter
#define SCORE_LIST_ROW_OFFSET 1 //score list row offsetter
#define CARD_COLUMN_OFFSET 15 //use to define the spacing from top left of card to top left of next card
#define CARD_ROW_OFFSET 17 //vertical define for where the cards are drawn on the screen
#define CARD_COLUMN_DRAW 27 //start location for first card to be drawn at
#define CARD_MOVE_UP 2 //number of rows to move
#define CARD_MOVE_DOWN -2 //number of rows to move
#define CARD_WIDTH 11
#define CARD_HEIGHT 11
#define CARD_OFFSET 5
#define CARD_SELECTOR_ROW (CARD_ROW_OFFSET + 1) // define where the card selector is painted vertically
#define BORDER_BOTTOM 34 //row that the bottom border is drawn at
#define SCREEN_ROW_COUNT 44 //max height of screen
#define SCREEN_COL_COUNT 140 //max width of screen
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define KEY_ESC 27
#define KEY_ENTER 13
#define START_POINTS 2000
#define SOLID_CHAR 219
#define ALPHA_CHAR 255
#define CARD_SELECTOR 30
#define DIR_COL 2 //Directions Column start position: used to define help.c's paint start location
#define DIR_ROW 38 //Directions Row start position: used to define help.c's paint start location
#define CUR_SCORE_COL 94
#define CUR_SCORE_ROW 9
#define SCORE_LIST_MAX_COL 47
#define SCORE_LIST_MAX_ROW 9
#define SCORE_LIST_ROW_TWO 34
#define SCORE_LIST_HORIZONTAL_BAR (SCORE_LIST_MAX_ROW - 2) // defines the location within the score list box to draw the dividing line for current score listing

enum SCORE
{
  SCORE_LOSS = 0,
  SCORE_JACKS = 1,
  SCORE_TWO_PAIR = 2,
  SCORE_THREE_OF_A_KIND = 3,
  SCORE_STRAIGHT = 4,
  SCORE_FLUSH = 5,
  SCORE_FULL_HOUSE = 6,
  SCORE_FOUR_OF_A_KIND = 7,
  SCORE_STRAIGHT_FLUSH = 8,
  SCORE_ROYAL_FLUSH = 9
};

//card struct
typedef struct card
{
  unsigned int cardFace : 4; //face number 1-13 A-K
  unsigned int cardSuit : 2; //suit 0-3 Hearts Diamonds Spades Clubs
} CARD;

//function prototypes 
short compareCardsJNH(CARD, CARD);
void  createDeckEGS(CARD[]);
void  dealCardsEGS(CARD[], CARD[]);
void  drawCard(int, int, int, int, CARD);
void  drawHedgehog(void);
void  drawFace(int, int, int, int);
void  drawScoreboard(int);
void  drawSuitPattern(int face, int suit, int xpos, int ypos);
void  help(int, int, int, int);
void  moveSingleCard(CARD *, int, int);
void  paintHandMER(CARD[], bool *, int);
int   scoreHandJNH(CARD*);
bool  scoreJacksJNH(CARD*);
bool  scoreTwoPairJNH(CARD*);
bool  scoreThreeOfAKindJNH(CARD*);
bool  scoreStraightJNH(CARD*);
bool  scoreFullHouseJNH(CARD*);
bool  scoreFourOfAKindJNH(CARD*);
bool  scoreStraighFlushJNH(CARD*);
bool  scoreRoyalFlushJNH(CARD*);
void  screenSizer(void);
void  selectDiscardsTJR(bool *, CARD[]);
void  shuffleDeckEGS(CARD[]);
void  sortHandJNH(CARD*);
void  titleScreenTJR();
