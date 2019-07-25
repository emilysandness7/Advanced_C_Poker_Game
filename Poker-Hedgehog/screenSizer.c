/*
screenSizer.h
Sets the size of the console. Only called in main.c

Authors: Joseph helland
Version .01
*/

#include "pokerHeader.h"

void setcursor(bool, DWORD);

/*
Takes the console screen and sets it to the proper size and porportions.
I doubt this is fully unix compatiable
*/
void screenSizer() {
  //define the size in characters for the window
  SMALL_RECT winSize = { 0, 0, 139, 44 };

  //define the window's title
  SetConsoleTitle(TEXT("  Hedgehog Poker  "));
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &winSize);

  //make sure we have a writing buffer that is the same size as our screen
  COORD bufferSize = { 140,45 };
  SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);

  //define the resolution area of the window. couldnt find a way to define it relative to character spaces
  SetWindowPos(GetConsoleWindow(), HWND_TOP, 0, 0, 1620, 900, SWP_SHOWWINDOW);

  //make the cursor invisible!
  setcursor(0, 0);
  COLOR_SCHEME;
  clr();
  return;
}

/*
Author: whitenite1 Jan 20, 2013 at 11:59am http://www.cplusplus.com/forum/beginner/90498/
modified slightly by Joseph Helland for hedgehog Poker.
*/
void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
  if (size == 0)
  {
    size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
  }
  CONSOLE_CURSOR_INFO lpCursor;
  lpCursor.bVisible = visible;
  lpCursor.dwSize = size;
  SetConsoleCursorInfo(console, &lpCursor);
}