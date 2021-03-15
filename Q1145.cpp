// 1145. Binary Tree Coloring Game (Medium)

#include <iostream>
#include "tree.h"
using namespace std;

class Solution {
public:
    TreeNode* findX(TreeNode* root, int x){
        if (root == NULL)
            return NULL;
        if (root->val == x)
            return root;
        
        TreeNode* left = findX(root->left, x);
        if (left)
            return left;
        return findX(root->right, x);
    }

    int countNode(TreeNode* root){
        if (root == NULL)
            return 0;
        return 1 + countNode(root->left) + countNode(root->right);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if (root == NULL)
            return false;
        
        TreeNode* node = findX(root,x);
        int left = countNode(node->left);
        int right = countNode(node->right);
        int rest = n - left - right - 1;

        return (left > (right + rest)) || (right > (left + rest)) || (rest > (left + right));
    }
};