// #include "models/3DArrayModel.cpp"
#include "solver/BFSSolver.h"
#include "solver/DFSSolver.h"
#include "solver/IDDFSSolver.h"
#include "solver/IDAStarSolver.h"
// #include "models/1DArrayModel.cpp"
// #include "models/RubiksCubeBitBoard.cpp"
#include "PatternDatabases/CornerDatabaseMaker.h"

using namespace std;

int main()
{

  // // Testing all models and all solvers except IDA star
  // RubiksCubeBitboard bit;
  // RubiksCube1DArray one_d;
  // RubiksCube3dArray three_d;

  // bit.randomShuffleCube(4);
  // one_d.randomShuffleCube(4);
  // three_d.randomShuffleCube(4);

  // cout << "Printing bitBoard Cube and solving usng bfs : " << endl;
  // bit.print();

  // BFSSolver<RubiksCubeBitboard, HashBitboard> BFS(bit);
  // vector<RubiksCube::MOVE> moves = BFS.solve();
  // for(auto & Move : moves) {
  //   cout << RubiksCube::getMove(Move) << " ";
  // }
  // cout << endl;
  // BFS.rubiksCube.print();

  // cout << "Printing 1DarrayModel Cube and solving usng DFS : " << endl;
  // one_d.print();

  // DFSSolver<RubiksCube1DArray, Hash1d> DFS(one_d);
  // moves = DFS.solve();
  // for(auto & Move : moves) {
  //   cout << RubiksCube::getMove(Move) << " ";
  // }
  // cout << endl;
  // DFS.rubiksCube.print();

  // cout << "Printing 3DarrayModel and solving using IDDFS : " << endl;
  // three_d.print();

  // IDDFSSolver<RubiksCube3dArray, Hash3d> IDDFS(three_d);
  // moves = IDDFS.IDDFS();
  // for(auto & Move : moves) {
  //   cout << RubiksCube::getMove(Move) << " ";
  // }
  // cout << endl;
  // IDDFS.rubiksCube.print();

  // CornerPatternDatabase Testing ---------------------------------------------------------------------------------

  //  CornerPatternDatabase cornerDB;
  //  RubiksCubeBitboard cube;
  //  cube.print();

  //  cout << (int)cornerDB.getNumMoves(cube) << "\n";

  //  cornerDB.setNumMoves(cube, 5);

  //  cout << (int)cornerDB.getNumMoves(cube) << "\n";

  //  cube.randomShuffleCube(1);
  //  cube.print();
  //  cout << (int)cornerDB.getNumMoves(cube) << "\n";

  //  cornerDB.setNumMoves(cube, 6);

  //  cout << (int)cornerDB.getNumMoves(cube) << "\n";

  // IdAstar testing
  string fileName = "/mnt/f/godsHand/Database/PatternDatabase.txt";

  //    Code to create Corner Database
  CornerDBMaker dbMaker(fileName, 0x99);
  dbMaker.bfsAndStore();

  RubiksCubeBitboard cube;
  auto shuffleMoves = cube.randomShuffleCube(13);
  cube.print();

  IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
  auto moves = idaStarSolver.solve();

  idaStarSolver.rubiksCube.print();
  for (auto move : moves)
    cout << cube.getMove(move) << " ";
  cout << "\n";

  return 0;
}
