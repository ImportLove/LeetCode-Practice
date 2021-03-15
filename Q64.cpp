// 64. Minimum Path Sum (Medium)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        vector<vector<int>> ans(grid.begin(), grid.end());
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    ans[i][j] = ans[i][j-1] + grid[i][j];
                else if (j == 0)
                    ans[i][j] = ans[i-1][j] + grid[i][j];
                else
                    ans[i][j] = min(ans[i][j-1], ans[i-1][j]) + grid[i][j];
            }
        }

        return ans[height-1][width-1];
    }
};