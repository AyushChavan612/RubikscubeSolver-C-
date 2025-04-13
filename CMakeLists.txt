cmake_minimum_required(VERSION 3.20)
project(godshand)

set(CMAKE_CXX_STANDARD 14)

# Include necessary header directories
include_directories(models)
include_directories(PatternDatabases)
include_directories(solver)

add_executable(rubiks_cube_solver
    main.cpp

    # Model Files
    models/RubiksCube.cpp
    models/RubiksCube.h
    models/1DArrayModel.cpp
    models/3DArrayModel.cpp
    models/RubiksCubeBitBoard.cpp

    # Pattern Database Files
    PatternDatabases/NibbleArray.cpp
    PatternDatabases/NibbleArray.h
    PatternDatabases/PatternDatabase.cpp
    PatternDatabases/PatternDatabase.h
    PatternDatabases/PermutationIndexer.h
    PatternDatabases/CornerPatternDatabase.cpp
    PatternDatabases/CornerPatternDatabase.h
    PatternDatabases/CornerDatabaseMaker.cpp
    PatternDatabases/CornerDatabaseMaker.h
    PatternDatabases/math.cpp
    PatternDatabases/math.h

    # Solver Files
    solver/DFSSolver.h
    solver/BFSSolver.h
    solver/IDDFSSolver.h
    solver/IDAStarSolver.h
)
