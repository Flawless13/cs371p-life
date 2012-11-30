#include <cstdlib>
#include <vector>  // vector

using namespace std;

#ifndef AbstractCell_h
#define AbstractCell_h

class AbstractCell
{
  public:

  bool alive_bool;

  virtual char print() = 0;
  virtual void evolve(int alive_neighbors) = 0;
  virtual AbstractCell* clone() = 0;
  virtual void change_state(char c) = 0;
  virtual bool neighbors_contains(int change_r, int change_c) = 0;
  
  bool alive()
  {
    return alive_bool;
  }
};

#endif