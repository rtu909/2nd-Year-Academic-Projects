#include "CellType.h"
#include "GameBoard.h"
#include "View.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <string.h>

void display_state(Board board){
  for (int i = 0; i < 30; i++){
    for (int j = 0; j < 30; j++){
      if (board.get_board()[i][j].live_state){
        std::cout << "@" << " ";
      }
      else{
        std::cout << "." << " ";
      }
    }
    std::cout << "|" << i << "\n";
  }
}