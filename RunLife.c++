// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2012
// Glenn P. Downing
// -------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall RunLife.c++ -o RunLife.c++.app
    % valgrind RunLife.c++.app > RunLife.out

To configure Doxygen:
    doxygen -g
That creates the file Doxyfile.
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <fstream>
#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"

// ----
// main
// ----

int main () 
{
  using namespace std;
  ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

  // ------------------
  // Conway Cell 109x69
  // ------------------

  try 
  {
    /*
      read RunLifeConway.in // assume all Conway cells
      Print grid.
      Simulate 283 moves.
      Print grid.
      Simulate 40 moves.
      Print grid.
      Simulate 2500 moves.
      Print grid.
    */

    ifstream in_file;
    in_file.open ("RunLifeConway.in");
    ofstream out_file;
    out_file.open ("RunLifeConway.out");

    Life<ConwayCell> life(in_file, out_file);
    life.print(0);
    life.step(283);
    life.print(283);
    life.step(40);
    life.print(323);
    life.step(2500);
    life.print(2823);
  }
  catch (const invalid_argument&) 
  {
    assert(false);
  }
  catch (const out_of_range&) 
  {
    assert(false);
  }

  // ------------------
  // Fredkin Cell 20x20
  // ------------------

  try 
  {
    /*
      read RunLifeFredkin.in // assume all Fredkin cells
      Print grid.
      Simulate 2 moves.
      Print every grid.
    */

    ifstream in_file;
    in_file.open ("RunLifeFredkin.in");
    ofstream out_file;
    out_file.open ("RunLifeFredkin.out");

    Life<FredkinCell> life(in_file, out_file);
    life.print(0);
    for(int i = 0; i < 2; i++)
    {
      life.step(1);
      life.print(i + 1);
    }
  }
  catch (const invalid_argument&) 
  {
    assert(false);
  }
  catch (const out_of_range&) 
  {
    assert(false);
  }

  // ----------
  // Cell 20x20
  // ----------

  try 
  {
    /*
      read RunLife.in // assume all Fredkin cells
      Print grid.
      Simulate 5 moves.
      Print every grid.
    */

    ifstream in_file;
    in_file.open ("RunLife.in");
    ofstream out_file;
    out_file.open ("RunLife.out");

    Life<Cell> life(in_file, out_file);
    life.print(0);
    for(int i = 0; i < 5; i++)
    {
      life.step(1);
      life.print(i + 1);
    }
  }
  catch (const invalid_argument&) 
  {
    assert(false);
  }
  catch (const out_of_range&) 
  {
    assert(false);
  }

  return 0;
}
