// 704. Binary Search (Easy)

#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = int(nums.size());
        int mid;
        while (begin < end){
            mid = (end-begin)/2 + begin;
            if (nums[mid] < target)
                begin = mid+1;
            else if (nums[mid] > target)
                end = mid;
            else
                return mid;
        }

        return -1;
    }
};
