// 980. Unique Paths III (Hard)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int height, width;
    int end;
    int visited;
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};

    bool isValid(int x, int y){
        return x >= 0 && x < height && y >= 0 && y < width;
    }

public:
    int dfs(vector<vector<int>>& grid, int v, int left){
        int x = v/width, y = v%width;
        visited += (1 << v);
        left -= 1;
        if (left == 0 && v == end){
            visited -= (1 << v);
            return 1;
        }

        int res = 0;
        for (auto& dir : dirs){
            int new_x = x+dir[0];
            int new_y = y+dir[1];
            int new_index = new_x * width + new_y;
            if (isValid(new_x,new_y) && grid[new_x][new_y] == 0 && (visited & (1 << new_index)) == 0)
                res += dfs(grid, new_index, left);
        }

        visited -= (1 << v);
        return res;
    }

    int uniquePathsIII(vector<vector<int>>& grid) { 
        height = grid.size();
        width = grid[0].size();
        visited = 0;
        int left = height*width;
        int begin;

        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                if (grid[i][j] == 1){
                    begin = i*width + j;
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == -1)
                    left -= 1;
                else if (grid[i][j] == 2){
                    end = i*width+j;
                    grid[i][j] = 0;
                }   
            }
        }

        return dfs(grid, begin, left);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << sol.uniquePathsIII(grid) << endl;
    return 0;
}