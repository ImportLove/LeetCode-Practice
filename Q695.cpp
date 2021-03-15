// 695. Max Area of Island (Medium)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col){
        if (row >= grid.size() || row < 0 || col >= grid[row].size() || col < 0)
            return 0;
        if (grid[row][col] == 0 || visited[row][col])
            return 0;
        visited[row][col] = true;
        return dfs(grid, visited, row+1, col) + dfs(grid, visited, row, col-1)
            + dfs(grid, visited, row-1, col) + dfs(grid, visited, row, col+1) + 1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int height = grid.size();
        int width = grid[0].size();
        int max_area = 0;
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for (int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){
                if (!visited[i][j] && grid[i][j] == 1)
                    max_area = max(max_area, dfs(grid, visited, i, j));
            }
        }
        return max_area;
    }
};

int main(){
    Solution sol;
    vector<int> vec1 = {0, 1};
    vector<int> vec2 = {1, 1};
    vector<vector<int>> grid;
    grid.push_back(vec1);
    grid.push_back(vec2);
    cout << sol.maxAreaOfIsland(grid) << endl;
}