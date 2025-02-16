#include "RubiksCube.h"

// to print the state of the cube
//        U U U
//        U U U
//        U U U
// L L L  F F F  R R R  B B B
// L L L  F F F  R R R  B B B
// L L L  F F F  R R R  B B B
//        D D D
//        D D D
//        D D D

void RubiksCube::printstate() const {
    std::cout << "printing Rubikscube state : \n\n"; 

    for(int row=0; row <= 2; ++row) {
        for(int col=0; col < 7; ++col) 
        std::cout << ' ';

        for(int col=0; col <= 2; ++col) {
            std::cout << getColorLetter(getColor(RubiksCube::FACE::UP, row, col)) << ' ';
        }

        std::cout << '\n';
    }

    for(int row=0; row <= 2; ++row) {
        for(int col=0; col <= 2; ++col) {
            std::cout << getColorLetter(getColor(RubiksCube::FACE::LEFT, row, col)) << ' ';
        }
        std::cout << ' ';

        for(int col=0; col <= 2; ++col) {
            std::cout << getColorLetter(getColor(RubiksCube::FACE::FRONT, row, col)) << ' ';
        }

        std::cout << ' ';

        for(int col=0; col <= 2; ++col) {
            std::cout << getColorLetter(getColor(RubiksCube::FACE::RIGHT, row, col)) << ' ';
        }

        std::cout << ' ';

        for(int col=0; col <= 2; ++col) {
            std::cout << getColorLetter(getColor(RubiksCube::FACE::BACK, row, col)) << ' ';
        }

        std::cout << '\n';
    }

    for(int row=0; row <= 2; ++row) {
        for(int col = 0; col < 7; ++col) {
            std::cout << ' ';
        }

        for(int col = 0; col <= 2; ++col) {
            std::cout << getColorLetter(getColor(RubiksCube::FACE::DOWN, row, col)) << ' ';
        }

        std::cout << '\n';
    }

    std::cout << '\n';
}

char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
    case COLOR::BLUE:
    return 'B';
    case COLOR::WHITE:
    return 'W';
    case COLOR::RED:
    return 'R';
    case COLOR::GREEN:
    return 'G';
    case COLOR::YELLOW:
    return 'Y';
    case COLOR::ORANGE:
    return 'O';
    }
    __builtin_unreachable();
}

std::string RubiksCube::getMoveNotation(MOVE move) {
    switch(move) {
        case MOVE::L :
            return "L";

            case MOVE::L2 :
                return "L2";

            case MOVE::LPRIME :
                return "L'";

            case MOVE::R :
                return "R";
            
            case MOVE::R2 :
                return "R2";

            case MOVE::RPRIME :
                return "R'";

            case MOVE::U :
                return "U";

            case MOVE::U2 :
                return "U2";

            case MOVE::UPRIME :
                return "U'";

            case MOVE::B :
                return "B";

            case MOVE::B2 :
                return "B2";
            
            case MOVE::BPRIME :
                return "B'";

            case MOVE::F :
                return "F";

            case MOVE::F2 :
                return "F2";

            case MOVE::FPRIME :
                return "F'";

            case MOVE::D :
                return "D";

            case MOVE::D2 :
                return "D2";

            case MOVE::DPRIME :
                return "D'";
    }
    __builtin_unreachable();
}

RubiksCube& RubiksCube::performMove(MOVE move) {
        switch(move) {
            case MOVE::L : 
            return this->l();

            case MOVE::L2 :
            return this->l2();

            case MOVE::LPRIME :
            return this->lPrime();

            case MOVE::R :
            return this->r();

            case MOVE::R2 :
            return this->r2();

            case MOVE::RPRIME :
            return this->rPrime();

            case MOVE::U :
            return this->u();

            case MOVE::U2 :
            return this->u2();

            case MOVE::UPRIME :
            return this->uPrime();

            case MOVE::B :
            return this->b();

            case MOVE::B2 :
            return this->b2();

            case MOVE::BPRIME :
            return this->bPrime();

            case MOVE::F :
            return this->f();

            case MOVE::F2 :
            return this->f2();

            case MOVE::FPRIME :
            return this->fPrime();

            case MOVE::D : 
            return this->d();

            case MOVE::D2 :
            return this->d2();

            case MOVE::DPRIME :
            return this->dPrime();
        }
        __builtin_unreachable();
}

RubiksCube& RubiksCube::invertMove(MOVE move) {
    switch(move) {
            case MOVE::L : 
            return this->lPrime();

            case MOVE::L2 :
            return this->l2();

            case MOVE::LPRIME :
            return this->l();

            case MOVE::R :
            return this->rPrime();

            case MOVE::R2 :
            return this->r2();

            case MOVE::RPRIME :
            return this->r();

            case MOVE::U :
            return this->uPrime();

            case MOVE::U2 :
            return this->u2();

            case MOVE::UPRIME :
            return this->u();

            case MOVE::B :
            return this->bPrime();

            case MOVE::B2 :
            return this->b2();

            case MOVE::BPRIME :
            return this->b();

            case MOVE::F :
            return this->fPrime();

            case MOVE::F2 :
            return this->f2();

            case MOVE::FPRIME :
            return this->f();

            case MOVE::D : 
            return this->dPrime();

            case MOVE::D2 :
            return this->d2();

            case MOVE::DPRIME :
            return this->d();
        }
        __builtin_unreachable();
}


std::vector<RubiksCube::MOVE> RubiksCube::randomShuffle(long long shuffle_moves_count) {
    std::vector<RubiksCube::MOVE> moves;

    static std::random_device rd;
    static std::seed_seq seed{rd(), rd(), rd(), rd(), rd()};
    static std::mt19937 mt(seed);
    std::uniform_int_distribution<int> dist(1, 18);

    for (int i = 1; i <= shuffle_moves_count; ++i) {
        int random_move = dist(mt);
        moves.push_back(static_cast<RubiksCube::MOVE>(random_move));
        this->performMove(moves.back());
    }

    return moves;
}