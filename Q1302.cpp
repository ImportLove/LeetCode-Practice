// 1302. Deepest Leaves Sum (Medium)

#include <iostream>
#include "tree.h"
using namespace std;

class Solution {
public:
	int height (TreeNode* root){
		if (root == NULL)
			return 0;
		int left = height(root->left);
		int right = height(root->right);
		return max(left, right) + 1;
	}

	int helper(TreeNode* root, int depth){
		if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL){
            if (depth == 1){
				return root->val;
			}
			return 0;
		}
        
        return helper(root->left, depth-1) + helper(root->right, depth-1);
	}

    int deepestLeavesSum(TreeNode* root) {
		if (root == NULL)
			return 0;
        int h = height(root);
		return helper(root, h);
    }
};