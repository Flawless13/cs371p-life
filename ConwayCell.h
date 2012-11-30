#include <cstdlib>
#include <string.h>
#include <vector>  // vector
#include "AbstractCell.h"

using namespace std;

#ifndef ConwayCell_h
#define ConwayCell_h

class ConwayCell : public AbstractCell
{
  public:
  // default constructor
  ConwayCell()
  {
    this->alive_bool = false;
  }

  // copy constructor
  ConwayCell(const ConwayCell* const ac)
  {
    this->alive_bool = ac->alive_bool;
  }

  // clones the cell and returns a pointer to the clone
  AbstractCell* clone()
  {
    return new ConwayCell(this); 
  }

  // changes the state of the cell based on the input character
  void change_state(char c)
  {
    if('.' == c)
      this->alive_bool = false;
    else
      this->alive_bool = true;
  }

  // evolves the cell one iteration of life
  void evolve(int alive_neighbors)
  {
    if(!this->alive_bool && alive_neighbors == 3)
      this->alive_bool = true;
    else if(this->alive_bool && (alive_neighbors < 2 || alive_neighbors > 3))
      this->alive_bool = false;
  }

  // checks if a cell within change_r rows and change_c columns is this' neighbor
  bool neighbors_contains(int change_r, int change_c)
  {
    return true;
  }

  // prints out the state of the cell as a char
  char print()
  {
    if(this->alive_bool)
      return '*';
    else
      return '.';
  }
};

#endif