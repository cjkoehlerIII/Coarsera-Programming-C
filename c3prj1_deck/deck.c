#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

int com(card_t c1,card_t c2);

int com(card_t c1,card_t c2){
  if((c1.value==c2.value)&&(c1.suit==c2.suit)) return 1;
  return 0;
}

void print_hand(deck_t * hand){

  for(size_t i=0; i<(hand->n_cards); i++)
    {
      // print_card(*(hand->cards)[i]);
      print_card((*hand).cards[i]);
      printf("%s", " ");

    }
}

int deck_contains(deck_t * d, card_t c) {
 
  card_t **ptr = d->cards; 

  for(int i=0; i<((int)d->n_cards); i++){
    if(value_letter(**ptr)== value_letter(c) && suit_letter(**ptr)==suit_letter(c)){
      return 1;
    }
    ptr++;
  }
  return 0;
}

void shuffle(deck_t * d){

  card_t *ptr = NULL;
  int cards = d->n_cards;
  int j=0;

  for(int i = cards-1; i>0 ; i--)
    {
      j = rand()%(i+1);

      ptr =d->cards[i];
      d->cards[i]=d->cards[j];
      d->cards[j]=ptr;
    }
}

void assert_full_deck(deck_t * d) {

  card_t ** ptr = d->cards;
  card_t c;
  int count;

  for(size_t i=0;i<d->n_cards;i++){
    c=**(ptr+i);
    count=0;
    for(size_t j=0; j<d->n_cards;j++){
      if(com(**(ptr+j),c)) count ++;
    }
    assert(count==1);
  }
}


 
