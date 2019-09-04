/**
 * \file CellType.h
 * \author Raymond Tu <tur1@mcmaster.ca>
 * \brief File that contains the exported type for the GameBoard, which is CellT, representing the cells in the board. 
 * live_state represents a boolean value for if the cell is alive or dead, 
 * while the integer live_neighbours represents the number of live neighbours a cell has.
 */
#ifndef A4_CELL_TYPE_H_
#define A4_CELL_TYPE_H_

struct CellT{
  bool live_state;
  int live_neighbours;
};

#endif