// 470. Implement Rand10() Using Rand7()

#include <iostream>
using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:

    // Solution provided by LeetCode Official (Rejection Sampling)
    int rand10() {
        int index;
        do{
            int row = rand7();
            int col = rand7();
            index = row + (col-1)*7;
        } while (index > 40);
        return 1+(index-1)%10;
    }
};
