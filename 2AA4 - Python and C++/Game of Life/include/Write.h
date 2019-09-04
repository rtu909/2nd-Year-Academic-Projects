/**
 * \file Write.h
 * \author Raymond Tu <tur1@mcmaster.ca>
 * \brief Module that takes the board and writes it to an output file, in the same format as the input 
 * for the Read module.
 */
#ifndef A4_WRITE_H_
#define A4_WRITE_H_

#include "GameBoard.h"

/**
 * \brief Takes in a given gameboard and writes it to an output file.
 * \param board represents the gameboard passed in to be outputted to the terminal.
 */
void write_state(Board board);

#endif