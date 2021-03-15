// 42. Trapping Rain Water (Hard)

#include <iostream>
#include <vector>
using namespace std;

/*
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;
        int left = height[0], right = height[height.size()-1];
        int sum = 0;
        int i = 1, j = int(height.size()-2);
        while (i <= j){
            if (left < right){
                if (left > height[i])
                    sum += left - height[i];
                else 
                    left = height[i];
                ++i;
            }
            else {
                if (right > height[j])
                    sum += right - height[j];
                else
                    right = height[j];
                --j;
            }
        }

        return sum;
    }
};