// 96. Unique Binary Search Trees (Medium)

/*
    Given n, how many structurally unique BST's (binary search trees) 
        that store values 1 ... n?
*/

// reference: Catalan Number
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1, 0);
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i <= n; ++i){
            for (int j = 0; j < i; ++j){
                res[i] += res[j]*res[i-j-1];
            }
        }
        return res[n];
    }
    
};

int main(){
    Solution sol;
    int result = sol.numTrees(3);
    cout << result << endl;
    return 0;
}