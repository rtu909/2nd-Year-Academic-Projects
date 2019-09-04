#include "CellType.h"
#include "Read.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <string.h>

//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::vector<CellT> > read_state(std::string filename){
  std::string line;
  std::ifstream fout;
  std::vector<std::vector<CellT> > cell_vec;

  const char * c = filename.c_str();

  fout.open(c);

  int i = 0;

  while (std::getline(fout, line)){

    std::vector<CellT> cell_row;

    for (int j = 0; j < 60; j++){
      std::string delim = " ";
      std::string token = line.substr(j, line.find(delim));
      if (token == "1"){
        CellT cell1;
        cell1.live_state = true;
        cell1.live_neighbours = 0;
        cell_row.push_back(cell1);
      }
      else if (token == "0") {
        CellT cell0;
        cell0.live_state = false;
        cell0.live_neighbours = 0;
        cell_row.push_back(cell0);
      }
    }

    cell_vec.push_back(cell_row);
  }
  fout.close();

  return cell_vec;

};