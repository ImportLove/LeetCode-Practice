// 94. Binary Tree Inorder Traversal (Medium)

#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

class Solution {
public:

	void helper(TreeNode* root, vector<int>& result){
		if (root == NULL)
			return;
		helper(root->left, result);
		result.push_back(root->val);
		helper(root->right, result);
	}

    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
        if (root == NULL)
			return result;

		helper(root, result);
		
		return result;
		
    }
};