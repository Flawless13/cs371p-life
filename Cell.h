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
  AbstractCell* cell_pointer;

  public:

  Cell()
  {
    FredkinCell fc;
    cell_pointer = fc.clone();
  }

  Cell(const Cell& c)
  {
    cell_pointer = c.cell_pointer->clone();
  }

  char print()
  {
    return cell_pointer->print();
  }

  void evolve(int alive_neighbors)
  {
    cell_pointer->evolve(alive_neighbors);
    FredkinCell* fc = dynamic_cast<FredkinCell*>(cell_pointer);
    if(fc != 0 && fc->age == 2)
      change_state('*');
  }

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

  bool alive()
  {
    return cell_pointer->alive();
  }

  bool neighbors_contains(int change_r, int change_c)
  {
    return cell_pointer->neighbors_contains(change_r, change_c);
  }

  ~Cell()
  {
    delete cell_pointer;
  }
};

#endif