/*
drawCard.c
Paints the card onto the screen.

Authors: Joseph helland, Mallory Russell
Version .01
*/

#include "pokerHeader.h"


#define FACE_OFFSET_BORDER_ONE 9
#define FACE_OFFSET_BORDER_TWO 1
#define FACEDRAW_ASCII_OFFSET 3
#define SUIT_OFFSET_BY_A_LITTLE 3
#define SUIT_OFFSET_TO_MIDDLE 5
#define SUIT_OFFSET_BY_A_LOT 7
#define CARD_BACKING (BACK_WHITE| BACK_BRIGHT)

/*
drawCard
This finction takes color selection and a card and draws it to the screen
It draws a different card that is dependant on the cards value.
The xpos and ypos are the row and column to start the draw from as the
top left of the card.
*/
void drawCard(int xpos, int ypos, int foreColor, int backColor, CARD card) {
  int x = 0;
  int y = 0;
  /*
  Draw the white background of the card
  */
  xya(xpos, ypos);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FORE_WHITE | CARD_BACKING);
  for (y = 0; y < CARD_WIDTH; y++) {
    for (x = 0; x < CARD_HEIGHT; x++) {
      xya(xpos + x, ypos + y);
      putc(ALPHA_CHAR, stdout);
    }
  }
  /*
  draw the face of the card on the white background
  */
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)foreColor | CARD_BACKING);
  drawFace(card.cardFace, card.cardSuit, xpos, ypos);
  COLOR_SCHEME;
  return;
}

void drawFace(int face, int suit, int xpos, int ypos) {
  //need a special draw for a 10 as it takes two char slots to display
  if (face == 10) {
    //draw 1's on the card
    xya(xpos + FACE_OFFSET_BORDER_TWO, ypos + FACE_OFFSET_BORDER_TWO);
    putc(faceASCII[face], stdout);
    xya(xpos + FACE_OFFSET_BORDER_ONE, ypos + FACE_OFFSET_BORDER_TWO);
    putc(faceASCII[face], stdout);
    xya(xpos + FACE_OFFSET_BORDER_ONE, ypos + FACE_OFFSET_BORDER_ONE - 1);
    putc(faceASCII[face], stdout);
    xya(xpos + FACE_OFFSET_BORDER_TWO, ypos + FACE_OFFSET_BORDER_ONE - 1);
    putc(faceASCII[face], stdout);
    //draw 0's on the card
    xya(xpos + FACE_OFFSET_BORDER_TWO, ypos + FACE_OFFSET_BORDER_TWO + 1);
    putc(faceASCII[0], stdout);
    xya(xpos + FACE_OFFSET_BORDER_ONE, ypos + FACE_OFFSET_BORDER_TWO + 1);
    putc(faceASCII[0], stdout);
    xya(xpos + FACE_OFFSET_BORDER_ONE, ypos + FACE_OFFSET_BORDER_ONE);
    putc(faceASCII[0], stdout);
    xya(xpos + FACE_OFFSET_BORDER_TWO, ypos + FACE_OFFSET_BORDER_ONE);
    putc(faceASCII[0], stdout);
  }
  else {
    //draw the face on the card
    xya(xpos + FACE_OFFSET_BORDER_TWO, ypos + FACE_OFFSET_BORDER_TWO);
    putc(faceASCII[face], stdout);
    xya(xpos + FACE_OFFSET_BORDER_ONE, ypos + FACE_OFFSET_BORDER_TWO);
    putc(faceASCII[face], stdout);
    xya(xpos + FACE_OFFSET_BORDER_ONE, ypos + FACE_OFFSET_BORDER_ONE);
    putc(faceASCII[face], stdout);
    xya(xpos + FACE_OFFSET_BORDER_TWO, ypos + FACE_OFFSET_BORDER_ONE);
    putc(faceASCII[face], stdout);
  }
  //draw card suit in the 4 corners
  xya(xpos + FACE_OFFSET_BORDER_TWO + 1, ypos + FACE_OFFSET_BORDER_TWO);
  putc(suitASCII[suit], stdout);
  xya(xpos + FACE_OFFSET_BORDER_ONE - 1, ypos + FACE_OFFSET_BORDER_TWO);
  putc(suitASCII[suit], stdout);
  xya(xpos + FACE_OFFSET_BORDER_ONE - 1, ypos + FACE_OFFSET_BORDER_ONE);
  putc(suitASCII[suit], stdout);
  xya(xpos + FACE_OFFSET_BORDER_TWO + 1, ypos + FACE_OFFSET_BORDER_ONE);
  putc(suitASCII[suit], stdout);
  drawSuitPattern(face, suit, xpos, ypos);
  return;
}

