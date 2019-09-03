#include "CardTypes.h"
#include "CardStack.h"
#include "GameBoard.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

SeqCrdStckT BoardT::init_seq(unsigned int n){
  SeqCrdStckT s;
  std::vector<CardT> empty_vec;
  
  for (unsigned int i = 0; i <= n-1; i++){
    s.push_back(CardStackT(empty_vec));
  };
  return s;
};

bool BoardT::two_decks(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W){

  for (unsigned int st = 0; st < 4; st++){
    for (unsigned int rk = 1; rk <= 13; rk++){
      CardT c2;
      SuitT suit = (SuitT)st;
      RankT rank = (RankT)rk;
      c2.s = suit;
      c2.r = rank;
      if (cnt_cards(T, F, D, W, c2) != 2){
        return false;
      }
    }
  }
  return true;
};
unsigned int BoardT::cnt_cards_seq(SeqCrdStckT S, CardT c2){
  unsigned int count;

  for (unsigned int s = 0; s < S.size(); s++){
    count = count + cnt_cards_stack(S[s], c2);
  }
  return count;
}

unsigned int BoardT::cnt_cards_stack(CardStackT s, CardT c2){
   int count = 0;
   for(unsigned int c=0; c<s.size(); c++){
       CardT c1 = s.toSeq()[c];
       if ((c1.s == c2.s) && (c1.r == c2.r)){
          count++;
    }
   }
    return count; 
}

unsigned int BoardT::cnt_cards(SeqCrdStckT T, SeqCrdStckT F, CardStackT D, CardStackT W, CardT c2){
  return cnt_cards_seq(T, c2) + cnt_cards_seq(F, c2) + cnt_cards_stack(D, c2) + cnt_cards_stack(W, c2);
}

SeqCrdStckT BoardT::tab_deck(std::vector<CardT> deck){
  SeqCrdStckT tab_stack;
  for (int i = 0; i < 10; i++){
    tab_stack.push_back(CardStackT());
    for (int j = 4*i; j <= 4*(i+1)-1; j++){
      tab_stack[i] = tab_stack[i].push(deck[j]);
    }
  }
  return tab_stack;
};

//https://www.geeksforgeeks.org/how-to-check-whether-a-number-is-in-the-rangea-b-using-one-comparison/
bool BoardT::is_valid_pos(CategoryT c, unsigned int n){
  if (c == Tableau){
    return (0 <= n && n <= 9);
  }
  else if (c == Foundation){
    return (0 <= n && n <= 7);
  }
  return false;
};

bool BoardT::tab_placeable(CardT c, CardT d){
  return (c.s == d.s) && (c.r == d.r - 1); 
};

bool BoardT::foundation_placeable(CardT c, CardT d){
  return (c.s == d.s) && (c.r == d.r + 1);
};

bool BoardT::valid_tab_tab(unsigned int n_0, unsigned int n_1){
  if (this->T[n_0].size() > 0){
    if (this->T[n_1].size() > 0){
      return tab_placeable(T[n_0].top(), T[n_1].top());
    }
    else if (this-> T[n_1].size() == 0){
      return true;
    }
  }
  else if (this->T[n_0].size() == 0){
    if (this->T[n_1].size() > 0){
      return false;
    }
    else if (this->T[n_1].size() == 0){
      return false;
    }
  }
  return false;
};

bool BoardT::valid_tab_foundation(unsigned int n_0, unsigned int n_1){
  if (this->T[n_0].size() > 0){
    if (this->F[n_1].size() > 0){
      return foundation_placeable(T[n_0].top(), F[n_1].top());
    }
    else if (this-> F[n_1].size() == 0){
      return this->T[n_0].top().r == ACE;
    }
  }
  else if (this->T[n_0].size() == 0){
    if (this->F[n_1].size() > 0){
      return false;
    }
    else if (this->F[n_1].size() == 0){
      return false;
    }
  }

  return false;

};

bool BoardT::valid_waste_tab(unsigned int n){
  if (this->T[n].size() > 0){
    return tab_placeable(this->W.top(), this->T[n].top());
  }
  else if (this->T[n].size() == 0){
    return true;
  }
  return false;
};

bool BoardT::valid_waste_foundation(unsigned int n){
  if (this->F[n].size() > 0){
    return foundation_placeable(this->W.top(), this->F[n].top());
  }
  else if (this->F[n].size() == 0){
    return this->W.top().r == ACE;
  }
  return false;
};

//https://stackoverflow.com/questions/421573/best-way-to-extract-a-subvector-from-a-vector?fbclid=IwAR3EcAqyrvR5HnGPAmF46aKTWr3VK7HLFdFhq5pZTSc9juDaBC7YFSZ2Y-w
BoardT::BoardT(std::vector<CardT> deck){

  this->F = init_seq(8);
  this->D = CardStackT(std::vector<CardT>(deck.begin() + 40, deck.end()));
  this->W = CardStackT();
  this->T = tab_deck(std::vector<CardT>(deck.begin(), deck.begin() + 40));

  if (!BoardT::two_decks(init_seq(10), init_seq(8), CardStackT(deck), CardStackT())){
    throw std::invalid_argument("invalid input for constructor");
  }
};

