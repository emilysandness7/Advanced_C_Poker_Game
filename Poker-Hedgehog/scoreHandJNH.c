/*
scoreHandJNH.c
Scores an incoming hand.

Authors: Joseph helland
Version .01
*/

#include "pokerHeader.h"

/*
First checks for if all the cards are in the same suit.
This rules out 3 of the top 5 most intensive checks most of the time. These are
also 3 of the top 5 rarest combinations.
*/
int scoreHandJNH(CARD * myHand) {
  short i;
  short count = 0;
  int score = SCORE_LOSS;
  CARD temp[5];
  bool isScore = false;

  /*
  takes the hand and makes a local copy that is then sorted prior to
  testing the hand for points. Then the hand is scored based on suit
  and also by rarity. Because the rarest hands are the highest points
  and also contain parts of other scoring hands they need to be tested
  first. Once the hand validates as true for a scoring hand it returns
  the score.
  */
  for (i = 0; i < 5; i++) {
    temp[i] = myHand[i];
  }
  sortHandJNH(temp);
  //test for a possible flush
  for (i = 0; i < 4; i++) {
    //check each card vs next card for same suit
    if (compareCardsJNH(temp[i], temp[i + 1]) == -1) {
      count++;
    }
  }
  //if flush is possible check for royal flush and then straight flush
  if (count == 4) {
    //Royal Flush
    if (isScore = scoreRoyalFlushJNH(temp)) {
      score = SCORE_ROYAL_FLUSH;
    }
    //Straigh Flush
    else if (isScore = scoreStraighFlushJNH(temp)) {
      score = SCORE_STRAIGHT_FLUSH;
    }
    //Flush
    else {
      score = SCORE_FLUSH;
    }
  }
  //Four of a Kind
  else if (isScore = scoreFourOfAKindJNH(temp)) {
    score = SCORE_FOUR_OF_A_KIND;
  }
  //Full House
  else if (isScore = scoreFullHouseJNH(temp)) {
    score = SCORE_FULL_HOUSE;
  }
  //Straight
  else if (isScore = scoreStraightJNH(temp)) {
    score = SCORE_STRAIGHT;
  }
  //Three of a Kind
  else if (isScore = scoreThreeOfAKindJNH(temp)) {
    score = SCORE_THREE_OF_A_KIND;
  }
  //Two Pair
  else if (isScore = scoreTwoPairJNH(temp)) {
    score = SCORE_TWO_PAIR;
  }
  //pair of Jacks or better
  else if (isScore = scoreJacksJNH(temp)) {
    score = SCORE_JACKS;
  }
  return score;
}

/*
sortHandJNH(*unsortedHand)
takes an unsorted hand and sorts it low to high
sorts ace low
assumes a 5 card hand
*/
void sortHandJNH(CARD* handSort) {
  short i;
  short ii;
  CARD temp;

  for (i = 0; i < 5; i++) {
    for (ii = i + 1; ii < 5; ii++) {
      if (handSort[i].cardFace > handSort[ii].cardFace) {
        temp = handSort[i];
        handSort[i] = handSort[ii];
        handSort[ii] = temp;
      }
    }
  }
  return;
}

/*
isRoyalFlush scoreRoyalFlushJNH(*sortedHand)
Scores a hand for a Royal Flush
Assumes hand is sorted ace low
checks for a royal flush (10 J Q K A)
returns isRoyalFlush true/false
*/
bool scoreRoyalFlushJNH(CARD*hand) {
  bool thisScore = false;
  short i;
  short test = 0;
  CARD ace;
  //if first card is an ace and second card is a 10 put the ace high
  if (hand[0].cardFace == 1 && hand[1].cardFace == 10) {
    ace = hand[0];
    for (i = 0; i < 4; i++) {
      hand[i] = hand[i + 1];
    }
    hand[CARDS_IN_HAND] = ace;
  }
  else {
    //if first card is not an ace and second not a 10 the hand cannot be a royal flush
    return thisScore;
  }
  for (i = 0; i < 4; i++) {
    //test if all cards are same suit
    if ((test = compareCardsJNH(hand[i], hand[i + 1])) != -1) {
      sortHandJNH(hand);
      return thisScore;
    }
    //now test if they are sequential
    else if (hand[i].cardFace != hand[i + 1].cardFace - 1) {
      //k followed by A is not mathmatically sequential as A is 1 and k is 13
      //test for i == 3 and cardface == 13
      if (i == 3 && hand[i].cardFace == 13) {
        thisScore = true;
      }
      else {
        sortHandJNH(hand);
        return thisScore;
      }
    }
  }
  sortHandJNH(hand);
  return thisScore;
}

/*
isStraightFlush scoreStraightFlushJNH(*sortedHand)
Scores a hand for a Straight Flush
Assumes hand is sorted ace low
Assumes hand has already been evaluated for a better hand
checks for a Straight flush (5 consecutive cards in same suit A low)
returns isStraightFlush true/false
*/
bool scoreStraighFlushJNH(CARD*hand) {
  bool thisScore = false;
  short i;
  short test = 0;

  for (i = 0; i < 4; i++) {
    //test if all cards are same suit
    if ((test = compareCardsJNH(hand[i], hand[i + 1])) != -1) {
      return thisScore;
    }
    //now test if they are sequential
    else if (hand[i].cardFace != hand[i + 1].cardFace - 1) {
      return thisScore;
    }
  }
  return thisScore = true;
}

