#include "models/3DArrayModel.cpp"
#include "solver/BFSSolver.h"
#include "solver/DFSSolver.h"
#include "solver/IDDFSSolver.h"
#include "models/1DArrayModel.cpp"
using namespace std;

int main() {
  
  RubiksCube1DArray cube;

  cube.randomShuffleCube(7);
  cube.print();

  IDDFSSolver<RubiksCube1DArray, Hash1d> IDDFSSolver(cube , 5);
  vector<RubiksCube::MOVE> moves = IDDFSSolver.IDDFS();
  for(auto & Move : moves) {
    cout << RubiksCube::getMove(Move) << " ";
  }

  IDDFSSolver.rubiksCube.print();

  return 0;
}