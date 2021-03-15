// 113. Path Sum II (Medium)

#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

void pathSum(TreeNode* root, int sum, int cur_sum, vector<int> tmp, vector<vector<int>>& result){
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL){

		// reach the leaf node of the tree
		// either push to the result or give it up
		tmp.push_back(root->val);
		cur_sum += root->val;
		if (sum == cur_sum)
			result.push_back(tmp);
		return;
	}

	cur_sum += root->val;
	tmp.push_back(root->val);

	pathSum(root->left, sum, cur_sum, tmp, result);
	pathSum(root->right, sum, cur_sum, tmp, result);
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector < vector <int> > result;
    vector<int> tmp;
	int cur_sum = 0;
	pathSum(root, sum, cur_sum, tmp, result);
	return result;
}
