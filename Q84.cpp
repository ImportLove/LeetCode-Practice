// 84. Largest Rectangle in Histogram (Hard)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        for (int i = 0; i < int(heights.size()); ++i){
            if (i+1 < heights.size() && heights[i] <= heights[i+1]){
                continue;
            }

            int minH = heights[i];

            for (int j = i; j >= 0; --j){
                minH = min(minH, heights[j]);
                int area = (i-j+1)*minH;
                max_area = max(max_area, area);
            }
        }

        return max_area;
    }
};

int main(){
    vector<int> vec = {2,1,5,6,4,2,3};
    Solution sol;
    cout << sol.largestRectangleArea(vec) << endl;
}