// Written by Mallory
// This function draws the suit type in
// pattern typically displayed on card
void drawSuitPattern(int face, int suit, int xpos, int ypos)
{
  switch (face)
  {
  case 1:
    // Displays to middle of card
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    return;

  case 2:
    // Displays to top middle
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    // Displays to top bottom
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    return;

  case 3:
    // Displays to top middle
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    // Displays to middle of card
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    // Displays to top bottom
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    return;

  case 4:
    // Top left
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Top right
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Bottom left
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Bottom right
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    return;

  case 5:
    // Top left
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Top right
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Displays to middle of card
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    // Bottom left
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Bottom right
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    return;

  case 6:
    // Top left
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Top right
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Bottom left
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Bottom right
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Middle left
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Middle right
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    return;

  case 7:
    // Top left
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Top right
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Bottom left
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Bottom right
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Middle left
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Middle right
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Middle of card, slightly higher
    xya(xpos + SUIT_OFFSET_TO_MIDDLE - 1, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    return;

  case 8:
    // Top left
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Top right
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Bottom left
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Bottom right
    xya(xpos + SUIT_OFFSET_BY_A_LOT, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Middle left
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Middle right
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Middle of card, slightly higher
    xya(xpos + SUIT_OFFSET_TO_MIDDLE - 1, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    // Middle of card, slightly lower
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    return;

  case 9:
    // Top left
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE - 1, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Top right
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE - 1, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Bottom left
    xya(xpos + SUIT_OFFSET_BY_A_LOT + 1, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Bottom right
    xya(xpos + SUIT_OFFSET_BY_A_LOT + 1, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Upper Middle left
    xya(xpos + SUIT_OFFSET_TO_MIDDLE - 1, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Lower Middle left
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Upper Middle right
    xya(xpos + SUIT_OFFSET_TO_MIDDLE - 1, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Lower Middle right
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Middle of card, slightly higher
    xya(xpos + SUIT_OFFSET_TO_MIDDLE - 2, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    return;

  case 10:
    // Top left
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE - 1, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Top right
    xya(xpos + SUIT_OFFSET_BY_A_LITTLE - 1, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Bottom left
    xya(xpos + SUIT_OFFSET_BY_A_LOT + 1, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Bottom right
    xya(xpos + SUIT_OFFSET_BY_A_LOT + 1, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Upper Middle left
    xya(xpos + SUIT_OFFSET_TO_MIDDLE - 1, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Lower Middle left
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_BY_A_LITTLE);
    putc(suitASCII[suit], stdout);
    // Upper Middle right
    xya(xpos + SUIT_OFFSET_TO_MIDDLE - 1, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Lower Middle right
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_BY_A_LOT);
    putc(suitASCII[suit], stdout);
    // Middle of card, slightly higher
    xya(xpos + SUIT_OFFSET_TO_MIDDLE - 2, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    // Middle of card, slightly lower
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 2, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(suitASCII[suit], stdout);
    return;

  case 11: // Jack
    // Displays a crown
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE - 2);
    putc(191, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE + 2);
    putc(218, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(210, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(202, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE - 1);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE + 1);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE - 2);
    putc(212, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE + 2);
    putc(190, stdout);
    return;

  case 12: // Queen
    // Upper piece
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE - 3);
    putc(197, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(210, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE + 3);
    putc(197, stdout);
    // Middle piece
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(202, stdout);
    // Two side bottom pieces
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE - 1);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE + 1);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE - 2);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE + 2);
    putc(205, stdout);
    // Bottom corners
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE - 3);
    putc(212, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE + 3);
    putc(190, stdout);
    return;

  case 13: // King
    // Displays a crown
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE - 3);
    putc(198, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE + 3);
    putc(181, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE - 1);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE + 1);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE - 2);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE + 2);
    putc(205, stdout);
    //Middle piece upper
    xya(xpos + SUIT_OFFSET_TO_MIDDLE, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(206, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE - 1, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(210, stdout);
    // Middle piece
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE);
    putc(202, stdout);
    // Two side bottom pieces
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE - 1);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE + 1);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE - 2);
    putc(205, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE + 2);
    putc(205, stdout);
    // Bottom corners
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE - 3);
    putc(212, stdout);
    xya(xpos + SUIT_OFFSET_TO_MIDDLE + 1, ypos + SUIT_OFFSET_TO_MIDDLE + 3);
    putc(190, stdout);
    return;
  }
  return;
}