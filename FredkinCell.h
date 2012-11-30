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
  // data-member to denote age
  int age;

  // default constructor
  FredkinCell()
  {
    this->age = 0;
    this->alive_bool = false;
  }

  // copy constructor
  FredkinCell(const FredkinCell* const ac)
  {
    this->alive_bool = ac->alive_bool;
    this->age = ac->age;
  }

  // clones the cell and returns a pointer to the clone
  AbstractCell* clone()
  {
    return new FredkinCell(this); 
  }

  // changes the state of the cell based on the input character
  void change_state(char c)
  {
    if('-' == c)
    {
      this->alive_bool = false;
    }
    else
    {
      this->alive_bool = true;
      if(c >= '0' && c <= '9')
        this->age = c - '0';
    }
  }

  // evolves the cell one iteration of life
  void evolve(int alive_neighbors)
  {
    bool temp = this->alive_bool;
    if(!this->alive_bool && (alive_neighbors == 1 || alive_neighbors == 3))
      this->alive_bool = true;
    else if(this->alive_bool && (alive_neighbors == 0 || alive_neighbors == 2 || alive_neighbors == 4))
      this->alive_bool = false;
    if(temp && this->alive_bool)
      ++this->age;
  }

  // checks if a cell within change_r rows and change_c columns is this' neighbor
  bool neighbors_contains(int change_r, int change_c)
  {
    return change_r == 0 || change_c == 0;
  }

  // print out the state of the cell as a character
  char print()
  {
    if(this->alive_bool)
      if(this->age < 10)
        return '0' + this->age;
      else
        return '+';
    else
      return '-';
  }
};

#endif