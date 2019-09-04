/**
 * \file GameBoard.h
 * \author Raymond Tu <tur1@mcmaster.ca>
 * \brief Provides an ADT representing a model for the game of Conway's Game of Life.
 * Saves the state of the game and allows the user to iterate to the next state of the game, where the cells in the board are updated accordingly.
 */
#ifndef A4_LIFE_BOARD_H_
#define A4_LIFE_BOARD_H_

#include "CellType.h"
#include <vector>
#include <string>
#include <string.h>

/**
 * \brief Represents the state of Conway's Game of Life.
 * \details The state variable board is a 2-D Vector of CellT elements, that represent the gameboard for the game.
 * set_neighbour and clear_neighbour are helper functions to next_gen in order to maintain modularity.
 */
class Board {
  private:
    std::vector<std::vector<CellT> > board;
    void set_neighbour();
    void clear_neighbour();
  public:
    /**
     * \brief Constructs the board.
     * \param filename is a string representing the filename of the passed in input for the Read module
     * to then return a 2-D vector that will be assigned to the board state variable.
     */
    Board(std::string filename);

    /**
     * \brief Accessor for the private board state variable.
     * \return A 2-D vector of CellT representing the gameboard from the board state variable.
     */
    std::vector<std::vector<CellT> > get_board();

    /**
     * \brief Updates the state of the game to the next generation of cells.
     */
    void next_gen();
};

#endif