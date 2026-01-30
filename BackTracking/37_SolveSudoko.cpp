#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch) {

        // Check row and column
        for(int i = 0; i < 9; i++){
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
        }

        // Check 3x3 box
        int start_row = (row / 3) * 3;
        int start_col = (col / 3) * 3;

        for(int i = start_row; i < start_row + 3; i++){
            for(int j = start_col; j < start_col + 3; j++){
                if(board[i][j] == ch) return false;
            }
        }

        return true;
    } 

    bool solve(vector<vector<char>>& board) {
      
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {
                 
                    for(char ch = '1'; ch <= '9'; ch++) {

                        if(isSafe(board, i, j, ch)) {

                            board[i][j] = ch;

                            if(solve(board))
                                return true;

                            board[i][j] = '.';  // backtrack
                        }
                    }

                    return false;  // no valid number found
                }
            }     
        }

        return true;  // solved
    }

    void solveSudoku(vector<vector<char>>& board) {      
        solve(board);
    }
};

int main() {

    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter Sudoku board (use . for empty cells):\n";

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;
    obj.solveSudoku(board);

    cout << "\nSolved Sudoku:\n";

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
