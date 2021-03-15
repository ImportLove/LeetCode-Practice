// 124. Binary Tree Maximum Path Sum (Hard)

#include <iostream>
#include <vector>
#include <algorithm>
#include "tree.h"
using namespace std;

// the root will be non-empty

/*
    Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

    Output: 42 (15-20-7)

*/


/*
	Note: 
		A better solution is given below commented 
*/
class Solution {
public:

	vector<int> ans;

	int maxGroup(TreeNode* root){
		if (root == NULL)
			return 0;

		if (root->left && root->right){
			int left = maxGroup(root->left);
			int right = maxGroup(root->right);
			ans.push_back(left+right+root->val);
			ans.push_back(max(left, right));
			return max(max(left+root->val, right + root->val), root->val);
		}

		else if (root->left){
			int left = maxGroup(root->left);
			ans.push_back(left);
			return max(left + root->val, root->val);
		}
		
		else if (root->right){
			int right = maxGroup(root->right);
			ans.push_back(right);
			return max(right + root->val, root->val);
		}

		ans.push_back(root->val);
		return root->val;
	}

    int maxPathSum(TreeNode* root) {
        int result = maxGroup(root);
		sort(ans.begin(), ans.end());

		return max(result, ans[ans.size()-1]);
    }
};



/*
class Solution {
    int max = INT32_MIN;
    int childPath,r;
public:
    
    int helper(TreeNode* root) {
        if (!root) return 0;
        int l = helper(root->left);
        r = helper(root->right);
        childPath = std::max(l,r);
        if (childPath<0) childPath = 0;
        max = std::max(max,l+r+root->val); 
        max = std::max(max,childPath+root->val);
        return childPath+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        helper(root);
        return max;
    }
};

*/

int main(){
	TreeNode* node = new TreeNode(100);
	TreeNode* root = new TreeNode(-1, node, NULL);
	Solution sol;

	cout << sol.maxPathSum(root) << endl;
	delete node;
	delete root;

	return 0;
}