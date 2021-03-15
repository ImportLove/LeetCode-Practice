// 9. Palindrome Number (Easy)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        vector<int> nums;
        while (x){
            nums.push_back(x%10);
            x = x/10;
        }

        for (int i = 0; i < int(nums.size())/2; ++i){
            if (nums[i] != nums[nums.size()-i-1])
                return false;
        }
        return true;
    }
};