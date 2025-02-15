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

    void printstate();

    virtual COLOR getColor(FACE face , int row , int col)=0;

    virtual bool isSolved() = 0;

    static std::string getMoveNotation(MOVE move);

    
};