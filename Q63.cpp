// 63. Unique Paths II (Medium)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        vector<vector<int>> ans(height+1, vector<int>(width+1, 0));
        if (obstacleGrid[0][0] == 0)
            ans[1][1] = 1;
        for (int i = 1; i <= height; ++i){
            for (int j = 1; j <= width; ++j){
                if (i == 1 && j == 1)
                    continue;
                if (obstacleGrid[i-1][j-1] == 1)
                    ans[i][j] = 0;  
                else
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
        return ans[height][width];
    }
};