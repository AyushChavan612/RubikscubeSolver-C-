#ifndef RUBIKS_CUBE_SOLVER_GENERIC_CUBE

#define RUBIKS_CUBE_SOLVER_GENERIC_CUBE
#include<bits/stdc++.h>

class RubiksCube {
    public : 
    enum class COLOR {
      WHITE,
      GREEN,
      RED,
      BLUE,
      ORANGE,
      YELLOW
    };

    enum class MOVE {
       L,
       L2,
       LPRIME,
       R,
       R2,
       RPRIME,
       U,
       U2,
       UPRIME,
       B,
       B2,
       BPRIME,
       F,
       F2,
       FPRIME,
       D,D2,DPRIME
    };

    enum class FACE {
       UP,
       LEFT,
       FRONT,
       RIGHT,
       BACK,
       DOWN
    };

    static char getColorLetter(COLOR color);

    void printstate() const;

    virtual COLOR getColor(FACE face , int row , int col) const = 0;

    virtual bool isSolved() const = 0;

    static std::string getMoveNotation(MOVE move);

    RubiksCube &performMove(MOVE move);

    RubiksCube &invertMove(MOVE move);

    std::vector<MOVE> randomShuffle(long long shuffle_moves_count);

    virtual RubiksCube &f() = 0;

    virtual RubiksCube &fPrime() = 0;
  
    virtual RubiksCube &f2() = 0;
  
    virtual RubiksCube &u() = 0;
  
    virtual RubiksCube &uPrime() = 0;
  
    virtual RubiksCube &u2() = 0;
  
    virtual RubiksCube &l() = 0;
  
    virtual RubiksCube &lPrime() = 0;
  
    virtual RubiksCube &l2() = 0;
  
    virtual RubiksCube &r() = 0;
  
    virtual RubiksCube &d() = 0;
  
    virtual RubiksCube &dPrime() = 0;
  
    virtual RubiksCube &d2() = 0;
  
    virtual RubiksCube &rPrime() = 0;
  
    virtual RubiksCube &r2() = 0;
  
    virtual RubiksCube &b() = 0;
  
    virtual RubiksCube &bPrime() = 0;
  
    virtual RubiksCube &b2() = 0;
};

#endif
