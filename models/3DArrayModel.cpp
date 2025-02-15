#include "RubiksCube.h"

class Rubikscube3Darray : public RubiksCube {
    private:
    char tempface[3][3]{};

    void rotateClockwise(int face) {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) [
                tempface[i][j] = cube[face][i][j];
            ]
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
   
};