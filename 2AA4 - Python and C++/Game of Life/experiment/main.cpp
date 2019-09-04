#include <iostream>
#include "GameBoard.h"
#include "View.h"
#include "Read.h"
#include "Write.h"
#include <vector>


int main() {
  Board board("./data/input.txt");
  display_state(board);
  board.next_gen();
  write_state(board);
  display_state(board);
}