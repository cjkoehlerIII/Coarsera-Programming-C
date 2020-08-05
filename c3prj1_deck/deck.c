#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include <time.h>

int com(card_t c1,card_t c2){
  if((c1.value==c2.value)&&(c1.suit==c2.suit)) return 1;
  return 0;
}

void print_hand(deck_t * hand){
 /*
This should print out the contents of a hand. 
It should print each card, and a space after each card.  
Do not put a newline after the hand, as this function 
gets called to print a hand in the middle of a line of output.
 */

  card_t **ptr = hand->cards; 

  for(size_t i=0; i<(hand->n_cards); i++)
    {
      print_card(card_t hand[i]);
      printf("%s", " ");
      ptr++;
    }
}

int deck_contains(deck_t * d, card_t c) {
  /* This function should check if a deck contains a particular card or not. 
 If the deck does contain the card, this function should return 1. 
 Otherwise it should return 0.(You will use this later to build the deck of 
 remaining cards which are not in any player's hand).
  */

  card_t **ptr = d->cards; 

  for(int i=0; i<(d->n_cards); i++){
    if(value_letter(**ptr)== value_letter(c) && suit_letter(**ptr)==suit_letter(c)){
      return 1;
    }
    ptr++;
  }
  return 0;
}

void shuffle(deck_t * d){
  /*This function takes in a deck and shuffles it,
randomly permuting the order of the deck of cards--
we'll leave the specifics of the algorithm design up to you.
However, you will wont to use random() to generate pseudo-random numbers.
  */

  srand(time(NULL));
  
  card_t ** ptr = d->cards;
  int size = (int)(d->n_cards);
  for(size_t i = size; i>0 ; i--)
    {
      int j = rand()%(i+1);
      ptr_swap(ptr+i, ptr+j);
  
}

void assert_full_deck(deck_t * d) {
  /*This function should check that the passed in deck contains every
valid card exactly once.  If the deck has any problems, this function should fail
an assert.  This will be used to help you test your deck shuffling:
we will shuffle a full deck, then call assert_full_deck, so that you can 
identify problmes with the deck.  You can print any error massages  you want if there is a problem.
Hint: you already wrote deck_contains.
  */

  card_t ** ptr = d->cards;
  card_t c;
  int count;

  for(size_t i=0;i<d->n_cards;i++){
    c=**(cards+i);
    count=0;
    for(size_t j=0; j<d->n_cards;j++){
      if(com(**(cards+j),c)) count ++;
    }
    assert(count==1);
  }
}

 void ptr_swap(card_t **a, card_t **b)
 {
   card_t *temp=*a;
   *a=*b;
   *b=temp;
 }

 
