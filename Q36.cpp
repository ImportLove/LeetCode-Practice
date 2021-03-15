// 36. Valid Sudoku (Medium)

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidBox(vector<vector<char>>& board, int row, int col){
        set<char> check;
        for (int i = row; i < row+3; ++i){
            for (int j = col; j < col+3; ++j){
                if (board[i][j] == '.')
                    continue;
                if (check.count(board[i][j]))
                    return false;
                check.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidRow(vector<vector<char>>& board, int row){
        set<char> check;
        for (int i = 0; i < 9; ++i){
            if (board[row][i] == '.')
                continue;
            if (check.count(board[row][i]))
                return false;
            check.insert(board[row][i]);
        }
        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int col){
        set<char> check;
        for (int i = 0; i < 9; ++i){
            if (board[i][col] == '.')
                continue;
            if (check.count(board[i][col]))
                return false;
            check.insert(board[i][col]);
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; ++i){
            if (!isValidRow(board, i) || !isValidCol(board, i))
                return false;
        }

        int row = 0;
        int col = 0;
        for (int i = 0; i < 3; ++i){
            row = 0;
            for (int j = 0; j < 3; ++j){
                if (!isValidBox(board, row, col))
                    return false;
                row += 3;
            }
            col += 3;
        }
        return true;
    }
};