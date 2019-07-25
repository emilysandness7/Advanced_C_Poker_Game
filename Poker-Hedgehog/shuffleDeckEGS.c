/*
shuffleDeckEGS.c
Shuffles a deck of 52 cards. Uses the Tiny Mersenne Twister.
This function relies on the tinymt32.h and tinymt32.c files.
Uses the 32 bit versions of tinymt32.h and tinymt32.c to be compatable
with both x86 and x64 compilers.

Tiny Mersenne Twister:
    http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/TINYMT/
How to time a function:
    http://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
Using srand((unsigned int)time(NULL)); for a seed:
    https://msdn.microsoft.com/en-us/library/398ax69y.aspx

What has improved in this function:
  - the bottom cards are shuffled more thoroughly
  - high and low cards are more evenly distributed throughout the deck.
    High value cards are no longer clustered at the top of the deck.
    Low value cards are no longer clustered at the bottom of the deck.
  - The suits are no longer clustered together.

Based on 110 tests:
  On average it's about 0.083 seconds slower than the original
  shuffle and it most likely uses more memory (not tested yet).
  But this function yields more random shuffles.

Author: Emily Sandness
History:
02 Mar 2016 - Initial Version.
03 Mar 2016 - Added debug output. Fixed shuffle bug.
04 Mar 2016 - Moved srand seed to before for-loop.
05 Mar 2016 - Implemented Tiny Mersenne Twister.
*/

#include "pokerHeader.h"
#include "tinymt32.h"

/*
Starts at the highest cards then swaps with a card that is lower
than the current card then moves down by one card.

Uses the Tiny Mersenne Twister to shuffle cards.
*/
void shuffleDeckEGS(CARD *deck) {

  short i, r;
  CARD swap; //card to swap
  tinymt32_t tinymt; //a TINYMT32_T struct that contains 3 iunsigned ints 
                     //and 1 array of 4 unsigned ints, used to hold a random value
  uint32_t seed; //seed value, unsigned int

  //give the seed a random unsigned int
  srand((unsigned int)time(NULL));
  seed = rand();

  //initializes the internal state array (tinymt) with a seed.
  tinymt32_init(&tinymt, seed);

  //go through the cards and shuffle them
  for (i = CARDS_IN_DECK - 1; i > 0; i--) {
    r = tinymt32_generate_uint32(&tinymt) % (i + 1); //tinymt32_generate_uint32() generates and returns a random unsigned int 
                                                     //based off the values seeded within tinymt struct
    swap = deck[i];
    deck[i] = deck[r];
    deck[r] = swap;
  }
}



