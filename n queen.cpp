#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> board;

bool isSafe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool solveNQUtil(int col) {
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

int main() {
    N = 4; // change to 8 for 8-Queens
    board.assign(N, vector<int>(N, 0));
    board[0][0] = 1; // first queen placed
    if (solveNQUtil(1))
        printBoard();
    else
        cout << "No solution exists.";
}
