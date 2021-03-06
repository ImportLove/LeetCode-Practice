// 70. Climbing Stairs (Easy)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1)
            return n;
        vector<int> count(n+1, 0);
        count[0] = 0;
        count[1] = 1;
        count[2] = 2;

        for (int i = 3; i <= n; ++i){
            count[i] = count[i-1] + count[i-2];
        }
        return count[n];
    }
};