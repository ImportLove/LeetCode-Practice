// 129. Sum Root to Leaf Numbers (Medium)
#include <iostream>
#include "tree.h"
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root, int sum){
        if (root == NULL)
            return 0;
        sum = sum*10 + root->val;
        if (root->left == NULL && root->right == NULL)
            return sum;
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return 0;
        return sumNumbers(root, 0);
    }
};