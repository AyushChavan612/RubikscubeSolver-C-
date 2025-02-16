#include "RubiksCube.h"
#include<vector>

class Rubikscube3Darray : public RubiksCube {
    private:
    char tempFace[3][3];

    void rotateClockwise(int face) {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                tempFace[i][j] = cube[face][i][j];
            }
        } 

        for(int row = 0; row < 3; ++row) {
            for(int col = 0; col < 3; ++col) {
                cube[face][row][col] = tempFace[col][2-row];
            }
        }
    }

    void rotateCounterClockwise(int face) {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                tempFace[i][j] = cube[face][i][j];
            }
        } 

        for(int row = 0; row < 3; ++row) {
            for(int col = 0; col < 3; ++col) {
                cube[face][row][col] = tempFace[2-col][row];
            }
        }
    }

    public:
    char cube[6][3][3];
    Rubikscube3Darray() {
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    COLOR getColor(FACE face , int row , int col) override{
        char color = cube[(int)face][row][col];
        switch (color)
        {
            case 'B':
                return COLOR::BLUE;
                break;
            case 'G':
                return COLOR::GREEN;
                break;
            case 'R':
                return COLOR::RED;
                break;
            case 'O':
                return COLOR::ORANGE;
                break;
            case 'Y':
                return COLOR::YELLOW;
                break;
            case 'W':
                return COLOR::WHITE;
                break;
        }
        __builtin_unreachable();
    }

    bool isSolved() override {
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    if(this->cube[i][j][k] != getColorLetter(COLOR(i))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    RubiksCube& f() override {
        this->rotateClockwise(2);
        char temp_arr[3] = {};
  
        for (int i = 0; i < 3; i++)
          temp_arr[i] = cube[0][2][i];
  
        for (int i = 0; i < 3; i++)
          cube[0][2][i] = cube[1][2 - i][2];
  
        for (int i = 0; i < 3; i++)
          cube[1][2 - i][2] = cube[5][0][2 - i];
  
        for (int i = 0; i < 3; i++)
          cube[5][0][2 - i] = cube[3][i][0];
  
        for (int i = 0; i < 3; i++)
          cube[3][i][0] = temp_arr[i];
  
        return *this;
    }
  
    RubiksCube &fPrime() override {
      this->f();
      this->f();
      this->f();
      return *this;
    }
  
    RubiksCube &f2() override {
      this->f();
      this->f();
      return *this;
    }
  
    RubiksCube &u() override {
      this->rotateClockwise(0);
      char temp_arr[3] = {};
  
      for (int i = 0; i < 3; i++)
        temp_arr[i] = cube[4][0][2 - i];
  
      for (int i = 0; i < 3; i++)
        cube[4][0][2 - i] = cube[1][0][2 - i];
  
      for (int i = 0; i < 3; i++)
        cube[1][0][2 - i] = cube[2][0][2 - i];
  
      for (int i = 0; i < 3; i++)
        cube[2][0][2 - i] = cube[3][0][2 - i];
  
      for (int i = 0; i < 3; i++)
        cube[3][0][2 - i] = temp_arr[i];
      return *this;
    }
  
    RubiksCube &uPrime() override {
      this->u();
      this->u();
      this->u();
      return *this;
    }
  
    RubiksCube &u2() override {
      this->u();
      this->u();
      return *this;
    }
  
    RubiksCube &l() override {
      this->rotateClockwise(1);
      char temp_arr[3] = {};
  
      for (int i = 0; i < 3; i++)
        temp_arr[i] = cube[0][i][0];
  
      for (int i = 0; i < 3; i++)
        cube[0][i][0] = cube[4][2 - i][2];
  
      for (int i = 0; i < 3; i++)
        cube[4][2 - i][2] = cube[5][i][0];
  
      for (int i = 0; i < 3; i++)
        cube[5][i][0] = cube[2][i][0];
  
      for (int i = 0; i < 3; i++)
        cube[2][i][0] = temp_arr[i];
  
      return *this;
    }
  
    RubiksCube &lPrime() override {
      this->l();
      this->l();
      this->l();
      return *this;
    }
  
    RubiksCube &l2() override {
      this->l();
      this->l();
      return *this;
    }
  
    RubiksCube &d() override {
      this->rotateClockwise(5);
      char temp_arr[3] = {};
  
      for (int i = 0; i < 3; i++)
        temp_arr[i] = cube[2][2][i];
  
      for (int i = 0; i < 3; i++)
        cube[2][2][i] = cube[1][2][i];
  
      for (int i = 0; i < 3; i++)
        cube[1][2][i] = cube[4][2][i];
  
      for (int i = 0; i < 3; i++)
        cube[4][2][i] = cube[3][2][i];
  
      for (int i = 0; i < 3; i++)
        cube[3][2][i] = temp_arr[i];
  
      return *this;
    }
  
    RubiksCube &dPrime() override {
      this->d();
      this->d();
      this->d();
      return *this;
    }
  
    RubiksCube &d2() override {
      this->d();
      this->d();
      return *this;
    }
  
    RubiksCube &r() override {
      this->rotateClockwise(3);
      char temp_arr[3] = {};
  
      for (int i = 0; i < 3; i++)
        temp_arr[i] = cube[0][2 - i][2];
  
      for (int i = 0; i < 3; i++)
        cube[0][2 - i][2] = cube[2][2 - i][2];
  
      for (int i = 0; i < 3; i++)
        cube[2][2 - i][2] = cube[5][2 - i][2];
  
      for (int i = 0; i < 3; i++)
        cube[5][2 - i][2] = cube[4][i][0];
  
      for (int i = 0; i < 3; i++)
        cube[4][i][0] = temp_arr[i];
  
      return *this;
    }
  
    RubiksCube &rPrime() override {
      this->r();
      this->r();
      this->r();
      return *this;
    }
  
    RubiksCube &r2() override {
      this->r();
      this->r();
      return *this;
    }
  
    RubiksCube &b() override {
      this->rotateClockwise(4);
  
      char temp_arr[3] = {};
  
      for (int i = 0; i < 3; i++)
        temp_arr[i] = cube[0][0][2 - i];
  
      for (int i = 0; i < 3; i++)
        cube[0][0][2 - i] = cube[3][2 - i][2];
  
      for (int i = 0; i < 3; i++)
        cube[3][2 - i][2] = cube[5][2][i];
  
      for (int i = 0; i < 3; i++)
        cube[5][2][i] = cube[1][i][0];
  
      for (int i = 0; i < 3; i++)
        cube[1][i][0] = temp_arr[i];
  
      return *this;
    }
  
    RubiksCube &bPrime() override {
      this->b();
      this->b();
      this->b();
      return *this;
    }
  
    RubiksCube &b2() override {
      this->b();
      this->b();
      return *this;
    }
};
  