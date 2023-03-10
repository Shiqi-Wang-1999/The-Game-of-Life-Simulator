/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef golGame_h
#define golGame_h

#include "golMyFunctions.h"
#include <vector>
#include <string>
using namespace std;

namespace gol
{
  class GameOfLife
  {
    
    public:
    GridCellStatus currentStatus;
    GameOfLife(GridCellStatus grid);
    void TakeStep();
    void printCurrentStatus();
    string getOneCellCurrent(int row, int column);
  };
} // end namespace

#endif
