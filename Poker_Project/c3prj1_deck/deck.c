#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for (size_t count = 0; count < (hand->n_cards);count++)
  {
    print_card(*(hand->cards[count]));
    if (count < hand->n_cards)
      putchar(' ');
  }

}

int deck_contains(deck_t * d, card_t c) {
  for (size_t i = 0; i < (d->n_cards); i++)
  {
    if (c.value == (d->cards[i])->value && c.suit == (d->cards[i])->suit)
      return (1);
  }
  return 0;
}

void shuffle(deck_t * d){
  size_t max_rand=d->n_cards;
  card_t swap_card;
  size_t num;
  size_t num2;
  for (size_t i=0; i<max_rand; i++){
    num=rand()%max_rand;
    num2=rand()%max_rand;
    //   while (num>max_rand){
    //num/=2;
    //}
    // printf("num =%zu ", num);
    swap_card.value=d->cards[num]->value;
    swap_card.suit=d->cards[num]->suit;
    d->cards[num]->value=d->cards[num2]->value;
    d->cards[num]->suit=d->cards[num2]->suit;
    d->cards[num2]->value=swap_card.value;
    d->cards[num2]->suit=swap_card.suit;
  }

  
}
void assert_full_deck(deck_t * d) {
  assert(d->n_cards == 52);
  for (size_t i = 0; i < (d->n_cards); i++)
  {
    assert_card_valid(*(d->cards[i]));

    // we want to  check that there are no dublicate card
    assert(deck_contains(d, card_from_num(i)) == 1);
  }
}
