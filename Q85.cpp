// 85. Maximal Rectangle (Hard)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        int height = int(matrix.size());
        int width = int(matrix[0].size());
        vector<vector<int>> max_l(height, vector<int>(width, 0));
        for(int i = 0; i < height; ++i){
            int max_num_one = 0;
            for (int j = 0; j < width; ++j){
                if (matrix[i][j] == '0'){
                    max_num_one = 0;
                    max_l[i][j] = max_num_one;
                }
                else{
                    max_num_one += 1;
                    max_l[i][j] = max_num_one;
                }  
            }
        }

        int max_area = 0;
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                if (matrix[i][j] == '1'){
                    int cur_length = max_l[i][j];
                    for (int k = i; k >= 0; --k){
                        cur_length = min(cur_length, max_l[k][j]);
                        max_area = max(max_area, cur_length*(i-k+1));
                        if (cur_length == 0)
                            break;
                    }
                }
            }
        }

        return max_area;

    }
};