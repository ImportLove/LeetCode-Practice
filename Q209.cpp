// 209. Minimum Size Subarray Sum (Medium)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int min_len = nums.size()+1;
        int left = 0, right = 0, sum = 0;
        while (right < nums.size()){
            while (sum < s && right < nums.size()){
				sum += nums[right];
                ++right;
            }

            while (sum >= s){
				min_len = min(min_len, right-left);	
                sum -= nums[left];
                ++left;
            }

        }

		if (min_len == nums.size()+1)
			return 0;
        return min_len;
    }
};
