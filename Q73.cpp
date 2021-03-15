// 73. Set Matrix Zeroes (Medium)

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void nullRow(int row, vector<vector<int>>& matrix){
        for (int i = 0; i < int(matrix[row].size()); ++i){
            matrix[row][i] = 0;
        }
    }
    void nullCol(int col, vector<vector<int>>& matrix){
        for (int i = 0; i < int(matrix.size()); ++i){
            matrix[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        for (int i = 0; i < int(matrix.size()); ++i){
            for (int j = 0; j < int(matrix[i].size()); ++j){
                if (matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (auto r : row){
            nullRow(r, matrix);
        }
        for (auto c : col){
            nullCol(c, matrix);
        }
    }
};