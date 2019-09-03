/**
 * \file View.h
 * \author Raymond Tu <tur1@mcmaster.ca>
 * \brief Module that takes the board and outputs it to the terminal with a graphical interface of ASCII characters.
 */
#ifndef A4_VIEW_H_
#define A4_VIEW_H_

#include "GameBoard.h"

/**
 * \brief Takes in a given gameboard and outputs it to the terminal, with . representing
 * dead cells, and @ representing live cells.
 * \param board represents the gameboard passed in to be outputted to the terminal.
 */
void display_state(Board board);

#endif