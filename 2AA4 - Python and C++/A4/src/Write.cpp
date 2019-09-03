#include "CellType.h"
#include "GameBoard.h"
#include "Write.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <string.h>

void write_state(Board board){
  std::ofstream writer;
  std::string line;

  writer.open("./data/output.txt");

  for (int i = 0; i < 30; i++){
    for (int j = 0; j < 30; j++){
      
      if (j == 29){
        if (board.get_board()[i][j].live_state){
          writer.write("1", 1);
        }
        else {
          writer.write("0", 1);
        }
      }
      else if (board.get_board()[i][j].live_state){
        writer.write("1", 1);
        writer.write(" ", 1);
      }
      else if (!board.get_board()[i][j].live_state){
        writer.write("0", 1);
        writer.write(" ", 1);
      }
    }
    if (!(i == 29)){
      writer.write("\n", 1);
    }
  }

  writer.close();

}