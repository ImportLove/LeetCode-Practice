// 173. Binary Search Tree Iterator (Medium)

#include <iostream>
#include <stack>
#include "tree.h"

using namespace std;

class BSTIterator {
public:

	TreeNode* tree = NULL;
    TreeNode* current = NULL;
	stack<TreeNode*> path; // only contains parents (self exclusive)
	int max_val = 0;

    BSTIterator(TreeNode* root) {

		// find the max value in the tree
        current = root;
		while (current && current->right){
			current = current->right;
		}
		if (current != NULL) 
			max_val = current->val;

		current = NULL;
		tree = root;
    }
    
    /** @return the next smallest number */
    int next() {

		if (current == NULL){
			current = tree;
			while (current->left != NULL){
				path.push(current);
				current = current->left;
			}
			return current->val;
		}

		// go right if you have it
        if (current->right != NULL){
			path.push(current);
            current = current->right;
			while (current->left){
				path.push(current);
				current = current->left;
			}
        }

		else {
			TreeNode* tmp;
			while (!path.empty()){
				
				tmp = path.top();
				path.pop();

				if (tmp->left == current){
					current = tmp;
					break;
				}
				current = tmp;
			}
		}
		return current->val;
            
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
		if (!tree)
			return false;
        if (current == NULL || current->val < max_val)
			return true;
		return false;
    }
};