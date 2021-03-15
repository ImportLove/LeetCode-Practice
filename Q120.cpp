// 120. Triangle (Medium)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;
        for (int i = 1; i < int(triangle.size()); ++i){
            for(int j = 0; j < int(triangle[i].size()); ++j){
                if (j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if (j == triangle[i].size()-1)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }

        int minstep = triangle[triangle.size()-1][0];
        for (int i = 1; i < int(triangle[triangle.size()-1].size()); ++i){
            if (triangle[triangle.size()-1][i] < minstep)
                minstep = triangle[triangle.size()-1][i];
        }

        return minstep;
    }
};