/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "golCatchMain.h"
#include "golMyFunctions.h"
#include "golGame.h"
#include <iostream>
#include <vector>


TEST_CASE( "Test case 1", "[PartA CheckInstantiation]" ) {
  gol::GridCellStatus grid(5,5);

  // Check the get and set function is correct
  string status_default = grid.getOneCellStatus(2,3);
  grid.setOneCellStatus(2,3,"alive");
  string status_set_23_alive = grid.getOneCellStatus(2,3);

  REQUIRE(status_default == "-");
  REQUIRE(status_set_23_alive == "o");

}

TEST_CASE( "Test case 2", "[PartA CheckInstantiation]" ) {
  gol::GridCellStatus grid1(5,6,8);

  // check whether the total number of placed cells is correct
  REQUIRE( grid1.totalNumOfCells() == 30 );
}

TEST_CASE( "Test case 3", "[PartA CheckInstantiation]" ) {
  gol::GridCellStatus grid("../Testing/Data/still_lifes.txt");

  // check whether the total number of placed cells is correct
  REQUIRE(grid.totalNumOfCells() == 100 );
  REQUIRE(grid.getOneCellStatus(4, 7) == "o");
}

TEST_CASE( "Test case 4", "[PartA CheckAliveNeighbor]" ) {
  gol::GridCellStatus grid("../Testing/Data/still_lifes.txt");

  // check whether the total number of placed cells is correct
  REQUIRE(grid.aliveNeighbor(1,1) == 1);
  REQUIRE(grid.aliveNeighbor(2,2) == 2);
  REQUIRE(grid.aliveNeighbor(4,8) == 5);
}

TEST_CASE( "Test Case 5", "[PartB TakeStep]") {
  gol::GridCellStatus grid("../Testing/Data/glider.txt");
  gol::GameOfLife status(grid);
  
  string current = status.getOneCellCurrent(2,2);
  REQUIRE(current == "-");
  
  status.TakeStep();
  
  string next = status.getOneCellCurrent(2,2);
  REQUIRE(next == "o");
}
