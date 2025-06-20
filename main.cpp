
#include <bits/stdc++.h>
#include "Model/RubiksCube3dArray.cpp"
//#include "Model/RubiksCube1dArray.cpp"
//#include "Model/RubiksCubeBitboard.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
#include "PatternDatabases/CornerPatternDatabase.h"
#include "PatternDatabases/CornerDBMaker.h"

using namespace std;

int main() {
    RubiksCube3dArray cube;
    cube.print();

    // Shuffle the cube with 6 random moves
    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    cout << "Shuffle moves: ";
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    // Solve using DFS
    DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8); // 8 is the max depth
    vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();

    cout << "Solution moves: ";
    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    dfsSolver.rubiksCube.print();

    return 0;
}