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
              << "Option 1:\n"
              << "\tStarting by entering (1) '.txt' file path (2)  Number of Generations. \n" 
              << "\tSample input:\t ./gofSimulator \"../Testing/Data/glider.txt\" 5\n"
              << "Option 2:\n"
              << "\tStarting with random cell contents by entering (1) Row (2) Column (3) Number of alive cells .4) Number of Generations. \n"
              << "\tSample input:\t ./gofSimulator 10 10 40 5 \n"
              << "Option 3:\n"
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

  // Option 1: Input with file path and the number of generation
  if (argc == 3)
  {
    string file_path = argv[1];
    gol::GridCellStatus initial_grid(file_path);
    int n_generation = stoi(argv[2]);

    gol::GameOfLife game(initial_grid);

    
    cout << "Initial Grid: \n";
    game.printCurrentStatus();

    for (int i=0; i<n_generation; i++)
    {
      cout << i+1 << " generation's grid: \n";
      game.TakeStep();
      game.printCurrentStatus();
    }
    
  }

  // Option 2: Input with the number of row, column, alive cell and generation.
  if (argc == 5)
  {
    int n_row = stoi(argv[1]);
    int n_column = stoi(argv[2]);
    int n_alive_cell = stoi(argv[3]);
    int n_generation = stoi(argv[4]);

    gol::GridCellStatus initial_grid(n_row, n_column, n_alive_cell);
    gol::GameOfLife game(initial_grid);

    cout << "Initial Grid: \n";
    game.printCurrentStatus();

    for (int i=0; i<n_generation; i++)
    {
      cout << i+1 << " generation's grid: \n";
      game.TakeStep();
      game.printCurrentStatus();
    }
    
  }

  return 0;
}
