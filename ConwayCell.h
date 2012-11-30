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
    this->alive = false;
  }

  ConwayCell(const ConwayCell* const ac)
  {
    this->alive = ac->alive;
  }

  AbstractCell* clone()
  {
    return new ConwayCell(this); 
  }

  void change_state(char c)
  {
    if('.' == c)
      this->alive = false;
    else
      this->alive = true;
  }

  void evolve(int alive_neighbors)
  {
    if(!this->alive && alive_neighbors == 3)
      this->alive = true;
    else if(this->alive && (alive_neighbors < 2 || alive_neighbors > 3))
      this->alive = false;
  }

  bool neighbors_contains(int change_r, int change_c)
  {
    return true;
  }

  char print()
  {
    if(this->alive)
      return '*';
    else
      return '.';
  }
};

#endif