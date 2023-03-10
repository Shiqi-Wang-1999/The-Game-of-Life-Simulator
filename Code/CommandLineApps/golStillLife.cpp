/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golMyFunctions.h>
#include <golGame.h>
#include <golExceptionMacro.h>
#include <iostream>
#include <vector>
#include <string>

// Example, header-only library, included in project for simplicity's sake.
#include <Eigen/Dense>
#include <unsupported/Eigen/NonLinearOptimization>
using namespace std;
/**
 * \brief Demo file to check that includes and library linkage is correct.
 */

static void show_usage(string name)
{
    cerr << "Usage: " << name << " <option(s)> SOURCES \n"
              << "Function: Find the Still Life Pattern in Conway's Game. \n"
              << "Option 1:\n"
              << "\tStarting with random cell contents by entering (1) Number of alive cells (2) Row (3) Column (4) Number of Iterations. \n"
              << "\tSample input:\t ./golStillLife 40 10 10 8 \n"
              << "Option 2:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << endl;
}

int main(int argc, char** argv)
{
  // User do not enter anything arguments
  if (argc == 1) {
    show_usage(argv[0]);
    return 0;
  }

  // -h, --help arguments
  for (int i = 1; i < argc; i++) 
  {
    string arg = argv[i];
    if ((arg == "-h") || (arg == "--help")) 
    {
      show_usage(argv[0]);
      return 0;
    }
  }

  if (argc == 5)
  {
    int n_alive_cell = stoi(argv[1]);
    int n_row = stoi(argv[2]);
    int n_column = stoi(argv[3]);
    int n_iteration = stoi(argv[4]);

    gol::GridCellStatus initial_grid(n_row, n_column, n_alive_cell);
    gol::GameOfLife game(initial_grid);

    vector<vector<string>> last_status;

    for (int i=0; i<n_iteration;i++)
    {
      last_status.assign(game.currentStatus.gridCellStatus.begin(), game.currentStatus.gridCellStatus.end());
      game.TakeStep();
      if (game.currentStatus.cellsAllDead() == true){
        cout << "Cells all dead this round. You can run the application again with the same arguments. The initial state will be different. \n" 
             << "You can also increase the number of alive cells or iterations to find a stationary pattern." << endl;
               return 0;}

      if (game.currentStatus.gridCellStatus == last_status)
      {
        cout << "Find pattern in " << i+1 << " iteration grid. \n";
        game.printCurrentStatus();
        return 0;
      }else{
        if (i == n_iteration - 1){
          cout << "We don't find the Still Life this round. You can run the application again with same arguments \n" 
               << "You can also increase the number of alive cells or iterations to find a stationary pattern." << endl;
               return 1;}
        last_status.clear();
      }
    }


  }

  return 0;
}
