/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golGame.h"
#include <iostream>


namespace gol {

  GameOfLife::GameOfLife(GridCellStatus grid)
  { 
    // store an instance from part A
    this->currentStatus = grid;
  }
    
  
  void GameOfLife::TakeStep()
  {
    vector<vector<string>> temp;
    temp.assign(this->currentStatus.gridCellStatus.begin(),this->currentStatus.gridCellStatus.end());

    for (int i=0; i<this->currentStatus.row; i++)
    {
      for (int j=0; j<this->currentStatus.column;j++)
      {
        int user_i = i + 1;
        int user_j = j + 1;
        if (this->currentStatus.getOneCellStatus(user_i,user_j) == "-")
        {
          if (this->currentStatus.aliveNeighbor(user_i,user_j) == 3)
          {
            // A dead cell with three alive cells around
            temp[i][j] = "o";
          }
        }else{
          if ((this->currentStatus.aliveNeighbor(user_i,user_j)<2) || (this->currentStatus.aliveNeighbor(user_i,user_j)>3))
          {
            temp[i][j] = "-";
          }
        }
      }
    }
    this->currentStatus.gridCellStatus.assign(temp.begin(), temp.end());
    temp.clear();
  }

  // Print current cell status in grid
  void GameOfLife::printCurrentStatus()
  {
    int row = this->currentStatus.gridCellStatus.size();
    int column = this->currentStatus.gridCellStatus[0].size();
    for (int i=0; i<row; i++)
    {
      for (int j=0; j<column; j++)
      {
        if (j == column-1)
        {
          // The last element of the vector gridCellStatus using std::endl to flush the buffer
          if (i == row-1) {cout << this->currentStatus.gridCellStatus[i][j] << endl;} 
          else {cout << this->currentStatus.gridCellStatus[i][j] << "\n";}
          continue;
        }
        cout << this->currentStatus.gridCellStatus[i][j] << " ";
      }
    }
    cout << endl;
  }

  string GameOfLife::getOneCellCurrent(int row, int column)
  {
    return this->currentStatus.gridCellStatus[row-1][column-1];
  }

} // end namespace
