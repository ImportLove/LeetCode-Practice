// 53. Maximum Subarray (Easy)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = INT32_MIN;
        for (int i = 0; i < int(nums.size()); ++i){
            sum = max(nums[i], sum + nums[i]);
            max_sum = max(sum, max_sum);
        }

        return max_sum;
    }
};