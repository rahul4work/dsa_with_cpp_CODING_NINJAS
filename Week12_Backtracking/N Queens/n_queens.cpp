/*
N QUEENS
level: hard

Problem statement
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way
to place 'N' queens such that no queen can attack any other queen on the chessboard.

A queen can be killed when it lies in the same row, or same column, or the same 
diagonal of any of the other queens. You have to print all such configurations.


Constraints:
1 <= 'N' <= 10

Time Limit: 1sec


------------------------------------------------------------------------------------
Sample Input 1:
4
Sample Output 1:
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
Explanation For Sample Input 1:
Output depicts two possible configurations of the chessboard for 4 queens.

The Chessboard matrix for the first configuration looks as follows:-

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

Queen contained cell is depicted by 1. As seen, No queen is in the same row, column,
or diagonal as the other queens. Hence this is a valid configuration.
------------------------------------------------------------------------------------



------------------------------------------------------------------------------------
Sample Input 2:
3
Sample Output2:
      (Blank)
Explanation For Sample Input 2:
Since no possible configuration exists for 3 Queen's.The output remains Empty.
------------------------------------------------------------------------------------
*/


#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
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

void solveNQueensUtil(int n, int row, vector<vector<int>>& board, vector<vector<int>>& result) {
    if (row == n) {
        vector<int> solution;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                solution.push_back(board[i][j]);
            }
        }
        result.push_back(solution);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solveNQueensUtil(n, row + 1, board, result);
            board[row][col] = 0; 
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> result;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveNQueensUtil(n, 0, board, result);
    return result;
}




int main() {
    int n;
    cin >> n;
    vector<vector<int>> answer;
    answer = solveNQueens(n);

    for (auto sol : answer) {
        for (auto i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}


