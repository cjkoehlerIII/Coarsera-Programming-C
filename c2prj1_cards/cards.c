#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

void assert_card_valid(card_t c){
assert(c.value>=2);
assert(c.value<=VALUE_ACE);
assert(c.suit>=SPADES);
assert(c.suit<=CLUBS);
return;
  }

const char * ranking_to_string(hand_ranking_t r) {

  if (r==STRAIGHT_FLUSH){
    return "STRAIGHT_FLUSH";
  };

  if (r==FOUR_OF_A_KIND){
    return "FOUR_OF_A_KIND";
  };

  if (r==FULL_HOUSE){
    return "FULL_HOUSE";
  };

  if (r==FLUSH){
    return "FLUSH";
  };

  if (r==STRAIGHT){
    return "STRAIGHT";
  };

  if (r==THREE_OF_A_KIND){
    return "THREE_OF_A_KIND";
  };

  if (r==TWO_PAIR){
    return "TWO_PAIR";
  };

  if (r==PAIR){
    return "PAIR";
  };

  if (r==NOTHING){
    return "NOTHING";
  }else{
    return "?";};
}

char value_letter(card_t c) {
  if(c.value==2){
    return '2';};

  if(c.value==3){
    return '3';};

  if(c.value==4){
    return '4';};

  if(c.value==5){
    return '5';};

  if(c.value==6){
    return '6';};

  if(c.value==7){
    return '7';};

  if(c.value==8){
    return '8';};

  if(c.value==9){
    return '9';};

  if(c.value==10){
    return '0';};

  if(c.value==VALUE_JACK){
    return 'J';};

  if(c.value==VALUE_QUEEN){
    return 'Q';};

  if(c.value==VALUE_KING){
    return 'K';}

  if(c.value==VALUE_ACE){
    return 'A';}
  else{
    return '?';};

}

char suit_letter(card_t c) {
  switch(c.suit) {
  case SPADES : return 's'; break;
  case HEARTS : return 'h'; break;
  case DIAMONDS : return 'd'; break;
  case CLUBS : return 'c'; break;
  default : return '?'; break;
  }
}

void print_card(card_t c) {
  char val = value_letter(c);
  char suit = suit_letter(c);
  printf("%c%c", val, suit);
  return;
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
    switch(value_let) {
  case '2' : temp.value = 2; break;
  case '3' : temp.value = 3; break;
  case '4' : temp.value = 4; break;
  case '5' : temp.value = 5; break;
  case '6' : temp.value = 6; break;
  case '7' : temp.value = 7; break;
  case '8' : temp.value = 8; break;
  case '9' : temp.value = 9; break;
  case '0' : temp.value = 10; break;
  case 'J' : temp.value = VALUE_JACK; break;
  case 'Q' : temp.value = VALUE_QUEEN; break;
  case 'K' : temp.value = VALUE_KING; break;
  case 'A' : temp.value = VALUE_ACE; break;
  }
  switch(suit_let) {
  case 's' : temp.suit = SPADES; break;
  case 'h' : temp.suit = HEARTS; break;
  case 'd' : temp.suit = DIAMONDS; break;
  case 'c' : temp.suit = CLUBS; break;
  }
  assert_card_valid(temp);
  return temp;
}


card_t card_from_num(unsigned c) {
  card_t temp={0,0};

  if(c<=12&&c>=0){
    temp.suit=SPADES;
    temp.value=c%13+2;
    return temp;};

  if(c<=25&&c>12){
    temp.suit=HEARTS;
    temp.value=c%13+2;
    return temp;};

  if(c<=38&&c>25){
    temp.suit=DIAMONDS;
    temp.value=c%13+2;
    return temp;};

  if(c<=51&&c>38){
    temp.suit=CLUBS;
    temp.value=c%13+2;
    return temp;};
 
  return temp;
}
