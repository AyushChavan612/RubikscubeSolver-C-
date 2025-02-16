#include "models/3DArrayModel.cpp"
using namespace std;

int main()
{
  Rubikscube3Darray cube1, cube2, cube3, cube4, cube5, cube6;
  cube1.d2();
  cube1.printstate();
  cube1.b2();
  cube1.printstate();
  cube1.l2();
  cube1.printstate();
  cube1.d();
  cube1.printstate();
  cube1.r();
  cube1.printstate();
  cube1.bPrime();
  cube1.printstate();
  return 0;
}