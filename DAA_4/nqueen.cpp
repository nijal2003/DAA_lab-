#include <iostream>
using namespace std;

int count = 0;

bool isSafe(int board[][10], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

void solveNQueen(int board[][10], int row, int n) {
    if (row == n) {
        count++;
        cout << "Solution #" << count << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solveNQueen(board, row + 1, n);
            board[row][col] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int board[10][10] = {0};
    solveNQueen(board, 0, n);
    if (count == 0) {
        cout << "No solution found." << endl;
    }
    else {
        cout << "Total possible solutions: " << count << endl;
    }
    return 0;
}
