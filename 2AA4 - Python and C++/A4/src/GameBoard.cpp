#include "CellType.h"
#include "GameBoard.h"
#include "Read.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <string.h>


Board::Board(std::string filename): board(read_state(filename)){
}

std::vector<std::vector<CellT> > Board::get_board(){
  return this->board;
};

void Board::set_neighbour(){
  clear_neighbour();

  for (int i = 1; i < 29; i++){
    for (int j = 1; j < 29; j++){

      int l_i = i-1;
      int h_i = i + 1;
      int l_j = j-1;
      int h_j = j + 1;

      bool i_top = i == 0;
      bool i_bot = i == 29;
      bool j_left = j == 0;
      bool j_right = j == 29;

      if (i_top && j_left){
        if (this->board[0][1].live_state){
          this->board[i][j].live_neighbours++;
        }
        if (this->board[1][0].live_state){
          this->board[i][j].live_neighbours++;
        }
        if (this->board[1][1].live_state){
          this->board[i][j].live_neighbours++;
        }
      }
      else if (i_top && j_right){
        if (this->board[0][28].live_state){
          this->board[i][j].live_neighbours++;
        }
        if (this->board[1][29].live_state){
          this->board[i][j].live_neighbours++;
        }
        if (this->board[1][28].live_state){
          this->board[i][j].live_neighbours++;
        }
        
      }
      else if (i_bot && j_left){
        if (this->board[28][0].live_state){
          this->board[i][j].live_neighbours++;
        }
        if (this->board[29][1].live_state){
          this->board[i][j].live_neighbours++;
        }
        if (this->board[28][1].live_state){
          this->board[i][j].live_neighbours++;
        }
        
      }
      else if (i_bot && j_right){
        if (this->board[29][28].live_state){
          this->board[i][j].live_neighbours++;
        }
        if (this->board[28][29].live_state){
          this->board[i][j].live_neighbours++;
        }
        if (this->board[28][28].live_state){
          this->board[i][j].live_neighbours++;
        }
        
      }
      else if (i_top && (0 < j && j < 29)){
        for (int new_i = 0; new_i <= 1; new_i++){
          for (int new_j = l_j; new_j <= h_i; new_j++){
            if (this->board[new_i][new_j].live_state){
              this->board[i][j].live_neighbours++;
            }
            
          }
        }
        
        
      }
      else if (j_left){
        for (int new_i = l_i; new_i <= h_i; new_i++){
          for (int new_j = j; new_j <= h_j; new_j++){
            if (this->board[new_i][new_j].live_state){
              this->board[i][j].live_neighbours++;
            }
          }
        }
        
      }
      else if (j_right){
        for (int new_i = l_i; new_i <= h_i; new_i++){
          for (int new_j = j; new_j >= l_j; new_j--){
            if (this->board[new_i][new_j].live_state){
              this->board[i][j].live_neighbours++;
            }
          }
        }
        
      }
      else if (i_bot){
        for (int new_i = i; new_i >= l_i; new_i--){
          for (int new_j = l_j; new_j <= h_j; new_j++){
            if (this->board[new_i][new_j].live_state){
              this->board[i][j].live_neighbours++;
            }
          }
        }
        
      }
      else{
        for (int new_i = l_i; new_i <= h_i; new_i++){
          for (int new_j = l_j; new_j <= h_j; new_j++){
            if (this->board[new_i][new_j].live_state){
              this->board[i][j].live_neighbours++;
            }
          }
        }
      }
      if (this->board[i][j].live_state){
        this->board[i][j].live_neighbours--;
      }

    }
  }
}

void Board::next_gen(){
  set_neighbour();

  for (int i = 1; i < 29; i++){
    for (int j = 1; j < 29; j++){

      if (this->board[i][j].live_state){
        if (this->board[i][j].live_neighbours < 2){
          this->board[i][j].live_state = false;
        }
        else if ((this->board[i][j].live_neighbours == 2) || (this->board[i][j].live_neighbours == 3)){
          this->board[i][j].live_state = true;
        }
        else if (this->board[i][j].live_neighbours > 3){
          this->board[i][j].live_state = false;
        }
      }
      else if (!this->board[i][j].live_state){
        if (this->board[i][j].live_neighbours == 3){
          this->board[i][j].live_state = true;
        }
      }
    }
  }
}

void Board::clear_neighbour(){
  for (int i = 0; i < 30; i++){
    for (int j = 0; j < 30; j++){
      this->board[i][j].live_neighbours = 0;
    }
  }
}