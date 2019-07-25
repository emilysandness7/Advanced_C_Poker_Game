/*
titleScreenTJR.c
Displays the title screen.

Author: Timothy Roller
Version .01
*/

#include "pokerHeader.h"

#define NUMBER_OF_ICONS 1000 //maximum number of icons to display
#define X_LOCATION 46 //used to keep icons in window
#define Y_LOCATION 140 //used to keep icons in window

#define LOCATION_CENTER 45 //used to position text

/*
* Function display title screen.
* Uses rand() to define locations of
* clubs, spades, hearts, and diamonds.
*/
void titleScreenTJR()
{
  int i = 0; //iterator  to work through loops
  int locationRows = 18; //used to work through rows
  int r2; //used to set location of icon
  int r; //used to set location of icon

  bon();

  //loop to create hearts
  while (i < NUMBER_OF_ICONS)
  {
    r2 = rand() % Y_LOCATION;
    r = rand() % X_LOCATION;

    xya(r, r2);
    printf("\3");
    i++;
  }

  i = 0;

  //loop to create diamonds
  while (i < NUMBER_OF_ICONS)
  {
    r2 = rand() % Y_LOCATION;
    r = rand() % X_LOCATION;

    xya(r, r2);
    printf("\4");
    i++;
  }

  i = 0;
  //loop to create clubs
  while (i < NUMBER_OF_ICONS)
  {
    r2 = rand() % Y_LOCATION;
    r = rand() % X_LOCATION;

    xya(r, r2);
    printf("\5");
    i++;
  }

  i = 0;
  //loop to create spades
  while (i < NUMBER_OF_ICONS)
  {
    r2 = rand() % Y_LOCATION;
    r = rand() % X_LOCATION;

    xya(r, r2);
    printf("\6");
    i++;
  }

  //displays the text
  xya(locationRows++, LOCATION_CENTER); // uses plus plus as it would not trigger otherwise
  printf("                                                             ");
  xya(locationRows++, LOCATION_CENTER);
  printf("                 Welcome to Hedgehog Poker                   ");
  xya(locationRows++, LOCATION_CENTER);
  printf("                                                             ");
  xya(locationRows++, LOCATION_CENTER);
  printf(" Joseph Helland, Mallory Russell, Emily Sandness, Tim Roller ");
  xya(locationRows++, LOCATION_CENTER);
  printf("                                                             ");
  xya(locationRows++, LOCATION_CENTER);
  printf("                  CIS 225 Spring 2016                        ");
  xya(locationRows++, LOCATION_CENTER);
  printf("                                                             ");
  xya(locationRows++, LOCATION_CENTER);
  printf("                  Press Enter to Start                       ");
  xya(locationRows++, LOCATION_CENTER);
  printf("                                                             ");
  xya(SCREEN_ROW_COUNT, SCREEN_ROW_COUNT);
  getchar();
}
