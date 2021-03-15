// 144. Binary Tree Preorder Traversal (Medium)

#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

class Solution {
public:
    void preorderTraversal(TreeNode* root, vector<int>& ans){
        if (root == NULL)
            return;
        ans.push_back(root->val);
        preorderTraversal(root->left, ans);
        preorderTraversal(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderTraversal(root, ans);
        return ans;
    }
};