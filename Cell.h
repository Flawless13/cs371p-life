#include <cstdlib>
#include <vector>  // vector

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

using namespace std;

#ifndef Cell_h
#define Cell_h

class Cell
{
  // pointer that this class is a wrapper for
  AbstractCell* cell_pointer;

  public:

  // default constructor
  Cell()
  {
    FredkinCell fc;
    cell_pointer = fc.clone();
  }

  // copy constructor
  Cell(const Cell& c)
  {
    cell_pointer = c.cell_pointer->clone();
  }

  // prints out a char for the state
  char print()
  {
    return cell_pointer->print();
  }

  // evolves the cell one iteration
  void evolve(int alive_neighbors)
  {
    cell_pointer->evolve(alive_neighbors);
    FredkinCell* fc = dynamic_cast<FredkinCell*>(cell_pointer);
    if(fc != 0 && fc->age == 2)
      change_state('*');
  }

  // changes the state of the cell based on the character input
  void change_state(char c)
  {
    FredkinCell* fc = dynamic_cast<FredkinCell*>(cell_pointer);
    if(fc != 0 && ('*' == c || '.' == c))
    {
      delete cell_pointer;
      ConwayCell cc;
      cell_pointer = cc.clone();
    }
    cell_pointer->change_state(c);
  }

  // returns if the cell is alive or dead
  bool alive()
  {
    return cell_pointer->alive();
  }

  // checks if a cell within change_r rows and change_c columns is this' neighbor
  bool neighbors_contains(int change_r, int change_c)
  {
    return cell_pointer->neighbors_contains(change_r, change_c);
  }

  // destructor
  ~Cell()
  {
    delete cell_pointer;
  }
};

#endif