bool BoardT::is_valid_tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1){

  if (c == Tableau && !(is_valid_pos(Tableau, n_0) && (is_valid_pos(Tableau, n_1)))){
    throw std::out_of_range("move is out of range");
  }
  else if (c == Foundation && !(is_valid_pos(Tableau, n_0) && (is_valid_pos(Foundation, n_1)))){
    throw std::out_of_range("move is out of range");
  }

  if (c == Tableau){
    return valid_tab_tab(n_0, n_1);
  }
  else if (c == Foundation){
    return valid_tab_foundation(n_0, n_1);
  }
  else if (c == Deck){
    return false;
  }
  else if (c == Waste){
    return false;
  }
  return false;
};

bool BoardT::is_valid_waste_mv(CategoryT c, unsigned int n){

  try {
    if (this->W.size() == 0){
      throw std::invalid_argument("waste is empty");
    }
  } catch (std::invalid_argument &e) { return false;}

  if (c == Tableau && !(is_valid_pos(Tableau, n))){
    throw std::out_of_range("move is not in a valid position");
  }
  if (c == Foundation && !(is_valid_pos(Foundation, n))){
    throw std::out_of_range("move is not in a valid position");
  }

  if (c == Tableau){
    return valid_waste_tab(n);
  }
  else if (c == Foundation){
    return valid_waste_foundation(n);
  }
  else if (c == Deck){
    return false;
  }
  else if (c == Waste){
    return false;
  }
  return false;

};

bool BoardT::is_valid_deck_mv(){
  return this->D.size() > 0;
};

void BoardT::tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1){
  if (!is_valid_tab_mv(c, n_0, n_1)){
    throw std::invalid_argument("not a valid tab move");
  }

  if (c ==  Tableau){
    this->T[n_0] = T[n_0].pop();
    this->T[n_1] = T[n_1].push(T[n_0].top());
  }
  else if (c == Foundation){
    this->T[n_0] = T[n_0].pop();
    this->F[n_1] = F[n_1].push(T[n_0].top());
  }
};

void BoardT::waste_mv(CategoryT c, unsigned int n){
  if (!is_valid_waste_mv(c,n)){
    throw std::invalid_argument("not a valid waste move");
  }

  if (c ==  Tableau){
    this->T[n] = T[n].push(W.top());
    this->W = W.pop();
  }
  else if (c == Foundation){
    this->F[n] = F[n].push(W.top());
    this->W = W.pop();
  }
};

void BoardT::deck_mv(){
  if (!is_valid_deck_mv()){
    throw std::invalid_argument("not a valid deck move");
  }

  CardStackT pushed_waste = this->W.push(this->D.top());

  this->W = pushed_waste;

  Stack<CardT> popped_deck = this->D.pop();
  this->D = popped_deck;
};

CardStackT BoardT::get_tab(unsigned int i){
  if (!is_valid_pos(Tableau, i)){
    throw std::out_of_range("i is out of range of Tableau");
  }
  return this->T[i];
};

CardStackT BoardT::get_foundation(unsigned int i){
  if (!is_valid_pos(Foundation, i)){
    throw std::out_of_range("i is out of range of Foundation");
  }
  return this->F[i];
};

CardStackT BoardT::get_deck(){
  return this->D;
};

CardStackT BoardT::get_waste(){
  return this->W;
};

bool BoardT::valid_mv_exists(){
  bool valid_tab_mv = false;
  bool valid_waste_mv = false;

  for (int n_0 = 0; n_0 < 10; n_0++){
    for (int n_1 = 0; n_1 < 10; n_1++){
      for (int i = 0; i < 2; i++){
        CategoryT c = (CategoryT) i;
        if (is_valid_pos(Tableau, n_0) && is_valid_pos(c, n_1)){
          valid_tab_mv = valid_tab_mv || is_valid_tab_mv(c, n_0, n_1);
        }
      }
    }
  }

  for (int n = 0; n < 10; n++){
      for (int i = 0; i < 2; i++){
        CategoryT c = (CategoryT) i;
        if (is_valid_pos(c, n)){
          valid_waste_mv = valid_waste_mv || is_valid_waste_mv(c, n);
        }
      }
  }

  
  return valid_tab_mv || valid_waste_mv || is_valid_deck_mv();
};

bool BoardT::is_win_state(){
  for (int i = 0; i < 7; i++){
    if (!((this->F[i].size() > 0) && (this->F[i].top().r == KING))){
      return false;
    }
  }
  return true;
};

