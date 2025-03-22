#include "models/3DArrayModel.cpp"
#include "solver/BFSSolver.h"
#include "solver/DFSSolver.h"
#include "solver/IDDFSSolver.h"
using namespace std;

int main() {
  
  RubiksCube3dArray cube;

  cube.randomShuffleCube(3);
  cube.print();

  IDDFSSolver<RubiksCube3dArray, Hash3d> IDDFSSolver(cube , 5);
  vector<RubiksCube::MOVE> moves = IDDFSSolver.IDDFS();
  for(auto & Move : moves) {
    cout << RubiksCube::getMove(Move) << " ";
  }

  IDDFSSolver.rubiksCube.print();



  return 0;
}