File Path
-----------------------

Source file of Part A : ./code/lib/golMyFunctions.cpp
Header file of Part A : ./code/lib/golMyFunctions.h
Source file of Part B : ./code/lib/golGame.cpp
Header file of Part B : ./code/lib/golGame.h
Command line source code of part B: ./code/CommandLineApps/gofSimulator.cpp
Command line source code of part C: ./code/CommandLineApps/golStillLife.cpp

Question Answer:
I found 5 different types of still life pattern in 4 by 4 grid (One type means a unique shape of all alive cells, without considering the position in the grid).


Build Steps
-----------------------

1. Open the project in container.
2. Create a new folder named 'build' [code] mkdir build
3. Enter the 'build' folder [code] cd build
4. Config the project. [code] cmake ..
5. Create Executable file. [code] make


Instruction for Use
-----------------------

Example command to run 'gofSimulator'. (When you are in the directory 'build')

1. View usage information
[code] ./bin/gofSimulator
[code] ./bin/gofSimulator -h
[code] ./bin/gofSimulator --help
[Output]
Usage: ./bin/gofSimulator <option(s)> SOURCES 
Option 1:
        Starting by entering (1) '.txt' file path (2)  Number of Generations. 
        Sample input:    ./gofSimulator "../Testing/Data/glider.txt" 5
Option 2:
        Starting with random cell contents by entering (1) Row (2) Column (3) Number of alive cells .4) Number of Generations. 
        Sample input:    ./gofSimulator 10 10 40 5 
Option 3:
        -h,--help               Show this help message

2. Option 1: specifying a text file input
[code] ./bin/gofSimulator "../Testing/Data/glider.txt" 10
[FinalOutput]
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - o - - - - -
- - - - - o - - - -
- - - o o o - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -

3. Option 2: starting with random cell contents for the initial conditions. parameter{n_row n_column n_alive_cell n_generation}
[code] ./bin/gofSimulator 7 7 15 10
[FinalOutput]
- - o o o - -
- - o o o - -
- - - o - o o
- - - - o o o
o o - - - o o
o - o - - - -
- o o - - - -

Example command to run 'gofSimulator'. (When you are in the directory 'build')

1. View usage information
[code] ./bin/golStillLife
[code] ./bin/golStillLife -h
[code] ./bin/golStillLife --help
[Output]
Usage: ./bin/golStillLife <option(s)> SOURCES 
Function: Find the Still Life Pattern in Conway's Game. 
Option 1:
        Starting with random cell contents by entering (1) Number of alive cells (2) Row (3) Column (4) Number of Iterations. 
        Sample input:    ./golStillLife 40 10 10 8 
Option 2:
        -h,--help               Show this help message

2. Print the resulting Still Life pattern. parameter{n_alive_cell n_row n_column n_generation}
[code] ./bin/golStillLife 20 8 8 20
[SampleStillLifePattern]
- - - - - - - -
- - - - - - o o
- - - - - - o o
o o - - - - - -
o o - - - - - -
- - - - - - - -
- - - - - - - -
- - - - - - - -

