#include <cstdlib>
#include <fstream>  // endl, istream, ostream
#include <string>    // strings for names
#include <vector>    // vector
#include <typeinfo>

#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

using namespace std;

template<typename T>
class Life
{
  // grid of cells
  vector< vector<T> > _grid;
  // grid of neighbor counts
  vector< vector<int> > neighbor_count;
  // number of rows in the grid
  int rows;
  // number of columns in the grid
  int cols;
  // population of alive cells in the grid
  int population;
  // output stream to print out to
  ofstream& out_file;

  public:
  
  // default constructor
  Life(ifstream& r, ofstream& w, bool running = false) : 
    out_file(w)
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

    update_neighbors();
    if(running)
    {
      string temp = typeid(_grid[0][0]).name();
      string type_t = "";
      for(int i = 0; i < (int)temp.length(); i++)
        if(!isdigit(temp[i]))
          type_t += temp[i];
      out_file << "*** Life<" << type_t << "> " << rows << "x" << cols << " ***" << endl << endl;
    }
  }

  // updates the population and neighbor counts grid
  void update_neighbors()
  {
    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
        neighbor_count[i][j] = 0;
    population = 0;
    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
        if(_grid[i][j].alive())
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

  // steps through the number of iterations of life that you tell it to
  void step(int steps)
  {
    for(int x = 0; x < steps; x++)
    {
      for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
          _grid[i][j].evolve(neighbor_count[i][j]);
      update_neighbors();
    }
  }

  // prints out the entire grid
  void print(int generation)
  {
    out_file << "Generation = " << generation << ", Population = " << population <<  "." << endl;
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < cols; j++)
        out_file << _grid[i][j].print();
      out_file << endl;
    }
    out_file << endl;
  }
};
