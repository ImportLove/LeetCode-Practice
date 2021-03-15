// 145. Binary Tree Postorder Traversal (Medium)

#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

class Solution {
public:
    void postorderTraversal(TreeNode* root, vector<int>& ans){
        if (root == NULL)
            return;
        
        postorderTraversal(root->left, ans);
        postorderTraversal(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderTraversal(root, ans);
        return ans;
    }
};