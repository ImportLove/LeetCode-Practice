// 199. Binary Tree Right Side View (Medium)

#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

class Solution {
public:

	int height(TreeNode* root){
		if (root == NULL)
			return 0;
		int left = height(root->left);
		int right = height(root->right);
		return max(left, right) + 1;
	}

	void setNumByLevel(TreeNode* root, int level, int pos, vector<int>& result){
		if (root == NULL)
			return;
		if (level == 1){
			result[pos] = root->val;
			return;
		}
		setNumByLevel(root->left, level-1, pos, result);
		setNumByLevel(root->right, level-1, pos, result);
	}

    vector<int> rightSideView(TreeNode* root) {
		int h = height(root);
		vector<int> result(h, 0);
		if (root == NULL)
			return result;
			
		for (int i = 1; i <= h; ++i){
			setNumByLevel(root, i, i-1, result);
		}

		return result;
    }
};