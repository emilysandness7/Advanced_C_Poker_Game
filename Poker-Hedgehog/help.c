/*
help.c
Prints the game instructions for the player.
*/

#include "pokerHeader.h"

/*
help(startRow, startCol, foreColor, backColor)
prints help list/directions list.

*/
void help(int r, int c, int foreColor, int backColor) {
  int locc = 0;
  int locr = 0;

  //To display properly the console should be set to Raster font 10x18
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreColor | backColor);
  bon();
  xya(locr + r, locc + c);
  printf("Press <A> and <D> to move the selector left and right");
  locr++;
  xya(locr + r, locc + c);
  printf("Press <W> and <S> to select or deselect a card");
  locr++;
  xya(locr + r, locc + c);
  printf("Press <Enter> to re-deal selected cards and score hand");
  locr++;
  xya(locr + r, locc + c);
  printf("Press <ESC> to Quit");
  bof();
  COLOR_SCHEME;
}