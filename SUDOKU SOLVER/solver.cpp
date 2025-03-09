#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char>>& board) {
    int rowHash[9][10] = {0};
        int colHash[9][10] = {0};
        int subGridHash[9][10] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';

                    if (rowHash[i][num]++ > 0)
                        return false;

                    if (colHash[j][num]++ > 0)
                        return false;

                    int subGridIndex = (i / 3) * 3 + (j / 3);
                    if (subGridHash[subGridIndex][num]++ > 0)
                        return false;
                }
            }
        }

        return true;
}
bool isValid1(int row, int col, vector<vector<char>>& board, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) {
            return false;
        }
        if (board[i][col] == c) {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid1(i, j, board, c)) {
                        board[i][j] = c;

                        if (solve(board)) {
                            return true;
                        } else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main() {
    int n;
    cout << "INSTRUCTIONS FOR INPUT" << endl;
    cout << "1. The number of rows/columns must be 9" << endl;
    cout << "2. The spaces should be denoted by '.'" << endl;
    cout << "Enter the number of rows/columns" << endl;
    cin >> n;
    if (n != 9) {
        cout << "The number of rows/columns should be 9" << endl;
    }
     
    vector<vector<char>> board(n, (vector<char>(n, '.')));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    if (!isValid(board)) {
        cout << "Check your sudoku as it is not valid" << endl;
    }

    solve(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }    
    return 0;
}