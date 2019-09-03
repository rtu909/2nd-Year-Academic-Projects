/**
 * \file Read.h
 * \author Raymond Tu <tur1@mcmaster.ca>
 * \brief Module that reads in a given input file of specified format in specification, 
 * returns a 2-D vector that will be used to initialize the gameboard.
 */
#ifndef A4_READ_H_
#define A4_READ_H_

#include "GameBoard.h"
#include "CellType.h"

/**
 * \brief Reads in a given filename of specified format and returns a 2-D vector of CellT.
 * \param filename is a string representing the name of the passed in input file.
 * \return A 2-D vector of CellT that will be used to initialize the gameboard.
 */
std::vector<std::vector<CellT> > read_state(std::string filename);

#endif