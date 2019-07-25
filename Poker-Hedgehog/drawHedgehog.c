/*
drawHedgehog.c
Author: Mallory Russell
draws hedgehog graphic
*/

#include "pokerHeader.h"

#define DRAW_ME_HERE 4

void drawHedgehog()
{
  bon;
  TextColor(COLOR_HEDGIE);
  xya(DRAW_ME_HERE, DRAW_ME_HERE + 1);
  for (int i = 0; i < 9; i++)
  {
    putc(92, stdout);
  }
  printf(".");
  xya(DRAW_ME_HERE + 1, DRAW_ME_HERE);
  for (int i = 0; i < 10; i++)
  {
    putc(92, stdout);
  }
  printf("::.");
  xya(DRAW_ME_HERE + 2, DRAW_ME_HERE);
  for (int i = 0; i < 10; i++)
  {
    putc(92, stdout);
  }
  putc(39, stdout);
  printf(" .\ ");
  xya(DRAW_ME_HERE + 3, DRAW_ME_HERE);
  for (int i = 0; i < 1; i++)
  {
    putc(92, stdout);
  }
  printf(":::::::::_,__0");

  xya(DRAW_ME_HERE + 5, DRAW_ME_HERE + 1);
  TextColor(FORE_BLACK|BACK_GREEN);
  printf("Hedgehog Poker");
}