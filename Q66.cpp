// 66. Plus One (Easy)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int size = digits.size(), carry = 0, adder = 1;
        for (int i = size-1; i >= 0; --i){
            int res = digits[i] + carry + adder;
            if (adder == 1)
                adder = 0;
            carry = 0;
            if (res >= 10){
                carry = 1;
                res -= 10;
            }
            ans.push_back(res);
        }
        if (carry != 0)
            ans.push_back(carry);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};