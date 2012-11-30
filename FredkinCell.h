#include <cstdlib>
#include <string.h>
#include <vector>  // vector
#include "AbstractCell.h"

using namespace std;

#ifndef FredkinCell_h
#define FredkinCell_h

class FredkinCell : public AbstractCell
{
  public:

  int age;

  FredkinCell()
  {
    this->age = 0;
    this->alive = false;
  }

  FredkinCell(const FredkinCell* const ac)
  {
    this->alive = ac->alive;
    this->age = ac->age;
  }

  AbstractCell* clone()
  {
    return new FredkinCell(this); 
  }

  void change_state(char c)
  {
    if('-' == c)
    {
      this->alive = false;
    }
    else
    {
      this->alive = true;
      if(c >= '0' && c <= '9')
        this->age = c - '0';
    }
  }

  void evolve(int alive_neighbors)
  {
    bool temp = this->alive;
    if(!this->alive && (alive_neighbors == 1 || alive_neighbors == 3))
      this->alive = true;
    else if(this->alive && (alive_neighbors == 0 || alive_neighbors == 2 || alive_neighbors == 4))
      this->alive = false;
    if(temp && this->alive)
      ++this->age;
  }

  bool neighbors_contains(int change_r, int change_c)
  {
    return change_r == 0 || change_c == 0;
  }

  char print()
  {
    if(this->alive)
      if(this->age < 10)
        return '0' + this->age;
      else
        return '+';
    else
      return '-';
  }
};

#endif