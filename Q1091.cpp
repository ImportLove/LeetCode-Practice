// 1091. Shortest Path in Binary Matrix (Medium)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isValid(int row, int col, int size){
        return row >= 0 && row < size && col >= 0 && col < size;
    }

    void addAll(vector<vector<int>>& grid, queue<int>& q, vector<vector<bool>>& visited, int row, int col, int size){
        
        for(int i = -1; i <= 1; ++i){
            for (int j = -1; j <= 1; ++j){
                if (isValid(row+i, col+j, size) && !visited[row+i][col+j] && grid[row+i][col+j] == 0){
                    visited[row+i][col+j] = true;
                    q.push((row+i)*size + col+j);
                }
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size = grid.size();
        if (grid[0][0] == 1)
            return -1;
        vector<vector<bool>> visited(size, vector<bool>(size, false));

        queue<int> q; // store coordinate;
        q.push(0);
        visited[0][0] = true;

        int row, col;

        int min_step = 0;
        while (!q.empty()){
            ++min_step;
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i){
                int index = q.front();
                q.pop();
                row = index/size;
                col = index%size;
                if (row == size-1 && col == size-1)
                    return min_step;
                addAll(grid, q, visited, row, col, size);
            }
        }

        return -1;
    }
};