/*
isFourOfAKind scoreFourOfAKindJNH(*sortedHand)
Scores a hand for four of a kind
Assumes hand is sorted ace low
Assumes hand has already been evaluated for a better hand
checks for four of a kind (4 cards with same face)
returns isFourOfAKind true/false
*/
bool scoreFourOfAKindJNH(CARD*hand) {
  bool thisScore = false;
  short i;
  short test = 0;
  short numSame = 0;
  if (test = compareCardsJNH(hand[0], hand[1]) == 1) {
    i = 0;
  }
  else {
    i = 1;
  }
  for (i; i < 4; i++) {
    //test if there are 4 of a kind.
    if (test = compareCardsJNH(hand[i], hand[i + 1]) != 1 && numSame != 3) {
      if (i > 0) {
        return thisScore;
      }
    }
    else {
      numSame++;
    }
  }
  return thisScore = true;
}

/*
isFullHouse scoreFullHouseJNH(*sortedHand)
Scores a hand for a full house
Assumes hand is sorted ace low
Assumes hand has already been evaluated for a better hand
checks for full house (3 + 2 cards with same face; set of 3 and a set of 2)
returns isFullHouse true/false
*/
bool scoreFullHouseJNH(CARD*hand) {
  bool thisScore = false;
  short test;

  if (test = compareCardsJNH(hand[0], hand[1]) != 1) return thisScore;

  if (test = compareCardsJNH(hand[1], hand[2]) == 1) {
    if (test = compareCardsJNH(hand[3], hand[4]) == 1) {
      thisScore = true;
    }
  }
  else if (test = compareCardsJNH(hand[2], hand[3]) == 1) {
    if (test = compareCardsJNH(hand[3], hand[4]) == 1) {
      thisScore = true;
    }
  }
  return thisScore;
}

/*
isStraight scoreStraightJNH(*sortedHand)
Scores a hand for a straight
Assumes hand is sorted ace low
Assumes hand has already been evaluated for a better hand
checks for a straight (run of 5 consecutive cards)
returns isStraight true/false
*/
bool scoreStraightJNH(CARD*hand) {
  bool thisScore = false;
  short i;
  CARD ace;
  if (hand[0].cardFace == 1 && hand[1].cardFace != 2) {
    ace = hand[0];
    for (i = 0; i < 4; i++) {
      hand[i] = hand[i + 1];
    }
    hand[CARDS_IN_HAND] = ace;
  }
  for (i = 0; i < 4; i++) {
    if (hand[i + 1].cardFace - 1 != hand[i].cardFace) {
      if (hand[i].cardFace - 12 != hand[i + 1].cardFace) {
        sortHandJNH(hand);
        return thisScore;
      }
    }
  }
  thisScore = true;
  return thisScore;
}

/*
isThreeOfAKind scoreThreeOfAKindJNH(*sortedHand)
Scores a hand for three of a kind
Assumes hand is sorted ace low
Assumes hand has already been evaluated for a better hand
checks for 3 of a kind (3 cards with the same face)
returns isStraight true/false
*/
bool scoreThreeOfAKindJNH(CARD*hand) {
  bool thisScore = false;
  short test;
  short counter = 0;
  short i;
  for (i = 0; i < 4; i++) {
    if (test = compareCardsJNH(hand[i], hand[i + 1]) != 1 && counter < 2) {
      counter = 0;
    }
    else {
      counter++;
    }
  }
  if (counter >= 2) {
    thisScore = true;
  }
  return thisScore;
}

/*
isTwoPair scoreTwoPairJNH(*sortedHand)
Scores a hand for two pair
Assumes hand is sorted ace low
Assumes hand has already been evaluated for a better hand
checks for 2 pairs (2 sets of 2 cards with the same face)
returns isTwoPair true/false
*/
bool scoreTwoPairJNH(CARD*hand) {
  short pairOne = 0;
  short test;
  short i;
  bool thisScore = false;
  for (i = 0; i < 4; i++) {
    if (test = compareCardsJNH(hand[i], hand[i + 1]) == 1) {
      if (pairOne == 0) {
        pairOne = 1;
      }
      else {
        thisScore = true;
        return thisScore;
      }
    }
  }
  return thisScore;
}

/*
isJacksOrBetter scoreJacksJNH(*sortedHand)
Scores a hand for a pair of jacks or better
Assumes hand is sorted ace low
Assumes hand has already been evaluated for a better hand
checks for a pair of jacks or higher (JJ, QQ, KK, AA)
returns isJacks true/false
*/
bool scoreJacksJNH(CARD*hand) {
  short test;
  short i;
  bool thisScore = false;
  for (i = 0; i < 4; i++) {
    test = compareCardsJNH(hand[i], hand[i + 1]);
    if (test == 1 && hand[i].cardFace >= 11) {
      thisScore = true;
      return thisScore;
    }
    else if (test == 1 && hand[i].cardFace == 1) {
      thisScore = true;
      return thisScore;
    }
  }
  return thisScore;
}

/*
result compareCardsJNH(cardOne, cardTwo)
Compares two cards and returns result as:
-1 cards are same suit
1 cards are same face
0 cards are not the same
*/
short compareCardsJNH(CARD cardOne, CARD cardTwo) {
  short result = 0;

  if (cardOne.cardFace == cardTwo.cardFace) {
    result = 1;
  }
  else if (cardOne.cardSuit == cardTwo.cardSuit) {
    result = -1;
  }
  return result;
}
