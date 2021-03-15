// 54. Spiral Matrix (Medium)

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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        height = matrix.size();
        width = matrix[0].size();
        vector<bool> visited(height*width, false);
        int left = height * width;
        vector<int> ans;

        int x = 0, y = 0;
        int turn = 0, index = 0;

        while (left){
            while (isValid(x,y) && !visited[x*width+y]){
                
                visited[x*width+y] = true;
                ans.push_back(matrix[x][y]);
                x += dirs[index][0];
                y += dirs[index][1];
            }

            x -= dirs[index][0];
            y -= dirs[index][1];
            ++turn;
            index = turn%4;
            x += dirs[index][0];
            y += dirs[index][1];
            --left;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = sol.spiralOrder(matrix);
    cout << ans.size() << endl;
    return 0;
}