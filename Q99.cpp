// 99. Recover Binary Search Tree (Hard)

#include <iostream>
#include "tree.h"

/*
    Two elements of a binary search tree (BST) are swapped by mistake.
    Recover the tree without changing its structure.
*/

class Solution {
public:

	void InOrderTra(TreeNode* root, TreeNode*& pre, TreeNode*& post, TreeNode*& prev){
		if (root == NULL)
			return;
		
		InOrderTra(root->left, pre, post, prev);

		if (prev != NULL && prev->val > root->val){
			if (pre == NULL)
				pre = prev;
			post = root;
		}
		prev = root;

		InOrderTra(root->right, pre, post, prev);
	}
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL;
		TreeNode* post = NULL;
		TreeNode* prev = NULL;
		
		InOrderTra(root, pre, post, prev);
		int temp = pre->val;
		pre->val = post->val;
		post->val = temp;
    }
};