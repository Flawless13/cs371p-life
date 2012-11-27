#include <cstdlib>
#include <vector>  // vector

using namespace std;

#ifndef AbstractCell_h
#define AbstractCell_h

class AbstractCell
{
  public:

  bool alive;

  virtual void print(ostream& w = cout) {};
  virtual void evolve(int alive_neighbors) {};
  virtual AbstractCell* clone() = 0;
  virtual void change_state(char c) {};
  virtual bool neighbors_contains(int change_r, int change_c) = 0;
  virtual ~AbstractCell() {};
};

#endif