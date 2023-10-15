#include <iostream>
using namespace std;

const int N = 4; 

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;

        // Move right
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        // Move down
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

        // If no valid path is found, backtrack
        sol[x][y] = 0;
        return false;
    }

    return false;
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        cout << "No path exists." << endl;
        return false;
    }

    cout << "Path found:" << endl;
    printSolution(sol);
    return true;
}

int main() {
    int maze[N][N] = {{0, 1, 1, 0},
                      {0, 0, 1, 0},
                      {1, 0, 1, 0},
                      {0, 0, 0, 0}};

    solveMaze(maze);
    return 0;
}
