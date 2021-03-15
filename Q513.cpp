// 513. Find Bottom Left Tree Value

#include <iostream>
#include "tree.h"
using namespace std;

/*
    Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

    Output:
    7
*/

class Solution {
public:

	int height (TreeNode* root){
		if (root == NULL)
			return 0;
		int left = height(root->left);
		int right = height(root->right);
		return max(left, right) + 1;
	}

	void getLeftMostValuebyLevel(TreeNode* root, int depth, int* val, bool& assignable){

		if (root == NULL || assignable)
			return;
		if (depth == 1){
			assignable = true;
			*val = root->val;
			return;
		}

		getLeftMostValuebyLevel(root->left, depth-1, val, assignable);
		getLeftMostValuebyLevel(root->right, depth-1, val, assignable);
		
	}

    int findBottomLeftValue(TreeNode* root) {
        if (root == NULL)
            return 0;

		int h = height(root);
		int value = 0;
		bool flag = false;
		
		getLeftMostValuebyLevel(root, h, &value, flag);

		return value;

    }
};