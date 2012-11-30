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

  ConwayCell()
  {
    this->alive_bool = false;
  }

  ConwayCell(const ConwayCell* const ac)
  {
    this->alive_bool = ac->alive_bool;
  }

  AbstractCell* clone()
  {
    return new ConwayCell(this); 
  }

  void change_state(char c)
  {
    if('.' == c)
      this->alive_bool = false;
    else
      this->alive_bool = true;
  }

  void evolve(int alive_neighbors)
  {
    if(!this->alive_bool && alive_neighbors == 3)
      this->alive_bool = true;
    else if(this->alive_bool && (alive_neighbors < 2 || alive_neighbors > 3))
      this->alive_bool = false;
  }

  bool neighbors_contains(int change_r, int change_c)
  {
    return true;
  }

  char print()
  {
    if(this->alive_bool)
      return '*';
    else
      return '.';
  }
};

#endif