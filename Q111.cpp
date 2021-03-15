// 111. Minimum Depth of Binary Tree (Easy)
#include <iostream>
#include "tree.h"
using namespace std;

int minDepth(TreeNode* root) {
    
    if (root == NULL)
        return 0;
    
    if (root->left != NULL && root->right != NULL){
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return min(left,right)+1;
    }
    
    else {
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return max(left,right)+1;
    }

}