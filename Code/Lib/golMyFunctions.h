/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golMyFunctions_h
#define golMyFunctions_h
#include <vector>
#include <string>
#include<algorithm>
#include<time.h>
#include <math.h>
#include <cstdio>
#include <sstream>
#include <fstream>
using namespace std;

/**
* \file golMyFunctions.h
* \brief Various Utilities.
* \ingroup utilities
*/
namespace gol
{
class GridCellStatus
{

void randnum(int Num, vector<int>& random_vec);
public:
int row;
int column;
vector<vector<string>> gridCellStatus;
GridCellStatus();
GridCellStatus(int row, int column);
GridCellStatus(int row, int column, int n_alive_cells);
GridCellStatus(string file_path);
string getOneCellStatus(int row, int column);
int totalNumOfCells();
void setOneCellStatus(int row, int column, string status);
void printGrid();
int aliveNeighbor(int row, int column);
bool cellsAllDead();

};


} // end namespace

#endif
