/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "golMyFunctions.h"
#include <iostream>


namespace gol {
  
  GridCellStatus::GridCellStatus(){}

  // Constructor with two arguments row and column
  // The default status for cells are set to dead
  GridCellStatus::GridCellStatus(int row, int column)
  {
    this->row = row;
    this->column = column;
    typedef vector <string>  VectorT;
    VectorT vec_each_row(column, "-");

    for (int i = 0; i < row; i++)
    {
      gridCellStatus.push_back(vec_each_row);
    }
    
  }

  // Constructor with three arguments row, column and the number of alive cells
  GridCellStatus::GridCellStatus(int row, int column, int n_alive_cells)
  {
    this->row = row;
    this->column = column;
    
    typedef vector<string>  VectorT;
    VectorT vec_each_row(column, "-");
    // Default status of all cells are set to dead
    for (int i = 0; i < row; i++){ gridCellStatus.push_back(vec_each_row);}

    int n_cells = row*column;
    vector<int> random_vec;
    // Generate non-repeating random numbers from 1 to 'n_cells'
    randnum(n_cells, random_vec);

    // Iterate the first 'n_alive_cells' random number, compute the corresponding index i and j for each one
    for (int i = 0; i < n_alive_cells; i++)
    {
      int index = random_vec[i];

      if ((index%column) == 0)
      {
        int index_i = floor(index/column)-1; 
        int index_j = column-1;
        gridCellStatus[index_i][index_j] = "o";
      }
      else
      {
        int index_i = floor(index/column);
        int index_j = (index%column)-1;
        gridCellStatus[index_i][index_j] = "o";
      }
    }
    
  }

  GridCellStatus::GridCellStatus(string file_path)
  {
    vector<string>  vec_each_row;
    
    ifstream fin(file_path, ios::in);
    char  line[1024]={0};
    try{
      while(fin.getline(line, sizeof(line)))
      {
        stringstream word(line);
        string s;
        while (word >> s)
        {
          if ((s == "o") || (s == "-")){vec_each_row.push_back(s);}
          else {throw exception();}
        }
        gridCellStatus.push_back(vec_each_row);
        vec_each_row.clear();
      }
    } catch (exception x) {
      // Data validation for the input data
      printf ("There is at least one invalid character in the data file, please replace them with 'o' or '-'. \n");
    }
    fin.clear();
    fin.close();

    this->row = gridCellStatus.size();
    this->column = gridCellStatus[0].size();
  }


  // Generate non-repeating random numbers from 1 to 'Num'
  void GridCellStatus::randnum(int Num, vector<int>& random_vec)
  {
      
      for (int i = 0; i < Num; ++i)
      {
          random_vec.push_back(i + 1);
      }
      srand(time(NULL));
      random_shuffle(random_vec.begin(), random_vec.end());

  }


  int GridCellStatus::totalNumOfCells()
  {
    return gridCellStatus.size() * gridCellStatus[0].size();
  }


  // Print current cell status in grid
  void GridCellStatus::printGrid()
  {
    for (int i=0; i<row; i++)
    {
      for (int j=0; j<column; j++)
      {
        if (j == column-1)
        {
          // The last element of the vector gridCellStatus using std::endl to flush the buffer
          if (i == row-1) {cout << gridCellStatus[i][j] << endl;} 
          else {cout << gridCellStatus[i][j] << "\n";}
          continue;
        }
        cout << gridCellStatus[i][j] << " ";
      }
    }
  }


  // Get individual cell contents
  string GridCellStatus::getOneCellStatus(int row, int column)
  {
      return gridCellStatus[row-1][column-1];
  }


  // Set individual cell contents
  void GridCellStatus::setOneCellStatus(int row, int column, string status)
  {
    if (status == "alive"){gridCellStatus[row-1][column-1]="o";}
    else if (status == "dead"){gridCellStatus[row-1][column-1]="-";}
    else{cout << "Please input valid status of a cell, alive or dead."<<endl;}
  }


  int GridCellStatus::aliveNeighbor(int row, int column)
  {
    if ((row<0) || (column<0) || (this->row<row) || (this->column<column))
    {
      throw out_of_range("The input cell is outside the grid.");
    }
    int n_alive_neighbor = 0;
    vector<pair<int,int>> neighbor_coor;
    int index_row = row - 1;
    int index_col = column - 1;

    neighbor_coor.push_back(make_pair<int,int>(index_row-1,index_col-1));
    neighbor_coor.push_back(make_pair<int,int&>(index_row-1,index_col));
    neighbor_coor.push_back(make_pair<int,int>(index_row-1,index_col+1));
    neighbor_coor.push_back(make_pair<int&,int>(index_row,index_col-1));
    neighbor_coor.push_back(make_pair<int&,int>(index_row,index_col+1));
    neighbor_coor.push_back(make_pair<int,int>(index_row+1,index_col-1));
    neighbor_coor.push_back(make_pair<int,int&>(index_row+1,index_col));
    neighbor_coor.push_back(make_pair<int,int>(index_row+1,index_col+1));

    vector<pair<int,int>>::iterator iter;

    for(iter=neighbor_coor.begin();iter!=neighbor_coor.end();iter++)
    {
      if ((iter->first > -1) && (iter->first<this->row))
      {
        if ((iter->second > -1) && (iter->second<this->column))
        {
          if (gridCellStatus[iter->first][iter->second] == "o"){n_alive_neighbor += 1;}
        }
      }
    }
    return n_alive_neighbor;
  }

  bool GridCellStatus::cellsAllDead()
  {
    for (int i=0; i<row;i++)
    {
      for (int j=0;j<column;j++)
      {
        if (gridCellStatus[i][j] == "o"){return false;}
      }
    }
    return true;
  }

} // end namespace
