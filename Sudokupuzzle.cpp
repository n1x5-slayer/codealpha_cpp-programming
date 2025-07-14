#include <iostream>
using namespace std;

const int N = 9;

// Dummy solvable puzzle (0 = empty cell)
int puzzle[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// Solved version of above puzzle for checking answers
int solution[N][N] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};

void printGrid(int grid[N][N]) {
    cout << "\nCurrent Sudoku Grid:\n";
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0 && row != 0) cout << "------+-------+------\n";
        for (int col = 0; col < N; col++) {
            if (col % 3 == 0 && col != 0) cout << "| ";
            if (grid[row][col] == 0)
                cout << ". ";
            else
                cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool isPuzzleComplete() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (puzzle[i][j] == 0)
                return false;
    return true;
}

int main() {
    int row, col, num;
    cout << "===== Sudoku Interactive Game =====\n";
    cout << "Note: Rows and columns are 0-indexed (0 to 8).\n";

    while (!isPuzzleComplete()) {
        printGrid(puzzle);

        cout << "\nEnter row (0-8): ";
        cin >> row;
        cout << "Enter column (0-8): ";
        cin >> col;

        if (puzzle[row][col] != 0) {
            cout << "Cell already filled. Try another cell.\n";
            continue;
        }

        cout << "Enter your guess (1-9): ";
        cin >> num;

        if (num == solution[row][col]) {
            puzzle[row][col] = num;
            cout << "? Correct!\n";
        } else {
            cout << "? Incorrect! Try again.\n";
        }
    }

    cout << "\n?? Puzzle completed successfully! Well done!\n";
    printGrid(puzzle);
    return 0;
}

