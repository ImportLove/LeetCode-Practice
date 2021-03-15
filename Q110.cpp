// 110. Balanced Binary Tree (Easy)
#include <iostream>
#include "tree.h"
using namespace std;

int height(TreeNode* root){
	if (root == NULL)
		return 0;
	int left = height(root->left);
	int right = height(root->right);

	if (left > right)
		return left + 1;
	else
		return right + 1;
}

bool isBalanced(TreeNode* root) {
	if (root == NULL)
		return true;

	int l_height = height(root->left);
	int r_height = height(root->right);

	return abs(l_height - r_height) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	
}
