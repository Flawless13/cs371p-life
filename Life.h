#include <cstdlib>
#include <iostream>  // endl, istream, ostream
#include <string>    // strings for names
#include <vector>    // vector

#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

using namespace std;

template<typename T>
class Life
{
  vector< vector<T> > _grid;
  vector< vector<int> > neighbor_count;
  int rows;
  int cols;
  int population;

  public:
  
  Life(istream& r = cin, ostream& w = cout)
  {
    char next;
    population = 0;

    r >> rows;
    r >> cols;

    vector<T> rowT(cols, T());
    _grid = vector< vector<T> >(rows, rowT);

    vector<int> rowI(cols, 0);
    neighbor_count = vector< vector<int> >(rows, rowI);

    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
      {
        r >> next;
        _grid[i][j].change_state(next);
      }
  }

  void update_neighbors()
  {
    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
        neighbor_count[i][j] = 0;
    population = 0;
    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
        if(_grid[i][j].alive)
        {
          ++population;
          for(int x = -1; x <= 1; x++)
            for(int y = -1; y <= 1; y++)
              if((i + x >= 0) && (j + y >= 0))                       // grid contains
                if((i + x < rows) && (j + y < rows))                 // grid contains
                  if(!(x == 0 && y == 0))                            // not self
                    if(_grid[i + x][j + y].neighbors_contains(x, y)) // neighbor contains
                      ++neighbor_count[i + x][j + y];
        }
  }

  void step(int steps)
  {
    for(int x = 0; x < steps; x++)
    {
      update_neighbors();
      for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
          _grid[i][j].evolve(neighbor_count[i][j]);
    }
  }

  void print(int generation, ostream& w = cout)
  {
    w << "Generation = " << generation << ", Population = " << population <<  "." << endl;
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < cols; j++)
        _grid[i][j].print(w);
      w << endl;
    }
    w << endl;
  }
};