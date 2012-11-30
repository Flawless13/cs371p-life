#include <cstdlib>
#include <vector>  // vector

using namespace std;

#ifndef AbstractCell_h
#define AbstractCell_h

class AbstractCell
{
  public:

  // data-member for alive status 
  bool alive_bool;

  // prints out the status of the cell as a char
  virtual char print() = 0;
  // evolves the cell one iteration
  virtual void evolve(int alive_neighbors) = 0;
  // clones the cell and returns a pointer to the clone
  virtual AbstractCell* clone() = 0;
  // changes the state of the cell
  virtual void change_state(char c) = 0;
  // checks if a cell within change_r rows and change_c columns is this' neighbor
  virtual bool neighbors_contains(int change_r, int change_c) = 0;
  
  // returns the only data-member
  bool alive()
  {
    return alive_bool;
  }
};

#endif