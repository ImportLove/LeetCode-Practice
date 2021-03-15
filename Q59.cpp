// 59. Spiral Matrix II (Medium)

#include <iostream>
#include <vector>
using namespace std;

class Solution {

private:
    int height, width;
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    bool isValid(int x, int y){
        return x >= 0 && x < height && y >= 0 && y < width;
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        height = width = n;
        vector<vector<int>> ans(n, vector<int>(n, -1));
        int count = 1, x = 0, y = 0, turn = 0, index = 0;

        while (count <= n*n){
            while (isValid(x,y) && ans[x][y] == -1){
                ans[x][y] = count;
                ++count;
                x += dirs[index][0];
                y += dirs[index][1];
            }

            x -= dirs[index][0];
            y -= dirs[index][1];
            ++turn;
            index = turn%4;
            x += dirs[index][0];
            y += dirs[index][1];
        }
        return ans;
    }
};